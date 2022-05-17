#include <unistd.h>
#include <stdlib.h>

char	*strip(char *str)
{
	int start;
	int	end;
	int new;
	char *result;


	start = 0;
	end = 0;
	new = 0;
	while (str[end] != 0)
		end++;
	while(str[start] != 0)
	{
		if(str[start] != ' ')
			break;
		start++;
	}
	end--;
	while (str[end] == ' ')
	{
		end--;
	}
	
	result = malloc(sizeof(char) * (end - start + 2));
	while(start <= end)
		result[new++] = str[start++];
	result[new] = 0;
	return(result);
}

char	upper(char *str)
{
	while (*str != 0)
	{
		if ('a' <= *str && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (*str);
}

void	rev_print(char *str)
{
	int i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	i--;
	while (i >=  0)
	{
		write(1, &str[i],1);
		i--;
	}

}

int	main(int argc, char **argv)
{
	char *str = argv[1];
	if (argc == 2)
	{
		str = strip(str);
		upper(str);
		rev_print(str);
	}
	write(1, "\n", 1);
	return 0;

}

/*by Ruby
def convert(input)
	puts (input.strip.upcase.reverse)
end
*/