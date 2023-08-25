#include "main.h"
/**
  *int_to_string- converts an integer to a string
  *@value: the integer to be converted
  *@buffer: used to store the int being processed
  *description: takes int value and converts in to a string
  *Return: the number string
 */
ssize_t int_to_string(int value, char *buffer)
{
	int j, len = 0;
	char temp[12];
	int tempLen = 0;

	if (value == 0)
	{
		buffer[len++] = '0';
	}
	else
	{
		if (value < 0)
		{
			buffer[len++] = '-';
			value = -value;
		}
		/*int tempLen = 0;*/
		while (value > 0)
		{
			temp[tempLen++] = '0' + (value % 10);
			value /= 10;
		}
		for (j = 0; j < tempLen; j++)
		{
			buffer[len++] = temp[tempLen - 1 - j];
		}
	}
	buffer[len] = '\0';
	return (len);
}
