#include <stdio.h>
#include <stdint.h>

int main()
{
	printf("%zu\n", sizeof(long double));
	printf("%zu\n", sizeof(int));
	printf("%zu\n\n", sizeof(uint64_t));
	printf("%f\n", 1.);
	printf("%f\n", 1.23456);
	printf("%f\n", 1.2345678);
}
