#include <stdio.h>

void bubble_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int swapped = 0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int t=arr[j]; arr[j]=arr[j+1]; arr[j+1]=t;
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    if(scanf("%d",&n)!=1) return 0;
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    bubble_sort(arr,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
