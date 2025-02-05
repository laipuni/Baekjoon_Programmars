#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int count;
	int arr[100001];
}HEAP;
void add_heap(HEAP *heap,int num)
{	
	heap->count+=1;
	int child = heap->count;
	int parent = child / 2;
	while (child != 1 && num < heap->arr[parent])
	{
		heap->arr[child] = heap->arr[parent];
		child = parent;
		parent = child / 2;
	}
	heap->arr[child] = num;
}
int remove_heap(HEAP* heap)
{	
	if (heap->count == 0)
		return 0;
	int num = heap->arr[heap->count--];
	int answer = heap->arr[1];
	int parent = 1;
	int child = 2;
	while (child <= heap->count)
	{
		if (heap->arr[child] > heap->arr[child+1]&&heap->count>2)
			child++;
		if (num <= heap->arr[child])
			break;
		else
		{	
			heap->arr[parent] = heap->arr[child];
			parent = child;
			child = parent * 2;
		}
	}
	heap->arr[parent] = num;
	return answer;
}
int main()
{
	int n,temp;
	HEAP* heap = (HEAP*)calloc(1,sizeof(HEAP));
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{	
		scanf("%d", &temp);
		if (temp!=0)
			add_heap(heap, temp);
		else
			printf("%d\n", remove_heap(heap));
	}
}