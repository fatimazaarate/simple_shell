#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string
 * or NULL if insufficient memory was available
*/

char *_strdup(char *str)
{
	char *strdp;
	unsigned int i, j;

	if (str == 0)
	return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{}
	strdp = (char *) malloc(sizeof(char) * (i + 1));

	if (strdp == 0)
	return (NULL);

	for (j = 0; j <= i; j++)
	strdp[j] = str[j];

	return (strdp);

}

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int _strlen(const char *s)
{
	int len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
*_strcpy - Copies the string pointed to by src to the buffer pointed to by dest
*@dest: The buffer where the string is copied
*@src: The source string to be copied
*Return: A pointer to the destination string dest
**/

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

char *_strcat(char *dest, const char *src)
{
	char *p = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (p);
}