#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define INF 1.0e+7
#define MIN(a,b)a<b?a:b
typedef struct
{
	int point;
	int distance;
}element;
typedef struct
{
	int size;
	element arr[200001];
}heap;
int n, e;
int graph[801][801];
int d[3][801];
int min_dis = INF;

void push(heap *h,int point, int dis)
{
	h->size++;
	int child = h->size;
	int parent = child / 2;

	while (child != 1 && dis < h->arr[child].distance)
	{
		h->arr[child].point = h->arr[parent].point;
		h->arr[child].distance = h->arr[parent].distance;
		child = parent;
		parent = child / 2;
	}

	h->arr[child].distance = dis;
	h->arr[child].point = point;

}
void pop(heap* h)
{
	if (h->size == 0)
		return;
	element temp = h->arr[h->size--];
	int parent = 1;
	int child = 2;

	while (child <= h->size)
	{
		if (child < h->size && h->arr[child].distance > h->arr[child + 1].distance)
			child++;

		if (h->arr[child].distance >= temp.distance)
			break;
		else
		{
			h->arr[parent].distance = h->arr[child].distance;
			h->arr[parent].point = h->arr[child].point;
			parent = child;
			child = parent * 2;
		}
	}

	h->arr[parent].distance = temp.distance;
	h->arr[parent].point = temp.point;
}
void daikstra(int start,int *d)
{
	heap* h = (heap*)calloc(1, sizeof(heap));
	push(h, start, 0);d[start] = 0;

	while (h->size != 0)
	{
		int current = h->arr[1].point;
		int distance = h->arr[1].distance;
		pop(h);

		if (d[current] <distance)
			continue;

		for (int i = 1;i <= n;i++)
		{
			int next_distance = graph[current][i] + distance;

			if (d[i] > next_distance)
			{
				d[i] = next_distance;
				push(h, i, next_distance);
			}
		}
	}
}
void solve(int v1, int v2)
{
	if (v1 == 1 && v2 == n)
		min_dis = d[0][n];
	else if (v1 == 1)
	{
		if (d[0][v2] < INF && d[2][n] < INF)
			min_dis = MIN(d[0][v2] + d[2][n], min_dis);
	}
	else if (v2 == n)
	{
		if (d[0][v1] < INF && d[1][n] < INF)
			min_dis = MIN(d[0][v1] + d[1][n], min_dis);
	}
	else
	{
		if (d[0][v1] < INF && d[1][v2] < INF && d[2][n] < INF)
			min_dis = MIN(d[0][v1] + d[1][v2] + d[2][n],min_dis);

		if (d[0][v2] < INF && d[2][v1] < INF && d[1][n] < INF)
			min_dis = MIN(d[0][v2] + d[2][v1] + d[1][n], min_dis);
	}

	if (min_dis == INF)
		printf("-1");
	else
		printf("%d", min_dis);
}
int main()
{
	int v1, v2;
	int st, end, dis;
	scanf("%d %d", &n, &e);

	for (int i = 0;i <= 3;i++)
		for(int j=0;j<=n;j++)
			d[i][j] = INF;
	
	for (int i = 0;i <= n;i++)
		for (int j = 0;j <= n;j++)
			graph[i][j] = INF;

	for (int i = 0;i < e;i++)
	{
		scanf("%d %d %d", &st, &end, &dis);
		graph[st][end] = MIN(dis, graph[st][end]);
		graph[end][st] = graph[st][end];
	}

	scanf("%d %d", &v1, &v2);

	daikstra(1, d[0]);
	if (v1 == 1 && v2 != n)
		daikstra(v2, d[2]);
	else if(v1!=1 && v2 == n)
		daikstra(v1, d[1]);
	else
	{
		daikstra(v1, d[1]);
		daikstra(v2, d[2]);
	}
	
	solve(v1,v2);
}