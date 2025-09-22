#include <stdio.h>

int linear_search(int arr[], int n, int key){
    for(int i=0;i<n;i++)
        if(arr[i]==key) return i;
    return -1;
}

int main(){
    int n;
    printf("Enter number of elements: ");
    if(scanf("%d",&n)!=1) return 0;
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int key;
    printf("Enter key to search: ");
    scanf("%d",&key);
    int idx = linear_search(arr,n,key);
    if(idx==-1) printf("Not found\n"); else printf("Found at index %d (0-based)\n", idx);
    return 0;
}
