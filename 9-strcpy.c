/**
* _strcpy - copy string pointed to by src
* @src: source string
* @dest: destination string
* description: copies the str pointed to by src
* Return: ptr to dest
*/

char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}
