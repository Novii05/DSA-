#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };

void display(struct Node *head){
    if(!head){ printf("List empty\n"); return; }
    struct Node *p=head;
    while(p){ printf("%d -> ", p->data); p=p->next; }
    printf("NULL\n");
}

void insert_front(struct Node **head){
    int x; printf("Enter value: "); if(scanf("%d",&x)!=1) return;
    struct Node *n = malloc(sizeof(*n)); n->data=x; n->next=*head; *head=n;
}

void insert_end(struct Node **head){
    int x; printf("Enter value: "); if(scanf("%d",&x)!=1) return;
    struct Node *n=malloc(sizeof(*n)); n->data=x; n->next=NULL;
    if(!*head) *head=n;
    else { struct Node *p=*head; while(p->next) p=p->next; p->next=n; }
}

void delete_value(struct Node **head){
    int x; printf("Enter value to delete: "); if(scanf("%d",&x)!=1) return;
    struct Node *p=*head, *prev=NULL;
    while(p && p->data!=x){ prev=p; p=p->next; }
    if(!p) { printf("Not found\n"); return; }
    if(!prev) *head=p->next; else prev->next=p->next;
    free(p); printf("Deleted\n");
}

int main(){
    struct Node *head=NULL;
    int choice;
    do{
        printf("\n1.Insert front\n2.Insert end\n3.Delete value\n4.Display\n5.Exit\nChoice: ");
        if(scanf("%d",&choice)!=1) break;
        switch(choice){
            case 1: insert_front(&head); break;
            case 2: insert_end(&head); break;
            case 3: delete_value(&head); break;
            case 4: display(head); break;
            case 5: break;
            default: printf("Invalid\n");
        }
    } while(choice!=5);
    return 0;
}
