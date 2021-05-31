#include <stdio.h>

int main()
{
	printf("| return = %d\n", printf("%c", '\x00'));
	printf("| return = %d\n", printf("%5c", '\x00'));
	printf("| return = %d\n", printf("%5c", 'a'));
	printf("| return = %d", printf("%clalala", '\x00'));
}
