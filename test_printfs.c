#include <stdio.h>

int main()
{
	printf("[%%c] ->%c<-\n", 'c');
	printf("[%%2c] ->%2c<-\n", 'c');
	printf("[%%.2c] ->%.2c<-\n", 'c');
	printf("[%%4.2c] ->%4.2c<-\n", 'c');
	printf("%d\n", printf("[%%.s] (42) ->%.s<-\n", 42));
	printf("[%%s] ->%s<-\n", "hess");
	printf("[%%2s] ->%2s<-\n", "hess");
	printf("[%%.2s] ->%.2s<-\n", "hess");
	printf("[%%8s] ->%8s<-\n", "hess");
	printf("[%%08s] ->%08s<-\n", "hess");
}
