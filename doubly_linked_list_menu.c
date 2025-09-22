#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *prev; struct Node *next; };

void display_forward(struct Node *head){
    if(!head){ printf("Empty\n"); return; }
    struct Node *p=head;
    while(p){ printf("%d -> ", p->data); p=p->next; }
    printf("NULL\n");
}

void display_backward(struct Node *tail){
    if(!tail){ printf("Empty\n"); return; }
    struct Node *p=tail;
    while(p){ printf("%d -> ", p->data); p=p->prev; }
    printf("NULL\n");
}

void insert_end(struct Node **head, struct Node **tail, int x){
    struct Node *n = malloc(sizeof(*n)); n->data=x; n->next=NULL; n->prev=NULL;
    if(!*head){ *head = *tail = n; return; }
    (*tail)->next = n; n->prev = *tail; *tail = n;
}

void delete_value(struct Node **head, struct Node **tail, int x){
    struct Node *p = *head;
    while(p && p->data!=x) p=p->next;
    if(!p){ printf("Not found\n"); return; }
    if(p->prev) p->prev->next = p->next; else *head = p->next;
    if(p->next) p->next->prev = p->prev; else *tail = p->prev;
    free(p); printf("Deleted\n");
}

int main(){
    struct Node *head=NULL, *tail=NULL;
    int ch, val;
    do{
        printf("\n1.Insert end\n2.Delete value\n3.Display forward\n4.Display backward\n5.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("Value: "); scanf("%d",&val); insert_end(&head,&tail,val); break;
            case 2: printf("Value: "); scanf("%d",&val); delete_value(&head,&tail,val); break;
            case 3: display_forward(head); break;
            case 4: display_backward(tail); break;
            case 5: break;
            default: printf("Invalid\n");
        }
    } while(ch!=5);
    return 0;
}
