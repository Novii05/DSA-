#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    if(c=='^') return 3;
    return 0;
}

char* infix_to_postfix(const char *exp){
    int n = strlen(exp);
    char *stack = malloc(n);
    int top = -1;
    char *out = malloc(2*n);
    int k=0;
    for(int i=0;i<n;i++){
        char c = exp[i];
        if(isspace((unsigned char)c)) continue;
        if(isalnum((unsigned char)c)) out[k++]=c;
        else if(c=='(') stack[++top]=c;
        else if(c==')'){
            while(top!=-1 && stack[top]!='(') out[k++]=stack[top--];
            if(top!=-1) top--;
        } else {
            while(top!=-1 && prec(stack[top])>=prec(c)) out[k++]=stack[top--];
            stack[++top]=c;
        }
    }
    while(top!=-1) out[k++]=stack[top--];
    out[k]='\0';
    free(stack);
    return out;
}

int main(){
    char expr[256];
    printf("Enter infix expression (no multi-digit operands): ");
    if(!fgets(expr,sizeof(expr),stdin)) return 0;
    expr[strcspn(expr,"\n")] = 0;
    char *post = infix_to_postfix(expr);
    printf("Postfix: %s\n", post);
    free(post);
    return 0;
}
