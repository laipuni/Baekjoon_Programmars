#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define INF 1.0e+9
#define MIN(a,b)a<b?a:b
typedef struct
{
	int point;
	int distance;
}element;
typedef struct
{
	int size;
	element *arr;
}heap;

int **graph;
int *d;
int v, e;
bool visited[20001];

void push(heap* h, int point, int distance)
{
	h->size++;

	int child = h->size;
	int parent = child / 2;

	while (child != 1 && distance < h->arr[parent].distance)
	{
		h->arr[child].point = h->arr[parent].point;
		h->arr[child].distance = h->arr[parent].distance;
		child = parent;
		parent = child / 2;
	}

	h->arr[child].point = point;
	h->arr[child].distance = distance;

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
		if (child<h->size && h->arr[child].distance > h->arr[child + 1].distance)
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

void daikstra(int start)
{
	heap* h = (heap*)calloc(1, sizeof(heap));
	h->arr = (element*)calloc(v + 1, sizeof(element));

	push(h, start, 0);
	d[start] = 0;
	
	while (h->size != 0)
	{
		int current = h->arr[1].point;
		int distance = h->arr[1].distance;
		pop(h);
		visited[current] = true;

		if (distance >d[current])
			continue;

		for (int i = 1;i <= v;i++)
		{
			int nextdistance = distance + graph[current][i];

			if (d[i] > nextdistance&&!visited[i])
			{
				d[i] = nextdistance;
				push(h, i, nextdistance);
			}
		}
	}
}

int main()
{	
	int start, end, dis,k,m;
	scanf("%d %d", &v, &e);
	graph = (int**)calloc(v + 1, sizeof(int*));
	d = (int*)calloc(v + 1, sizeof(int));

	for (int i = 0;i <= v;i++)
		graph[i] = (int*)calloc(v + 1, sizeof(int));

	for (int i = 0;i <= v;i++)
		for (int j = 0;j <= v;j++)
			graph[i][j] = INF;

	for (int i = 0;i <= v;i++)
		d[i] = INF;

	for (int i = 0;i < e;i++)
	{
		scanf("%d %d %d", &start, &end, &dis);
		graph[start][end] = MIN(graph[start][end],dis);
	}
	scanf("%d %d", &k, &m);

	daikstra(k);

	printf("%d", d[m]);

}