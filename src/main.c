#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_printf(char *restrict format, ...) {
  va_list arg;
  char *iter;
  int len = 0;
  int argument;
  va_start(arg, format);
  for (iter = format; *iter != '\0'; iter++) {
    if (*iter != '%') {
      putchar(*iter);
      len++;
    }
    if (*iter == '%') {
      iter++;
      switch (*iter) {
      case 'c':
        argument = va_arg(arg, int);
        putchar(argument);
        len++;
        break;
      }
    }
  }

  va_end(arg);
  return len;
}

int main() {
  int a = 0;
  char c = 't';
  my_printf("this is the value of char: %c\n", c);
  // my_printf("hello world");
  return a;
}