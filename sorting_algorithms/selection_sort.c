#include<stdio.h>
void selectionSort(int arr[],int N){
    int temp;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if (arr[i]>arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int main(){
    int arr[] = {10,2,53,32,12,0,100,99};
    int N = sizeof(arr)/ sizeof(arr[0]);
    printf("Array before sort: ");
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
    selectionSort(arr,N);
    printf("\nArray after sort: ");
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
}