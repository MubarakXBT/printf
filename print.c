/* Required Headers */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 *_printf - Prototype for Printf function
 *@fmt: The argument to be printed
 *Description: This program Will provide a minimal function of printf
 *
 * Return: The program should return The numbers of characters printed
 */
void _printf(const char *fmt, ...)
{
	/* Declaration of variables*/
	int dval, ival;
	int count = 0;
	char *cval, *sval;
	const char *init;
	double fval;

	/* Declare pointer for argument list */
	va_list ptr;

	/* Initiaise argument to the list pointer*/
	va_start(ptr, fmt);

	for(init = fmt; *init != '\0'; init++)
	{
		if (*init  != '%')
		{
			putchar(*init);
			continue;
		}
		init++;
		switch(*init)
		{
			case 'i':
				ival = va_arg(ptr, int);
				printf("%i", ival);
				break;
			case 'd':
				dval = va_arg(ptr, int);
				printf("%d", dval);
				break;
			case 'f':
				fval = va_arg(ptr, double);
				printf("%f", fval);
				break;
			case 'c':
				cval = va_arg(ptr, char*);
				printf("%s", cval);
			case 's':
				sval = va_arg(ptr, char*);
				printf("%s", sval);
				break;
			default:
				putchar(*init);
				break;
		}
	}
	va_end(ptr);
}

int main(void)
{
	int i = 10;
	char *c = "SHELL";

	_printf("This is %d\n%c", i, c);
	return (0);
}
