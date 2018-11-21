

/* probably those header files are all you need */
#define MEASURE_TIME

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#ifdef MEASURE_TIME
#include<time.h>
#endif


typedef struct{
	int last;
	int size;
	int* array;
	int max_size;
}HEAP;

HEAP* create_heap(int max){
	HEAP* heap=(HEAP*)malloc(sizeof(HEAP));
	heap->last=-1;
	heap->size=0;
	heap->max_size=max;
	heap->array=(int*)malloc(sizeof(int)*max);
	return heap;
}

void reheapup(HEAP* heap,int last){
int parent;
int tmp;
if (last!=0) {	
	parent=(last-1)/2;
	if (heap->array[last]>heap->array[parent]){
		tmp=heap->array[last];
		heap->array[last]=heap->array[parent];
		heap->array[parent]=tmp;
	reheapup(heap,parent);	
	}
}
}
void insertmaxheap(HEAP* heap,int last,int data){
	heap->last=heap->last+1;
	(heap->size)++;
	
	heap->array[last+1]=data;
	if (last!=0)
	reheapup(heap,last+1);
	
}

void reheapdown(HEAP* heap,int last){
int parent;
int tmp;
if (last!=0) {	
	parent=(last-1)/2;
	if (heap->array[last]<heap->array[parent]){
		tmp=heap->array[last];
		heap->array[last]=heap->array[parent];
		heap->array[parent]=tmp;
	reheapdown(heap,parent);	
	}
}
}
void insertminheap(HEAP* heap,int last,int data){
	(heap->last)++;
	(heap->size)++;
	
	heap->array[last+1]=data;
	if (last!=0)
	reheapdown(heap,last+1);
	
}

void maxheapdown(HEAP* heap,int index){
if (index>=heap->last) return;
if (2*index+2>heap->last) return;
int tmp;
	if (heap->array[2*index+1]>heap->array[2*index+2]){
		if(heap->array[index]<heap->array[2*index+1]){
		tmp=heap->array[2*index+1];
		heap->array[2*index+1]=heap->array[index];
		heap->array[index]=tmp;
		maxheapdown(heap,2*index+1);		
		}}
	else {
		if(heap->array[index]<heap->array[2*index+2]){
		tmp=heap->array[2*index+2];
		heap->array[2*index+2]=heap->array[index];
		heap->array[index]=tmp;
		maxheapdown(heap,2*index+2);
		}}
}
	
void minheapdown(HEAP* heap,int index){
if (index>heap->last) return;
if (2*index+2>heap->last) return;
int tmp;
	if (heap->array[2*index+1]<heap->array[2*index+2]){
		if(heap->array[index]>heap->array[2*index+1]){
		tmp=heap->array[2*index+1];
		heap->array[2*index+1]=heap->array[index];
		heap->array[index]=tmp;
		minheapdown(heap,2*index+1);}		
		}
	else {
		if(heap->array[index]>heap->array[2*index+2]){
		tmp=heap->array[2*index+2];
		heap->array[2*index+2]=heap->array[index];
		heap->array[index]=tmp;
		minheapdown(heap,2*index+2);
		}}
}

int deletemaxheaproot(HEAP* heap,int last){

int delete;
int tmp;
	delete=heap->array[0];
	tmp=heap->array[0];
	heap->array[0]=heap->array[last];
	heap->array[last]=tmp;

	(heap->last)--;
	(heap->size)--;


	maxheapdown(heap,0);


	return delete;
}

int deleteminheaproot(HEAP* heap,int last){

int delete;
int tmp;
	delete=heap->array[0];
	tmp=heap->array[0];
	heap->array[0]=heap->array[last];
	heap->array[last]=tmp;

	(heap->last)--;
	(heap->size)--;	

	
	minheapdown(heap,0);

	return delete;
}

void heap4median_additem(int i,HEAP* left,HEAP* right){
int tmp;
	if (left->size==0) insertmaxheap(left,left->last,i);
	else if (i>left->array[0]) insertminheap(right,right->last,i);
	else  insertmaxheap(left,left->last,i);



	if (left->size-right->size>=2) {
		tmp=deletemaxheaproot(left,left->last);
		insertminheap(right,right->last,tmp);
		}
	else if (right->size-left->size>=2){
		tmp=deleteminheaproot(right,right->last);
		insertmaxheap(left,left->last,tmp);
		}
}

void heap4median_build(int a[],int N,HEAP* L,HEAP* R){
	int i=0;
	
	for (i=0;i<N;i++){
		heap4median_additem(a[i],L,R);
	}
}

int main()
{
  int i=0;
  int N=0;
int val=0;
	/* number of data */
	/* data in array */
 
#ifdef MEASURE_TIME
  clock_t start, end;
  double cpu_time_used;

  start = clock();
#endif

  /* fprintf(stdout, "Number of data? "); */
  fscanf(stdin, "%d", &N);
	int A[N];
	HEAP* L=create_heap(N/2+1);
	HEAP* R=create_heap(N/2+1);
	for (i=0; i<N; i++) {
		fscanf(stdin, "%d", &val);
		A[i]=val;
			}
	

	heap4median_build(A,N,L,R);

	printf("L's root: %d\n",L->array[0]);
	printf("L's size: %d\n",L->size);
	printf("R's root: %d\n",R->array[0]);
	printf("L's size: %d\n",R->size);
	
	
#ifdef MEASURE_TIME
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  fprintf(stderr,">> Execution time: %.5f seconds\n",cpu_time_used);
#endif

free(L->array);
free(L);
free(R->array);
free(R);
}


