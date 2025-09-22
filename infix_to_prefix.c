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

char* reverse_str(const char *s){
    int n=strlen(s);
    char *r = malloc(n+1);
    for(int i=0;i<n;i++) r[i]=s[n-1-i];
    r[n]=0;
    return r;
}

char* infix_to_prefix(const char *exp){
    int n=strlen(exp);
    char *rev = malloc(n+1);
    int ri=0;
    for(int i=n-1;i>=0;i--){
        char c=exp[i];
        if(c=='(') rev[ri]=')';
        else if(c==')') rev[ri]='(';
        else rev[ri]=c;
        ri++;
    }
    rev[ri]=0;
    char *stack = malloc(n);
    int top=-1;
    char *out = malloc(2*n);
    int k=0;
    for(int i=0;i<strlen(rev);i++){
        char c=rev[i];
        if(isspace((unsigned char)c)) continue;
        if(isalnum((unsigned char)c)) out[k++]=c;
        else if(c=='(') stack[++top]=c;
        else if(c==')'){
            while(top!=-1 && stack[top]!='(') out[k++]=stack[top--];
            if(top!=-1) top--;
        } else {
            while(top!=-1 && prec(stack[top])>prec(c)) out[k++]=stack[top--];
            stack[++top]=c;
        }
    }
    while(top!=-1) out[k++]=stack[top--];
    out[k]=0;
    char *pref = reverse_str(out);
    free(stack); free(out); free(rev);
    return pref;
}

int main(){
    char expr[256];
    printf("Enter infix expression (no multi-digit operands): ");
    if(!fgets(expr,sizeof(expr),stdin)) return 0;
    expr[strcspn(expr,"\n")] = 0;
    char *pref = infix_to_prefix(expr);
    printf("Prefix: %s\n", pref);
    free(pref);
    return 0;
}
