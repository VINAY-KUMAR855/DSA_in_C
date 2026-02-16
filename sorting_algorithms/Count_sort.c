#include<stdio.h>

void count_sort(int arr[],int N){
    int max = 0;
        for(int i=0; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max+1];
    // initialize with 0
    for(int i = 0; i <= max; i++){
        count[i] = 0;
    }
    // count num of times element occur
    for (int i=0;i<N;i++){
        ++count[arr[i]];
    }
    // increase by 
    for(int i=1;i<(max+1);i++){
        count[i] += count[i-1];
    }
    // take another array
    int b[N];
    for (int i=N-1;i>=0;i--){
        b[--count[arr[i]]] = arr[i] ;
    }

    for (int i=0;i<N;i++){
        arr[i] = b[i];
    }

    
}
int main(){
    int arr[] = {0,1,1,2,3,3,3,4,2,1,2,3};
    int N = sizeof(arr)/sizeof(arr[0]);
    count_sort(arr,N);
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
}