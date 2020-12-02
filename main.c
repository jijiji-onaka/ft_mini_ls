#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	printf("\x1b[35m%zu\n", strlen("\x1b[34m"));
	printf("\x1b[35m%zu\n", strlen("\033[0m"));
	printf("\x1b[35m%zu\n", strlen("\033[34m"));
	char *s = strdup("a");
	s = strdup("a");
	while (1)
		;
}
