#include<stdio.h>
// recursive function
// factorial
// int factorial(int n){
//     if(n==0||n==1){
//         return 1;
//     }else{
//         return n*factorial(n-1);
//     }
// }
void insertion_sort(int arr[], int N){
    int i,j,temp;
    for (i=1;i<N;i++){
        for (j=i-1;j>=0&& arr[j]>arr[j+1];j-- ){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}

int main(){
    // int num =5;
    // printf("%d",factorial(num));
    int  arr[] = {15,20,10,30,50,18,5,45};
    int N = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,N);
    printf("sorted array: ");
    for(int i=0;i<N;i++){
        printf("%d\n ",arr[i]);
    }
}