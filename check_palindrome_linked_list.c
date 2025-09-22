#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };

void push(struct Node **head, int x){
    struct Node *n = malloc(sizeof(*n)); n->data=x; n->next=*head; *head=n;
}

int is_palindrome(struct Node *head){
    if(!head || !head->next) return 1;
    // find middle
    struct Node *slow=head, *fast=head;
    while(fast->next && fast->next->next){ slow=slow->next; fast=fast->next->next; }
    // reverse second half
    struct Node *prev=NULL, *cur=slow->next;
    while(cur){
        struct Node *nx=cur->next;
        cur->next=prev;
        prev=cur; cur=nx;
    }
    // compare
    struct Node *p1=head, *p2=prev;
    int result = 1;
    while(p2){
        if(p1->data != p2->data){ result=0; break; }
        p1=p1->next; p2=p2->next;
    }
    // restore (optional)
    cur = prev; prev = NULL;
    while(cur){
        struct Node *nx=cur->next;
        cur->next=prev; prev=cur; cur=nx;
    }
    slow->next = prev;
    return result;
}

void display(struct Node *head){
    while(head){ printf("%d -> ", head->data); head=head->next; }
    printf("NULL\n");
}

int main(){
    struct Node *head=NULL;
    int n, v;
    printf("Enter number of nodes: ");
    if(scanf("%d",&n)!=1) return 0;
    printf("Enter %d values:\n", n);
    for(int i=0;i<n;i++){ scanf("%d",&v); push(&head,v); } // pushes at front
    printf("List (note: pushed at front):\n"); display(head);
    if(is_palindrome(head)) printf("Palindrome\n"); else printf("Not palindrome\n");
    return 0;
}
