#include "main.h"



/**
* free_cmd - a function to free the memory
* @cmd: the memory to be freed
*/
void free_cmd(char **cmd)
{
	int j;

	if (cmd == NULL)
		return;

	for (j = 0; cmd[j]; j++)
	{
		free(cmd[j]);
		cmd[j] = NULL;
	}

	free(cmd), cmd = NULL;
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

char *_itoa(int n)
{
	char buffer [20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);
	return(_strdup(buffer));
}

