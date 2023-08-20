/**
* _strcat - concat two strings
* @dest: destination str
* @src: source string
* description: copies src int dest
* Return: dest
*/



char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	if (*dest == '\0')
	{
		while (*src != '\0')
		{
			*dest = *src;
			dest++;
			src++;
		}
	}
	*dest = '\0';
	dest = ptr;
	return (dest);
}
