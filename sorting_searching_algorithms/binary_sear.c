#include<stdio.h>
void binary_search(int arr[], int low, int high, int key){
    int mid = (low+high)/2;
    if (low<=high){
        if (arr[mid]==key){
            printf("key found at %d\n",mid);
            return;
        }
        else if(arr[mid]<key){
            low = mid+1;
            binary_search(arr,low,high,key);
        }
        else{
            high =mid-1;
            binary_search(arr,low,high,key);
        }
    }
    else{
        printf("Element not found.\n");
        return;
    }
}
int main(){
    int arr[] = {10,12,20,32,50,55,65,80,99};
    int N = sizeof(arr)/sizeof(arr[0]);
    binary_search(arr,0,N-1,99);

    return 0;
}
