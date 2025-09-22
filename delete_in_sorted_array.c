#include <stdio.h>

int main(){
    int n;
    printf("Enter number of elements (sorted ascending): ");
    if(scanf("%d",&n)!=1) return 0;
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int x;
    printf("Enter element to delete: ");
    scanf("%d",&x);
    int pos = -1;
    for(int i=0;i<n;i++) if(arr[i]==x){ pos=i; break; }
    if(pos==-1){
        printf("Element not found.\n");
    } else {
        for(int i=pos;i<n-1;i++) arr[i]=arr[i+1];
        printf("Array after deletion:\n");
        for(int i=0;i<n-1;i++) printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}
