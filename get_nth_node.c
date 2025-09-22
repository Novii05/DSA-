#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };

struct Node* get_nth(struct Node *head, int n){
    int i=0;
    while(head && i<n){ head = head->next; i++; }
    return head;
}

void push(struct Node **head, int x){
    struct Node *n = malloc(sizeof(*n)); n->data=x; n->next=*head; *head=n;
}

void display(struct Node *head){
    while(head){ printf("%d -> ", head->data); head=head->next; }
    printf("NULL\n");
}

int main(){
    struct Node *head = NULL;
    int k, val;
    printf("Enter number of nodes to push (will be pushed at front): ");
    if(scanf("%d",&k)!=1) return 0;
    printf("Enter %d values:\n", k);
    for(int i=0;i<k;i++){ scanf("%d",&val); push(&head,val); }
    display(head);
    int n;
    printf("Enter index (0-based) of Nth node to get: ");
    scanf("%d",&n);
    struct Node *res = get_nth(head,n);
    if(res) printf("Node at index %d: %d\n", n, res->data);
    else printf("Index out of range\n");
    return 0;
}
