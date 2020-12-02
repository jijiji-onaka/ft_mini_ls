#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	f(int i)
{
	if (i == 2)
		return 0;
	char *s = strdup("1");
	f(i + 1);
	free(s);
	return 0;
}

int main(int ac, char **av)
{
	f(0);
	while (1);
}
