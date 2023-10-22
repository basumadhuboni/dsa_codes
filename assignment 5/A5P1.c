#include<stdio.h>
int top = -1, n;
int push(char arr[], char ele){
    top = top + 1;
    arr[top] = ele;
    return top;
}
char pop(char arr[]){
    char ele = arr[top];
    
     
        top=top-1;
    
    return ele;
}
int is_operator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return 1;
    else
        return 0;
}
int precedence(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 main(){
    printf("enter max no of elements in the stack: ");
    scanf("%d", &n);
    char exp[n],exp1[n],postfix[n], stack[n];
    int i,k;
    printf("enter the expression: ");
    scanf("%s", exp1);
    //reversing the expression
    for(i=0;i<n;i++){
        if(exp1[i]=='('){
            exp[n-1-i]=')';
        }
        else if(exp1[i]==')'){
            exp[n-i-1]='(';
        }
        else{
             exp[n-1-i]=exp1[i];
        }
    }
    //finding post fix 
    i = 0, k = 0;
    while(i < n){
        char c = exp[i];
        if(!is_operator(c) && c != '(' && c != ')'){
            postfix[k] = c;
            k = k + 1;
        }
        else {
            if(c == '('){
                top = push(stack, c);
            }
            else if(c == ')'){
                while(top != -1 && stack[top] != '('){
                    postfix[k] = pop(stack);
                    k = k + 1;
                }
                if(top != -1 && stack[top] == '(')
                    top = top - 1;
            }
            else {
                while(top != -1 && precedence(c) < precedence(stack[top])){
                    postfix[k] = pop(stack);
                    k = k + 1;
                }
                top = push(stack, c);
            }
        }
        i = i + 1;
    }
    while(top != -1){
        postfix[k] = pop(stack);
        k = k + 1;
    }
    //reversing the postfix
    char prefix[k];
    for(i=0;i<k;i++){
        if(postfix[i]=='('){
            prefix[k-1-i]=')';
        }
        else if(postfix[i]==')'){
            prefix[k-i-1]='(';
        }
        else{
             prefix[k-1-i]=postfix[i];
        }
    }
    printf("the prefix expression is: \n");
    for(i=0;i<k;i++){
        printf("%c ",prefix[i]);
    }
}
   
