#include<stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if (left<n&&arr[largest]<arr[left]){
        largest = left;
    }
    if(right<n&&arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}
void head_sort(int arr[], int n){
    // step1 : build max heap
    for(int i=n/2-1;i>=0;i--){// no need to do for leaf nodes, so i = n/2-1
        heapify(arr,n,i);
    }
    // step2 : extract elements
    for(int i = n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);// we pass n is i, so, i is not heapify
    }
}
int main(){
    int arr[] = {4,10,3,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    head_sort(arr,n);
    printf("After sort: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}