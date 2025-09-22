#include <stdio.h>

void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++) if(arr[j]<arr[min_idx]) min_idx=j;
        int t=arr[i]; arr[i]=arr[min_idx]; arr[min_idx]=t;
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    if(scanf("%d",&n)!=1) return 0;
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    selection_sort(arr,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
