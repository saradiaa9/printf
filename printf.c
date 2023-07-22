#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Prints formatted output to stdout
 *
 * @format: The format string used to produce the output
 * @...: The variable argument list containing the values to be printed
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
int c = va_arg(args, int);
_putchar(c);
count++;
break;
}
case 's':
{
char *s = va_arg(args, char *);
while (*s != '\0')
{
_putchar(*s);
s++;
count++;
}
break;
}
case 'd':
case 'i':
{
int n = va_arg(args, int);
unsigned int m;
unsigned int divisor = 1;
if (n < 0)
{
_putchar('-');
count++;
m = -n;
}
else
{
m = n;
}
while (m / divisor > 9)
{
divisor *= 10;
}
do
{
_putchar(m / divisor + '0');
count++;
m %= divisor;
divisor /= 10;
}
while (divisor > 0);
break;
}
case 'u':
{
unsigned int n = va_arg(args, unsigned int);
unsigned int m = n;
unsigned int divisor = 1;
while (m / divisor > 9)
{
divisor *= 10;
}
do
{
_putchar(m / divisor + '0');
count++;
m %= divisor;
divisor /= 10;
}
while (divisor > 0);
break;
}
case 'x':
{
unsigned int n = va_arg(args, unsigned int);
unsigned int m = n;
char buffer[20];
int i = 0;
                    
do
{
int digit = m % 16;
if (digit < 10)
{
buffer[i++] = digit + '0';
}
else
{
buffer[i++] = digit - 10 + 'a';
}
m /= 16;
}
while (m != 0);
                    
while (i > 0)
{
_putchar(buffer[--i]);
count++;
}
break;
}
case 'X':
{
unsigned int n = va_arg(args, unsigned int);
unsigned int m = n;
char buffer[20];
int i = 0; 
do
{
int digit = m % 16;
if (digit < 10)
{
buffer[i++] = digit + '0';
}
else
{
buffer[i++] = digit - 10 + 'A';
}
m /= 16;
}
while (m != 0);
                 
while (i > 0) {
_putchar(buffer[--i]);
count++;
}
break;
}
case 'p':
{
void *p = va_arg(args, void *);
unsigned long n = (unsigned long)p;
char buffer[20];
int i = 0;
do
{
int digit = n % 16;
if (digit < 10)
{
buffer[i++] = digit + '0';
}
else
{
buffer[i++] = digit - 10 + 'a';
}
n /= 16;
}
while (n != 0);
_putchar('0');
_putchar('x');
count += 2;
while (i > 0) {
_putchar(buffer[--i]);
count++;
}
break;
}
case 'o':
{
unsigned int n = va_arg(args, unsigned int);
char buffer[20];
unsigned int m = n;
int i = 0;
do
{
int digit = m % 8;
buffer[i++] = digit + '0';
m /= 8;
}
while (m != 0);
while (i > 0)
{
_putchar(buffer[--i]);
count++;
}
break;
}
case '%':
{
_putchar('%');
count++;
break;
}
default:
{
_putchar('%');
_putchar(*format);
count += 2;
break;
}
}
}
else
{
_putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}

