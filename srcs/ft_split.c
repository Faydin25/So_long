#include "../so_long.h"

static int	wordcount(const char *s, char c)
{
	int	count;

	count = 0;
	while (s && *s)
	{
		while (*s == c)
			s++;
		count += *s != 0;
		s = ft_strchr(s, c);
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**result;
	int		i;
	size_t	len;

	words = wordcount(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = ft_strchr(s, c) - s;
		result[i] = ft_substr(s, 0, len);
		s += len;
		if (!result[i++])
			return (0);
	}
	result[i] = 0;
	return (result);
}
