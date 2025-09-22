#include <stdio.h>

int main(){
    int n;
    printf("Enter number of elements (sorted ascending): ");
    if(scanf("%d",&n)!=1) return 0;
    int size = n+1;
    int arr[size];
    printf("Enter %d sorted elements:\n", n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int x;
    printf("Enter element to insert: ");
    scanf("%d",&x);
    int i = n-1;
    while(i>=0 && arr[i] > x){
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = x;
    printf("Array after insertion:\n");
    for(int j=0;j<=n;j++) printf("%d ", arr[j]);
    printf("\n");
    return 0;
}
