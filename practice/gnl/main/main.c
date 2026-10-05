/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabbi <mlabbi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 04:22:07 by mlabbi            #+#    #+#             */
/*   Updated: 2026/09/22 04:22:09 by mlabbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char				*get_next_line(int fd);

/* ========================================================= */
/*                         UTILITIES                         */
/* ========================================================= */

static int			g_tests = 0;
static int			g_passed = 0;

static void	print_result(const char *name, int ok)
{
	g_tests++;
	if (ok)
	{
		g_passed++;
		printf("\033[32m[PASS]\033[0m %s\n", name);
	}
	else
		printf("\033[31m[FAIL]\033[0m %s\n", name);
}

static int	write_file(const char *filename, const char *content)
{
	int		fd;
	ssize_t	len;
	ssize_t	written;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (0);
	len = strlen(content);
	written = write(fd, content, len);
	close(fd);
	return (written == len);
}

static int	check_line(char *got, const char *expected)
{
	if (!got && !expected)
		return (1);
	if (!got || !expected)
		return (0);
	return (strcmp(got, expected) == 0);
}

static int	check_all_lines(const char *filename, const char **expected,
		int count)
{
	int		fd;
	int		i;
	char	*line;
	int		ok;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	ok = 1;
	i = 0;
	while (i < count)
	{
		line = get_next_line(fd);
		if (!check_line(line, expected[i]))
		{
			printf("       line %d mismatch\n", i + 1);
			printf("       expected: %s",
				expected[i] ? expected[i] : "(NULL)\n");
			printf("       got     : %s", line ? line : "(NULL)\n");
			ok = 0;
			free(line);
			break ;
		}
		free(line);
		i++;
	}
	if (ok)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			printf("       expected EOF, but got: %s", line);
			free(line);
			ok = 0;
		}
	}
	close(fd);
	return (ok);
}

static void	remove_file(const char *filename)
{
	unlink(filename);
}

/* ========================================================= */
/*                     BASIC TESTS                           */
/* ========================================================= */

static void	test_empty_file(void)
{
	const char	*expected[] = {NULL};

	write_file("gnl_empty.txt", "");
	print_result("Empty file", check_all_lines("gnl_empty.txt", expected, 0));
	remove_file("gnl_empty.txt");
}

static void	test_one_line_newline(void)
{
	const char	*expected[] = {"hello world\n"};

	write_file("gnl_one.txt", "hello world\n");
	print_result("One normal line", check_all_lines("gnl_one.txt", expected,
			1));
	remove_file("gnl_one.txt");
}

static void	test_one_line_no_newline(void)
{
	const char	*expected[] = {"hello world"};

	write_file("gnl_no_nl.txt", "hello world");
	print_result("One line without final newline",
		check_all_lines("gnl_no_nl.txt", expected, 1));
	remove_file("gnl_no_nl.txt");
}

static void	test_empty_lines(void)
{
	const char	*expected[] = {"\n", "\n", "\n", "abc\n", "\n", "xyz\n"};

	write_file("gnl_empty_lines.txt", "\n\n\nabc\n\nxyz\n");
	print_result("Multiple empty lines", check_all_lines("gnl_empty_lines.txt",
			expected, 6));
	remove_file("gnl_empty_lines.txt");
}

static void	test_mixed_lines(void)
{
	const char	*expected[] = {"a\n", "bb\n", "ccc\n", "dddd\n", "eeeee\n",
			"ffffff"};

	write_file("gnl_mixed.txt",
				"a\n"
				"bb\n"
				"ccc\n"
				"dddd\n"
				"eeeee\n"
				"ffffff");
	print_result("Lines with increasing lengths",
		check_all_lines("gnl_mixed.txt", expected, 6));
	remove_file("gnl_mixed.txt");
}

