#include "shell.h"

/**
 * put_numb_helper - function that helps
 * _put_number to print given number
 *
 * @fd: file descriptor
 * @num: number to be printed
 * Return: (void)
 */
void put_numb_helper(int fd, int num)
{
	char c;

	if (!num)
		return;
	put_numb_helper(fd, num / 10);
	c = num % 10 + 48;
	write(fd, &c, 1);
}

/**
 * put_number - function that will print
 * number to fd
 *
 * @fd: file descriptor
 * @numb: number to be printed
 * Return: (void)
 */
void put_number(int fd, int numb)
{
	char c;

	if (numb == 0)
	{
		c = numb + '0';
		write(fd, &c, 1);
	}
	if (numb < 0)
	{
		write(fd, "-", 1);
		numb *= -1;
	}
	put_numb_helper(fd, numb);
}

/**
 * x_puts - function that print given string
 * into given file descriptor
 * @fd: file descriptor
 * @str: string
 * Return: (void)
 */
void x_puts(int fd, char *str)
{
	write(fd, str, x_strlen(str));
}

/**
 * x_format_printf - function that will print given
 * string and parameters following
 * the given format and specifiers
 *
 * @fd: file descriptor
 * @format: format to follow
 * Return: (void)
 */
void x_format_printf(int fd, const char *format, ...)
{
	int iter;
	int percent;
	va_list ap;

	iter = 0;
	percent = 0;
	va_start(ap, format);
	while (format[iter])
	{
		if (format[iter] == '%')
			percent = 1;
		else if (percent)
		{
			if (format[iter] == 'd')
				put_number(fd, va_arg(ap, int));
			else if (format[iter] == 's')
				x_puts(fd, va_arg(ap, char *));
			else
			{
				write(fd, &format[iter], 1);
			}
			percent = 0;
		}
		else
			write(fd, &format[iter], 1);

		iter++;
	}
	va_end(ap);
}

