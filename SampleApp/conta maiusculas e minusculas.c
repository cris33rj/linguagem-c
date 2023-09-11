// C++ program to count the uppercase,
// lowercase, special characters
// and numeric values
#include<stdio.h>
#include<string.h>


// Function to count uppercase, lowercase,
// special characters and numbers
void Count(char *str)
{
	int upper = 0, lower = 0, number = 0, special = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			upper++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			lower++;
		else if (str[i]>= '0' && str[i]<= '9')
			number++;
		else
			special++;
	}
	printf("Upper case letters: %d:\n ",  upper);
	printf("Lower case letters %d:\n ", lower);
	printf("Number %d:\n ", number);
	printf("Special characters %d: ", special);
}

// Driver function
int main()
{
	char str[] = "#GeeKs01fOrgEEks07@";
	Count(str);
	return 0;
}
