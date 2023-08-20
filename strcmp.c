#include "main.h"

/**
  * _strcmp - compares string
  * @s1: first string
  * @s2: second string
  * description: compares s1 and s2
  * Return: 0(equal) <0(s2 >s1) >0(s1>s2)
*/


int _strcmp(const char *s1, const char *s2)
{
	int i, res;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
		{
			res = s1[i];
			return (res);
		}
		else if (s2[i] > s1[i])
		{
			res = -(s2[i]);
			return (res);
		}
		else
		{
			res = 0;
		}
		i++;
	}
	return (res);
}
