#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 1000000
typedef struct
{
	int screen;
	int clip;
	int time;
}queue;
int rear = -1;
int front = -1;
bool visited[1001][1001];

void push(queue* q, int screen, int clip, int time)
{
	if (rear == MAXSIZE)
		return;
	else
	{
		rear = (rear + 1) % MAXSIZE;
		(q+rear)->screen = screen;
		(q+rear)->clip = clip;
		(q + rear)->time = time;
	}
}
void pop(queue* q)
{
	if (rear == front)
		return;
	else
		front = (front + 1) % MAXSIZE;
}
void BFS(int s)
{
	queue* q = (queue*)calloc(MAXSIZE + 1, sizeof(queue));
	push(q, 1, 0, 0);visited[1][0] = true;

	while (rear != front)
	{	
		pop(q);
		int now_screen = (q + front)->screen;
		int now_clip = (q + front)->clip;
		int now_time = (q + front)->time;

		if (now_screen == s)
		{
			printf("%d", now_time);
			return;
		}

		if (!visited[now_screen][now_screen] && now_screen < 1001)
		{
			push(q, now_screen, now_screen, now_time + 1);
			visited[now_screen][now_screen] = true;
		}
		
		if (now_screen + now_clip< 1001)
		{	
			if (!visited[now_screen + now_clip][now_clip] && now_clip != 0)
			{
				push(q, now_screen + now_clip, now_clip, now_time + 1);
				visited[now_screen + now_clip][now_clip] = true;
			}
		}

		if (!visited[now_screen - 1][now_clip] && (now_screen - 1) >= 0)
		{
			push(q, now_screen - 1, now_clip, now_time + 1);
			visited[now_screen - 1][now_clip] = true;
		}

	}
}
int main()
{
	int s;
	scanf("%d", &s);
	BFS(s);
}