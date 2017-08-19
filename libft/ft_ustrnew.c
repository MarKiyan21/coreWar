//
// Created by Администратор on 05.08.2017.
//

#include "libft.h"
#include <stdlib.h>

unsigned char	*ft_ustrnew(size_t size)
{
	unsigned char *tmp;
	unsigned char *str;

	if ((tmp = (unsigned char*)malloc(size + 1)) == NULL)
		return (NULL);
	str = tmp;
	while (size--)
	{
		*str = 0;
		str++;
	}
	*str = '\0';
	return (tmp);
}