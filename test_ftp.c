#include "ft_printf.h"
#include <stdio.h>

int main()
{
	ft_printf("%%\n", 1);
	ft_printf("%d\n", 1);
	ft_printf("%hhd\n", 1);
	ft_printf("%hd\n", 1);
	ft_printf("%ld\n", 1);
	ft_printf("%lld\n", 1);
	ft_printf("%d\n", 100);
	ft_printf("%d\n", -100);
	ft_printf("%0.5d\n", 1);
	ft_printf("%0.5d\n", -1);
	ft_printf("Lalala %d lalala %d\n", 100, -12);
	ft_printf("1.000.000.000.000 = %d\n", 1000000000000);
	ft_printf("1.000.000.000.000 = %lld\n", 1000000000000ll);
	ft_printf("    5->%5d<-\n", 1);
	ft_printf("   -5->%-5d<-\n", 1);
	ft_printf(" 05.2->%05.2d<-\n", 1);
	ft_printf("-05.2->%-05.2d<-\n", 1);
	ft_printf("    5->%5d<-\n", -1);
	ft_printf("   -5->%-5d<-\n", -1);
	ft_printf(" 05.3->%05.3d<-\n", -1);
	ft_printf("-05.3->%-05.3d<-\n", -1);
	ft_printf("%x\n", 1);
	ft_printf("%x\n", 95);
	ft_printf("%X\n", 1);
	ft_printf("%X\n", 95);
	ft_printf("%u\n", 1);
	ft_printf("%hhu\n", -1);
	ft_printf("%hu\n", -1);
	ft_printf("%u\n", -1);
	ft_printf("%lu\n", -1);
	ft_printf("%llu\n", -1);
	ft_printf("%c\n", 'c');
	ft_printf("%s\n", "string de ta mere");

	int rp, rm;
	printf("printf %%x (-1)\n");
	rp = printf("%x\n", -1);
	printf("return=%d\n", rp);
	printf("ft_printf (-1)\n");
	rm = ft_printf("%x\n", -1);
	printf("return=%d\n", rm);
}
