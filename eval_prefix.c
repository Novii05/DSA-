#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int eval_prefix(const char *exp){
    int n=strlen(exp);
    int *stack = malloc(n*sizeof(int));
    int top=-1;
    for(int i=n-1;i>=0;i--){
        char c=exp[i];
        if(isspace((unsigned char)c)) continue;
        if(isdigit((unsigned char)c)) stack[++top]=c-'0';
        else {
            int a=stack[top--];
            int b=stack[top--];
            int res=0;
            if(c=='+') res=a+b;
            else if(c=='-') res=a-b;
            else if(c=='*') res=a*b;
            else if(c=='/') res=a/b;
            else if(c=='^'){ int r=1; for(int j=0;j<b;j++) r*=a; res=r; }
            stack[++top]=res;
        }
    }
    int ans = stack[top];
    free(stack);
    return ans;
}

int main(){
    char expr[256];
    printf("Enter prefix expression (single-digit operands): ");
    if(!fgets(expr,sizeof(expr),stdin)) return 0;
    expr[strcspn(expr,"\n")] = 0;
    int res = eval_prefix(expr);
    printf("Result = %d\n", res);
    return 0;
}
