#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int i = 0;

	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int i = 0;
	int count = 0;

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1] == 's')
		{
			count += ft_putstr(va_arg(ap, char *));
			i += 2;
		}
		else
			count += ft_putchar(format[i++]);
	}
	va_end(ap);
	return (count);
}