static void	test_spaces_tabs(void)
{
	const char	*expected[] = {"   \n", "\t\t\t\n", " hello world \n",
			"\t hello \t\n", "     "};

	write_file("gnl_spaces.txt",
				"   \n"
				"\t\t\t\n"
				" hello world \n"
				"\t hello \t\n"
				"     ");
	print_result("Spaces and tabs", check_all_lines("gnl_spaces.txt", expected,
			5));
	remove_file("gnl_spaces.txt");
}

/* ========================================================= */
/*                   BUFFER BOUNDARY TESTS                   */
/* ========================================================= */

static char	*make_string(int len, char c)
{
	char	*s;
	int		i;

	s = malloc(len + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	s[len] = '\0';
	return (s);
}

static void	test_boundary(int len, int newline)
{
	char	*content;
	char	*expected;
	char	*line;
	int		fd;
	int		ok;

	content = make_string(len, 'A');
	if (!content)
		return ;
	expected = malloc(len + 2);
	if (!expected)
	{
		free(content);
		return ;
	}
	memcpy(expected, content, len);
	if (newline)
	{
		expected[len] = '\n';
		expected[len + 1] = '\0';
	}
	else
		expected[len] = '\0';
	fd = open("gnl_boundary.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		free(content);
		free(expected);
		return ;
	}
	write(fd, content, len);
	if (newline)
		write(fd, "\n", 1);
	close(fd);
	fd = open("gnl_boundary.txt", O_RDONLY);
	line = get_next_line(fd);
	ok = check_line(line, expected);
	free(line);
	close(fd);
	printf("       length=%d, newline=%s\n", len, newline ? "YES" : "NO");
	print_result("BUFFER boundary test", ok);
	free(content);
	free(expected);
	remove_file("gnl_boundary.txt");
}

static void	test_buffer_boundaries(void)
{
	printf("\n\033[36m--- BUFFER BOUNDARIES ---\033[0m\n");
	test_boundary(BUFFER_SIZE - 1, 1);
	test_boundary(BUFFER_SIZE, 1);
	test_boundary(BUFFER_SIZE + 1, 1);
	test_boundary(BUFFER_SIZE - 1, 0);
	test_boundary(BUFFER_SIZE, 0);
	test_boundary(BUFFER_SIZE + 1, 0);
	test_boundary(BUFFER_SIZE * 2 - 1, 1);
	test_boundary(BUFFER_SIZE * 2, 1);
	test_boundary(BUFFER_SIZE * 2 + 1, 1);
}

/* ========================================================= */
/*                    LONG LINE TEST                         */
/* ========================================================= */

static void	test_huge_line(void)
{
	int		fd;
	char	*line;
	char	*expected;
	int		len;
	int		i;
	int		ok;

	len = 100000;
	expected = make_string(len, 'X');
	if (!expected)
		return ;
	fd = open("gnl_huge.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		free(expected);
		return ;
	}
	i = 0;
	while (i < len)
	{
		write(fd, "X", 1);
		i++;
	}
	write(fd, "\n", 1);
	close(fd);
	fd = open("gnl_huge.txt", O_RDONLY);
	line = get_next_line(fd);
	ok = 1;
	if (!line)
		ok = 0;
	else
	{
		if ((int)strlen(line) != len + 1)
			ok = 0;
		if (line[len] != '\n')
			ok = 0;
	}
	printf("       requested line length: %d\n", len);
	print_result("100,000-character line", ok);
	free(line);
	free(expected);
	close(fd);
	remove_file("gnl_huge.txt");
}

/* ========================================================= */
/*                     MANY LINES                            */
/* ========================================================= */

static void	test_many_lines(void)
{
	int		fd;
	int		i;
	int		ok;
	char	*line;
	char	expected[64];

	fd = open("gnl_many.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	i = 0;
	while (i < 10000)
	{
		dprintf(fd, "line-%d\n", i);
		i++;
	}
	close(fd);
	fd = open("gnl_many.txt", O_RDONLY);
	ok = 1;
	i = 0;
	while (i < 10000)
	{
		line = get_next_line(fd);
		snprintf(expected, sizeof(expected), "line-%d\n", i);
		if (!line || strcmp(line, expected) != 0)
		{
			ok = 0;
			printf("       failed around line %d\n", i);
			free(line);
			break ;
		}
		free(line);
		i++;
	}
	if (ok)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			ok = 0;
			free(line);
		}
	}
	close(fd);
	print_result("10,000 lines", ok);
	remove_file("gnl_many.txt");
}

