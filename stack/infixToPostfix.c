// eg:- a+b/c*d-e/(f+g) -> abc/d*+efg+/- 
// 3+5*(5/5)-2^2  ->  3555/*+22^-
// 7+5*3/5^1+(3-2)  ->  753*51^/+32-+
#include<stdio.h>
#include<ctype.h> // character handling library
#define SIZE 50

char stack[SIZE];
int top= -1;
void push(char value){
    stack[++top] = value;
}
char pop(){
    return stack[top--];
}
int precedence(char ch){
    if (ch=='^'){
        return 3;
    } else if(ch=='*' || ch=='/'){
        return 2;
    } else if (ch=='+'||ch=='-'){
        return 1;
    }
    return 0;
}
void infixToPostfix(char infix[]){
    char ch;
    int i=0;
    while((ch=infix[i])!='\0'){
        if (isalnum(ch)){
            printf("%c",ch);
        }else if(ch=='('){
            push(ch);
        }else if(ch==')'){
            while(stack[top]!='('){
                printf("%c",pop());
            }
            pop();
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(ch)){
                printf("%c",pop());
            }
            push(ch);
        }
        i++;
    }
    while(top!=-1){
        printf("%c",pop());
    }
}
int main(){
    char infix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s",infix);
    infixToPostfix(infix);
    return 0;
}