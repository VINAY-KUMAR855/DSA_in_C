#include<stdio.h>
#define SIZE 100
int heap[SIZE];
int n=0; // number of elements
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// heapify up (insert)
void insert(int value){
    if(n==SIZE){
        printf("Heap overflow\n");
        return;
    }
    heap[n] = value;
    int i=n;
    n++;
    while(i!=0&&heap[(i-1)/2]<heap[i]){
        swap(&heap[(i-1)/2],&heap[i]);
        i = (i-1)/2;
    }
}
void display(){
    printf("Heap: ");
    for(int i=0;i<n;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}
// delete (heapify down)

void heapifyDown(int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    // find largest
    if(left<n&&heap[largest]<heap[left]){
        largest = left;
    }
    if(right<n&&heap[largest]<heap[right]){
        largest = right;
    }
    // replace with largest.
    if(largest!=i){
        swap(&heap[i],&heap[largest]);
        heapifyDown(largest);
    }
}
void deleteRoot(){
    if(n<=0){
        printf("Heap is empty\n");
        return;
    }
    // replace root with leaft
    heap[0] = heap[n-1];
    // decrement n
    n--;
    heapifyDown(0);
}
int main(){
    insert(1);
    insert(2);
    insert(4);
    insert(1);
    display();
    deleteRoot();
    display();
    deleteRoot();
    display();
}