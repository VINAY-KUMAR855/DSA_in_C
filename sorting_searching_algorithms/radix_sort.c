#include<stdio.h>
void count_sort(int arr[], int N,int divide){
    // int max = 9;
    // int count[max+1];
    int count[10];
    for(int i=0;i<=9;i++){
        count[i] = 0;
    }
    
    for(int i=0;i<N;i++){
        ++count[(arr[i]/divide)%10];
    }
    for(int i=1;i<=9;i++){
        count[i] +=count[i-1];
    }
    int b[N];
    for(int i=N-1;i>=0;i--){
        b[--count[(arr[i]/divide)%10]] = arr[i];
    }
    for(int i=0;i<N;i++){
        arr[i] = b[i];
    }
}
int getMax(int arr[],int N){
    int max = arr[0];
    for(int i=0;i<N;i++){
        if (max<arr[i]){
            max = arr[i];
        }
        return max;
    }
}
void radix_sort(int arr[], int N){
    int max=getMax(arr,N);
    int divide = 1;
    while(max>0){
        count_sort(arr,N,divide);
        max/=10;
        divide*=10;
    }

}
int main(){
    int arr[] = {432,8,530,90,88,231,11,45,677,199};
    int N = sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr,N);
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
}