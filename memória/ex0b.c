#include <stdio.h>

int main(void){
    int x = 123;
	printf("%p\n", &x);
	int *p = &x;
	p = p + 10000;
	printf("%p\n", p);
	*p = 10;
	printf("%p\n", *p);
    return 0;
}