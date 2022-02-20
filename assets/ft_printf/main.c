#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{

    char *ptr = NULL;
    printf("%d", printf(" %c %s %p %d %i %u %x %X\n", 'H', "hello", ptr, 255, 255, 255, 255, 255));
    printf("%d", ft_printf(" %c %s %p %d %i %u %x %X\n", 'H', "hello", ptr, 255, 255, 255, 255, 255));
}
