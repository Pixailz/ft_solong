#include "ft_printf.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	(void) argc;
	int	i = 1234;

	//ft_printf("%x\n", i);
	ft_printf("int i = %d\n", i);
	return (0);
}
