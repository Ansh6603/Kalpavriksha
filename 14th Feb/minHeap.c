#include<stdio.h>
#define MAX_SIZE 100
typedef struct
{
    int array[MAX_SIZE];
    int size;
}MinHeap;
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapifyUp(MinHeap* heap,int index)
{
    int parent=(index-1)/2;
    if(index>0 && heap->array[index]<heap->array[parent])
    {
        swap(&heap->array[index],&heap->array[parent]);
        heapifyUp(heap,parent);
    }
}
void insert(MinHeap *heap,int value)
{
    if(heap->size==MAX_SIZE)
    {
        printf("Heap is Full \n");
        return ;
    }
    heap->array[heap->size]=value;
    heap->size++;
    heapifyUp(heap,heap->size-1);
}
void displayHeap(MinHeap* heap)
{
    if(heap->size==0)
    {
        printf("Heap is Empty \n");
        return;
    }
    for(int iteratorI=0;iteratorI<heap->size;iteratorI++)
    {
        printf("%d ",heap->array[iteratorI]);
    }
    printf("\n");
}
void heapifyDown(MinHeap* heap,int index)
{
    int leftIndex=2*index+1;
    int rightIndex=2*index+2;
    int smallest=index;
    if(leftIndex<heap->size && heap->array[leftIndex]<heap->array[smallest])
    {
        smallest=leftIndex;
    }
    if(rightIndex<heap->size && heap->array[rightIndex]<heap->array[smallest])
    {
        smallest=rightIndex;
    }
    if(smallest!=index)
    {
        swap(&heap->array[index], &heap->array[smallest]);
        heapifyDown(heap, smallest);
    }
}
int extractMin(MinHeap* heap)
{
    if(heap->size==0)
    {
        printf("MinHeap is Empty \n");
        return -1;
    }
    int minValue=heap->array[0];
    heap->array[0]=heap->array[heap->size-1];
    heap->size--;
    heapifyDown(heap,0);
    return minValue;
}
int main()
{
    MinHeap heap;
    heap.size=0;
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 30);
    insert(&heap, 40);
    insert(&heap, 5);
    displayHeap(&heap);
    printf("Deleted Element : %d \n",extractMin(&heap));
    displayHeap(&heap);
    
}