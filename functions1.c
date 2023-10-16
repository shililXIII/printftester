#include "main.h"

/**** PRINT UNSIGNED NUMBER ****/
/**
 * print_unsigned -  this is function used for  Print out   unsigned number
 * @typ:  Display the List  of arguments
 * @bu: used for Calculate Buffer array  handle print
 * @fl:   screen a Calculates activities flag
 * @wi: this is calculated get  width
 * @prec:  this is the display Precision specification
 * @si: Calculate the specifier of size
 * Return: Number of characters printed
 */
int print_unsigned(va_list typ, char bu[],
	int fl, int wi, int prec, int si)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(typ, unsigned long int);

	n = convert_size_unsgnd(n, si);

	if (n == 0)
		bu[i--] = '0';

	bu[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		bu[i--] = (n % 10) + '0';
		n /= 10;
	}

	i++;

	return (write_unsgnd(0, i, bu, fl, wi, prec, si));
}

/*** PRINT UNSIGNED NUMBER IN OCTAL ***/
/**
 * print_octal - this is fun for Prints an unsigned number in octal notation
 * @typ:  Display the List  of arguments
 * @bu: used for Calculate Buffer array  handle print
 * @fl:   screen a Calculates activities flag
 * @wi: this is calculated get  width
 * @prec:  this is the display Precision specification
 * @si: Calculate the specifier of size
 * Return: Number of characters printed.
 */
int print_octal(va_list typ, char bu[],
	int fl, int wi, int prec, int si)
{

	int i = BUFF_SIZE - 2;
	unsigned long int nu = va_arg(typ, unsigned long int);
	unsigned long int init_nu = nu;

	UNUSED(wi);

	nu = convert_size_unsgnd(nu, si);

	if (nu == 0)
		bu[i--] = '0';

	bu[BUFF_SIZE - 1] = '\0';

	while (nu > 0)
	{
		bu[i--] = (nu % 8) + '0';
		nu /= 8;
	}

	if (fl & F_HASH && init_nu != 0)
		bu[i--] = '0';

	i++;

	return (write_unsgnd(0, i, bu, fl, wi, prec, si));
}

/***** PRINT UNSIGNED NUMBER IN HEXADECIMAL ****/
/**
 * print_hexadecimal - cat Print  unsigned number  hexadecimal notation
 * @typ:  Display the List  of arguments
 * @bu: used for Calculate Buffer array  handle print
 * @fl:   screen a Calculates activities flag
 * @wi: this is calculated get  width
 * @prec:  this is the display Precision specification
 * @si: Calculate the specifier of size
 * Return: Number of characters printed.
 */
int print_hexadecimal(va_list typ, char bu[],
	int fl, int wi, int prec, int si)
{
	return (print_hexa(typ, "0123456789abcdef", bu,
		fl, 'x', wi, prec, si));
}

/*** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ***/
/**
 * print_hexa_upper - dsp fun for unsigned number in upper hexadecimal notation
 * @typ:  Display the List  of arguments
 * @bu: used for Calculate Buffer array  handle print
 * @fl:   screen a Calculates activities flag
 * @wi: this is calculated get  width
 * @prec:  this is the display Precision specification
 * @si: Calculate the specifier of size
 * Return: Number of characters printed.
 */
int print_hexa_upper(va_list typ, char bu[],
	int fl, int wi, int prec, int si)
{
	return (print_hexa(typ, "0123456789ABCDEF", bu,
		fl, 'X', wi, prec, si));
}

/*** PRINT HEXX NUM IN LOWER OR UPPER ****/
/**
 * print_hexa - this  fun using aPrint a hexadecimal number lower or upper case
 * @typ: Display the List  of arguments
 * @map_to: Array of value  map the number to
 * @bu: Calculate a Buffer array to handle print
 * @fl:  screen a Calculates activitiesflag
 * @flag_ch: screen a Calculates activities flag
 * @wi: this is calculated get  width
 * @prec: this is the display Precision specification
 * @si: Calculate the specifier of size
 * @si: Calculate the specifier of size
 * Return:  return a Number of characters printed
 */
int print_hexa(va_list typ, char map_to[], char bu[],
	int fl, char flag_ch, int wi, int prec, int si)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(typ, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(wi);

	number = convert_size_unsgnd(number, si);

	if (number == 0)
		bu[i--] = '0';

	bu[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		bu[i--] = map_to[number % 16];
		number /= 16;
	}

	if (fl & F_HASH && init_number != 0)
	{
		bu[i--] = flag_ch;
		bu[i--] = '0';
	}

	i++;
	return (write_unsgnd(0, i, bu, fl, wi, prec, si));
}
