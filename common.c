#include "common.h"

/* Common implementations:
 * `printf` function;
 */

void putchar(char ch);
/* putchar must only be declared here,
 * implemented in kernel.c. */
#include "common.h"

void putchar(char ch);
/* Declare the putchar function implemented in kernel.c */

void printf(const char *fmt, ...) {
    va_list vargs;
    va_start(vargs, fmt);

    while (*fmt) {
        if (*fmt == '%') {
            fmt++; // Skip the '%'
            switch (*fmt) { // Read next character
                case '\0':
                /* 
                NULL terminator after the '%' means that '%'
                is the last element of the string. 
                */
                    putchar('%');
                    goto end;
                case '%': // Print '%'
                    putchar('%');
                    break;
                case 's': { // Print string.
                    const char *s = va_arg(vargs, const char *);
                    while (*s) {
                        putchar(*s);
                        s++;
                    }
                    break;
                }
                case 'd': { // Print integer in decimal.
                    int value = va_arg(vargs, int);
                    unsigned magnitude = value; 
                    if (value < 0) {
                        putchar('-');
                        magnitude = -magnitude;
                    }

                    unsigned divisor = 1;
                    while (magnitude / divisor > 9)
                        divisor *= 10;

                    while (divisor > 0) {
                        putchar('0' + magnitude / divisor);
                        magnitude %= divisor;
                        divisor /= 10;
                    }

                    break;
                }
                case 'x': { // Print integer in hexadecimal.
                    unsigned value = va_arg(vargs, unsigned);
                    for (int i = 7; i >= 0; i--) {
                        unsigned nibble = (value >> (i * 4)) & 0xf;
                    /* nibble~half Byte=4 bits */
                        putchar("0123456789abcdef"[nibble]);
                    }
                }
            }
        } else {
            putchar(*fmt);
        }

        fmt++;
    }

end:
    va_end(vargs);
}
