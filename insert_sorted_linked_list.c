#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };

void insert_sorted(struct Node **head, int x){
    struct Node *n = malloc(sizeof(*n)); n->data=x; n->next=NULL;
    if(!*head || (*head)->data >= x){
        n->next = *head; *head = n; return;
    }
    struct Node *p = *head;
    while(p->next && p->next->data < x) p=p->next;
    n->next = p->next; p->next = n;
}

void display(struct Node *head){
    while(head){ printf("%d -> ", head->data); head=head->next; }
    printf("NULL\n");
}

int main(){
    struct Node *head = NULL;
    int n;
    printf("Enter number of initial elements (sorted ascending): ");
    if(scanf("%d",&n)!=1) return 0;
    for(int i=0;i<n;i++){ int v; scanf("%d",&v); insert_sorted(&head,v); }
    printf("List before insertion:\n"); display(head);
    int x; printf("Enter element to insert: "); scanf("%d",&x);
    insert_sorted(&head,x);
    printf("List after insertion:\n"); display(head);
    return 0;
}
