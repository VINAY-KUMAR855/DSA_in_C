#include<stdio.h>
void shell_sort(int arr[], int N){
    
}
int main(){
    int arr[] = {22,34,25,12,64,11,90,88,45};
    int N = sizeof(arr)/sizeof(arr[0]);
    shell_sort(arr,N);
    printf("Sorted array: ");
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
}