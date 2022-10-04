#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen((char *)s1);
	dup = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!dup)
	{
		return (NULL);
	}
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
