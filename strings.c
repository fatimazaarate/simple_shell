#include "main.h"

/**
 * _strdup - duplicate to new memory space location
 * @str: char
 *
 * Return: 0
 *
 */
char *_strdup(char *str)
{
	char *dup;
	int n, i;

	if (str == NULL)
		return (NULL);

	n = strlen(str);
	dup = (char *) malloc((n + 1) * sizeof(char));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
	{
		dup[i] = str[i];
	}
	return (dup);
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
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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

void reverse_string(char *str, int len)
{
	char tmp;
	int i = 0, nd = len -1;

	while (i < nd)
	{
		tmp = str[i];
		str[i] = str[nd];
		str[nd] = tmp;
		i++;
		nd--;
	}

	
}

int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}