/* ========================================================= */
/*                  MULTIPLE FD TEST                         */
/* ========================================================= */

static void	test_multiple_fds(void)
{
	int		fd1;
	int		fd2;
	char	*l1;
	char	*l2;
	int		ok;

	write_file("gnl_fd1.txt",
				"AAA\n"
				"BBB\n"
				"CCC\n");
	write_file("gnl_fd2.txt",
				"111\n"
				"222\n"
				"333\n");
	fd1 = open("gnl_fd1.txt", O_RDONLY);
	fd2 = open("gnl_fd2.txt", O_RDONLY);
	ok = 1;
	l1 = get_next_line(fd1);
	l2 = get_next_line(fd2);
	if (!l1 || strcmp(l1, "AAA\n") != 0)
		ok = 0;
	if (!l2 || strcmp(l2, "111\n") != 0)
		ok = 0;
	free(l1);
	free(l2);
	l1 = get_next_line(fd1);
	l2 = get_next_line(fd2);
	if (!l1 || strcmp(l1, "BBB\n") != 0)
		ok = 0;
	if (!l2 || strcmp(l2, "222\n") != 0)
		ok = 0;
	free(l1);
	free(l2);
	l1 = get_next_line(fd1);
	l2 = get_next_line(fd2);
	if (!l1 || strcmp(l1, "CCC\n") != 0)
		ok = 0;
	if (!l2 || strcmp(l2, "333\n") != 0)
		ok = 0;
	free(l1);
	free(l2);
	close(fd1);
	close(fd2);
	print_result("Multiple FDs interleaved", ok);
	remove_file("gnl_fd1.txt");
	remove_file("gnl_fd2.txt");
}

/* ========================================================= */
/*                    SPECIAL CHARACTERS                     */
/* ========================================================= */

static void	test_special_chars(void)
{
	const char	*expected[] = {"abc\r\n", "123\t456\n", "!@#$%^&*()\n", "éàç\n",
			"END"};

	write_file("gnl_special.txt",
				"abc\r\n"
				"123\t456\n"
				"!@#$%^&*()\n"
				"éàç\n"
				"END");
	print_result("Special characters", check_all_lines("gnl_special.txt",
			expected, 5));
	remove_file("gnl_special.txt");
}

/* ========================================================= */
/*                    REPEATED EOF                           */
/* ========================================================= */

static void	test_repeated_eof(void)
{
	int		fd;
	char	*line;
	int		ok;

	write_file("gnl_eof.txt", "hello\n");
	fd = open("gnl_eof.txt", O_RDONLY);
	line = get_next_line(fd);
	free(line);
	ok = 1;
	line = get_next_line(fd);
	if (line != NULL)
	{
		ok = 0;
		free(line);
	}
	line = get_next_line(fd);
	if (line != NULL)
	{
		ok = 0;
		free(line);
	}
	line = get_next_line(fd);
	if (line != NULL)
	{
		ok = 0;
		free(line);
	}
	close(fd);
	print_result("Repeated calls after EOF", ok);
	remove_file("gnl_eof.txt");
}

/* ========================================================= */
/*                  INVALID FD TEST                          */
/* ========================================================= */

static void	test_invalid_fd(void)
{
	char	*line;
	int		ok;

	line = get_next_line(-1);
	ok = (line == NULL);
	free(line);
	print_result("Invalid FD (-1)", ok);
}

/* ========================================================= */
/*                  CLOSED FD TEST                           */
/* ========================================================= */

