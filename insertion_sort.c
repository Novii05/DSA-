#include <stdio.h>

void insertion_sort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    if(scanf("%d",&n)!=1) return 0;
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    insertion_sort(arr,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
