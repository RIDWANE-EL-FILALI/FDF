#include "fdf.h"

void	msg_error(char *err)
{
	perror(err);
	exit(1);
}