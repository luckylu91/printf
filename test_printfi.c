#include <stdio.h>
#include <stdlib.h>

int main()
{
	void	*p;

	setbuf(stdout, NULL);

	printf("[%%d]\n%d\n", 1);
	printf("[%%0d]\n%0d\n", 1);
	printf("[%%0.4d]\n%0d\n", 1);
	printf("[%%00d]\n%00d\n", 1);
	printf("[%%00.4d]\n%0d\n", 1);
	printf("[%%000000d]\n%000000d\n", 1);
	printf("[%%.2d] (1)\n%.2d\n", 1);
	printf("[%%.10d] (1)\n%.10d\n", 1);
	printf("[%%.-10d] (1)\n%.-10d\n", 1);
	printf("[%%.d] (0)\n%.d\n", 0);
	printf("[%%.-2d] (0)\n%.-2d\n", 0);
	printf("[%%.-10d] (0)\n%.-10d\n", 0);
	printf("[%%.--+-+10d] (0)\n%.--+-+10d\n", 0);
	printf("[%%.--+-+-10d] (0)\n%.--+-+-10d\n", 0);
	printf("[%%2d] (1)\n%2d\n", 1);
	printf("[%%.2d] (9999)\n%.2d\n", 9999);
	printf("[%%2d] (9999)\n%2d\n", 9999);
	printf("[%%4.2d] (1)\n%4.2d\n", 1);
	printf("[%%04.2d] (1) -> flag 0 ignored (and we don't care)\n%04.2d\n", 1);
	printf("[%%04d] (1)\n%04d\n", 1);
	printf("[%%6.4d] (1)\n%6.4d\n", 1);
	printf("[%%06.4d] (1)\n%06.4d\n", 1);
	printf("[%%6.2d] (1)\n%6.2d\n", 1);
	printf("[%%06.2d] (1)\n%06.2d\n", 1);
	printf("[%%06.4d] (1)\n%06.4d\n", -1);

	printf("\n\t----------\nNo Precision after '.'\n\n");

	printf("[%%.d] (1)\n%.d\n", 1);

	printf("\n\t----------\n\n");

	printf("[%%x] (1)\n%x\n", 1);
	printf("[%%0x] (1)\n%0x\n", 1);
	printf("[%%0.4x] (1)\n%0x\n", 1);
	printf("[%%00x] (1)\n%00x\n", 1);
	printf("[%%00.4x] (1)\n%0x\n", 1);
	printf("[%%000000x] (1)\n%000000x\n", 1);
	printf("[%%.2x] (12)\n%.2x\n", 12);
	printf("[%%2x] (-41)\n%2x\n", -41);
	printf("[%%.2x] (9999)\n%.2x\n", 9999);
	printf("[%%2x] (9999)\n%2x\n", 9999);
	printf("[%%4.2d] (1)\n%4.2d\n", 1);
	printf("[%%04.2d] (1) -> flag 0 ignored (and we don't care)\n%04.2d\n", 1);
	printf("[%%04x] (1)\n%04x\n", 1);
	printf("[%%6.4d] (1)\n%6.4d\n", 1);
	printf("[%%06.4d] (1)\n%06.4d\n", 1);
	printf("[%%6.2d] (1)\n%6.2d\n", 1);
	printf("[%%06.2d] (1)\n%06.2d\n", 1);
	printf("[%%06.4d] (1)\n%06.4d\n", -1);

	printf("\n\t----------\n\n");

	printf("[%%p]%p (uninitialized)\n", p);
	printf("[%%p]%p (NULL)\n", NULL);
	if (!(p = malloc(1)))
		printf("error malloc failed\n");
	else
		printf("[%%p]%p (after malloc)\n", p);

	printf("\n\t----------\n\n");

	printf("Parse error [%%k]:\n");
	printf("%k\n");
	printf("Not enough args [%%d] (void):\n");
	printf("%d\n");
	printf("Too many args [%%d] (1, 1):\n");
	printf("%d\n", 1, 1);
	printf("Non standard [%%0p] (p):\n");
	printf("%0p\n", p);
	printf("Non standard [%%.2p] (p):\n");
	printf("%.2p\n", p);
	printf("Non standard [%%#p] (p):\n");
	printf("%#p\n", p);
	printf("Non standard (\"Nonsensical\") [%%Ld] (786):\n");
	printf("%Ld\n", 786L);
	
	printf("\n\t----------\n\n");

	printf("[%%+d] (0)\n%+d\n", 0);
	printf("[%%+d] (10)\n%+d\n", 10);
	printf("[%%+d] (-10)\n%+d\n", -10);
	
	printf("\n\t----------\n\n");

	printf("%0*.*i\n", 2, -2, 8);

}
