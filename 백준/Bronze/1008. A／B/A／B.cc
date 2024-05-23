#include<stdio.h>
int main(void)
{
	long double a, b;
	scanf("%Lf %Lf", &a, &b);
	printf("%.16Lf", a / b);

}