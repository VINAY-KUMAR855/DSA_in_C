#include<stdio.h>
void insertion_sort(int arr[],int N){
    int i,j,key;
    for(i=1;i<N;i++){
        j=i-1;
        key = arr[i];
        while(j>=0&&arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
int main(){
    int arr[] = {15,20,10,30,50,18,5,45};
    int N=(sizeof(arr)/sizeof(arr[0]));
    printf("Unsorted array: ");
    for (int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
    insertion_sort(arr,N);
    printf("\nSorted array: ");
    for (int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
}