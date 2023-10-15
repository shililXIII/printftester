#include "main.h"

/**
 * ha_print - prints args based on its type
 * @fmt: Formatted str in which to print the args.
 * @list: List of args to print.
 * @ind: ind.
 * @buffer: Buff arr handle print.
 * @flags: Calc active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */

int ha_print(const char *fmt)
{{
	int i, unknow_len = 0, printed_chars = -1;

	fmt_t fmt_types[] = {
		/**but func protype names**/
	{'\0', NULL}
	};
	
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
        if (fmt[*ind] == fmt_types[i].fmt)

		return (fmt_types[i].fn( flags, width /**and another printed**/));
		
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
