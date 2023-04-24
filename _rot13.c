#include "main.h"

int print_rot13(va_list l)
{
	char upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int i, ctr = 0;

	char *str = va_arg(l, char*);
	while(*str != '\0')
	{
		if(*str >= 'A' && *str <= 'Z')
		{
			for(i = 0; i < 26; i++)
			{
				if(upper[i] == *str)
					break;	
			}
			i += 13;
			if(i >= 26)
				i = i % 26;
			write(1, &upper[i], 1);
		}else if(*str >= 'a' && *str <= 'z')
		{
			for(i = 0; i < 26; i++)
			{
				if(lower[i] == *str)
					break;
			}
			i += 13;
			if(i >= 26)
				i = i % 26;
			write(1, &lower[i], 1);
		}else{
			write(1, str, 1);
		}
		ctr++;
		str++;
	}
	return (ctr);
}