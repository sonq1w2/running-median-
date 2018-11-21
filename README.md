running medain을 구하기 위해서 왼쪽 heap은 max heap,오른쪽은 min heap을 만든다.  
여기서 왼쪽 heap의 루트값이 중간값이 된다.  
  
typedef struct{  
	int last;  
	int size;  
	int* array;  
	int max_size;  
}HEAP;  
  
void insertmaxheap(HEAP* heap,int last,int data){  
-heap의 array 사이즈를 늘려준다.  
-array의 맨 뒤에 새로운 값을 넣고 reheapup시킨다.  
  
void reheapup(HEAP* heap,int last){  
-parent의 값과 비교해서 새로운 값이 자기에게 맞는 위치로 가도록 해준다.  
  
int deletemaxheaproot(HEAP* heap,int last){  
-root를 삭제를 할때 이 값을 array의 맨 뒤에다 넣고 마지막 값을 맨앞으로 옮긴다.  
-삭제될 값을 제외한 범위에서 maxheapdown해준다.  
  
void maxheapdown(HEAP* heap,int index){  
-원래 array에서 가장 작은 값을 맨앞에 옮겼기 때문에 이 값을 제자리로 내려가게 한다.  
  
void heap4median_additem(int i,HEAP* left,HEAP* right){  
-heap을 구현했으니 running median을 구현한다.  
-왼쪽 heap의 root보다 값이 크면 오른쪽 heap에 넣고 나머지 경우는 왼쪽에 넣는다.  
-그 후에 HEAP에서 정의한 size를 이용해서 노드갯수가 두개 이상 차이나면 균형을 맞춰준다.
