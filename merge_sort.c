#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    int *L = malloc(n1*sizeof(int));
    int *R = malloc(n2*sizeof(int));
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
    free(L); free(R);
}

void merge_sort(int arr[], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    if(scanf("%d",&n)!=1) return 0;
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    merge_sort(arr,0,n-1);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