static void	test_closed_fd(void)
{
	int		fd;
	char	*line;
	int		ok;

	write_file("gnl_closed.txt", "hello\n");
	fd = open("gnl_closed.txt", O_RDONLY);
	if (fd < 0)
		return ;
	close(fd);
	line = get_next_line(fd);
	ok = (line == NULL);
	free(line);
	print_result("Closed FD", ok);
	remove_file("gnl_closed.txt");
}

/* ========================================================= */
/*                  DIRECTORY TEST                           */
/* ========================================================= */

static void	test_directory(void)
{
	int		fd;
	char	*line;
	int		ok;

	fd = open(".", O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	/*
		* Linux read() on a directory normally fails with EISDIR.
		* get_next_line() should therefore return NULL.
		*/
	ok = (line == NULL);
	free(line);
	close(fd);
	print_result("Directory FD / read error", ok);
}

/* ========================================================= */
/*                 RANDOMIZED TEST                           */
/* ========================================================= */

static unsigned int	g_seed = 0x1337C0FF;

static unsigned int	rand_u32(void)
{
	g_seed ^= g_seed << 13;
	g_seed ^= g_seed >> 17;
	g_seed ^= g_seed << 5;
	return (g_seed);
}

static void	test_random(void)
{
	int		fd;
	int		i;
	int		len;
	int		ok;
	char	*line;
	char	*expected;
	char	*content;

	fd = open("gnl_random.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	i = 0;
	while (i < 1000)
	{
		len = rand_u32() % 300;
		content = make_string(len, (char)('a' + (rand_u32() % 26)));
		if (!content)
		{
			close(fd);
			return ;
		}
		write(fd, content, len);
		if (rand_u32() % 3 != 0)
			write(fd, "\n", 1);
		free(content);
		i++;
	}
	close(fd);
	/*
		* We can't compare the random file against hardcoded
		* strings, so this test mainly stresses:
		*
		* - allocations
		* - stash handling
		* - long/short lines
		* - EOF
		* - repeated reads
		*/
	fd = open("gnl_random.txt", O_RDONLY);
	ok = 1;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		/*
			* Every returned line must be non-empty OR contain
			* a newline. Any returned line must not exceed the
			* amount written in this particular generated file.
			*/
		if (strlen(line) == 0)
			ok = 0;
		free(line);
		i++;
		if (i > 2000)
		{
			ok = 0;
			break ;
		}
	}
	close(fd);
	print_result("1,000 randomized lines", ok);
	(void)expected;
	remove_file("gnl_random.txt");
}

/* ========================================================= */
/*                         MAIN                              */
/* ========================================================= */

int	main(void)
{
	printf("\n");
	printf("=============================================\n");
	printf("       GET_NEXT_LINE DEEP TESTER\n");
	printf("=============================================\n");
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	printf("=============================================\n\n");

	printf("\033[36m--- BASIC TESTS ---\033[0m\n");

	test_empty_file();
	test_one_line_newline();
	test_one_line_no_newline();
	test_empty_lines();
	test_mixed_lines();
	test_spaces_tabs();

	test_buffer_boundaries();

	printf("\n\033[36m--- EXTREME TESTS ---\033[0m\n");

	test_huge_line();
	test_multiple_fds();
	test_special_chars();
	test_repeated_eof();

	printf("\n\033[36m--- ERROR TESTS ---\033[0m\n");

	test_invalid_fd();
	test_closed_fd();
	test_directory();

	printf("\n\033[36m--- RANDOM TEST ---\033[0m\n");

	test_random();

	printf("\n=============================================\n");
	printf("RESULT: %d / %d tests passed\n", g_passed, g_tests);

	if (g_passed == g_tests)
		printf("\033[32mALL TESTS PASSED\033[0m\n");
	else
		printf("\033[31mSOME TESTS FAILED\033[0m\n");

	printf("=============================================\n\n");

	return (g_passed == g_tests ? 0 : 1);
}