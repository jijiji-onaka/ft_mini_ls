#include <stdio.h>
#include <stdlib.h>
#include "includes/ft_mini_ls_bonus.h"
#include <string.h>

#include <stdio.h>
#include <errno.h>

#define DEBUGV(v_fmt, v) \
    printf(#v ": " v_fmt "\t(file \"%s\", line %d, in %s)\n", \
        v, __FILE__, __LINE__, __FUNCTION__);

#define DEBUGVD(v) DEBUGV("%d", v);
#define DEBUGVS(v) DEBUGV("%s", v);

#define DEBUGF(fmt, ...) \
    printf(fmt "\t(file \"%s\", line %d, in %s)\n", \
        __VA_ARGS__, __FILE__, __LINE__, __FUNCTION__);

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
DIR				*dir;
	char			**current_dir_file;
	int				alloc_size;
	size_t			hidden_file_num;
	int				return_value;

	errno = 0;
	if ((dir = opendir(av[1])) == NULL)
	{
		printf("%s\n", strerror(errno));
		return (1);
	}
		printf("%s\n", strerror(errno));
		printf("%d\n", errno);
}
