#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int i, c = 0, arr[100000];
	double pr = 0;
	int x1, y1, r1, x2, y2, r2;
	scanf("%d", &c);
	for (i = 0;i < c;i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		pr = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		if (pr==0 && r1 == r2)
			printf("-1\n");
		else if (pr == r1 + r2 || pr == abs(r1 - r2))
			printf("1\n");
		else if (abs(r1-r2)<pr&&pr < r1 + r2)
			printf("2\n");
		else
			printf("0\n");
	}
 }