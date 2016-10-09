//ZigZag Conversion
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows)
{	
	int length = strlen(s);
	int i, j, k = 0;
	char* result = (char*)malloc(length+10);

	if (numRows == 1)
		return s;

	for (i = 0; i < numRows; i++)
	{
		for (j = i; j < length;)
		{
			result[k++] = s[j];
			j += 2 * (numRows - 1);
			if (j - 2 * i < length && i != 0 && i != numRows - 1)
			{
				result[k++] = s[j - 2*i];
			}
		}
	}
	result[k]='\0';
	return result;
}

int main(int argc, char* argv[])
{
	printf("%s\n", convert(argv[1],atoi(argv[2])));
	return 0;
}
