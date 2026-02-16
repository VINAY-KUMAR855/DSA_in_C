// 6523+-* = 0   34+5* = 35   
// 231*+9- = -4
// 753*5/+32-+ = 11
#include<stdio.h>
#include<ctype.h>
#define SIZE 50
int stack[SIZE];
int top=-1;
void push(int ch){
    stack[++top] = ch;
}
int pop(){
    return stack[top--];
}
int postfixEvalution(char infix[]){
    char ch;
    int i=0, num,A,B,C; 
    while((ch = infix[i])!='\0'){
        if (isalnum(ch)){
            num = ch-'0';
            push(num);
            i++;
        }
        else if (ch=='+'|| ch=='-'||ch=='*'||ch=='/'){
            A = pop();
            B = pop();
            switch (ch){
                case '+' : C = B+A;break;
                case '-' : C = B-A;break;
                case '*' : C = B*A;break;
                case '/' : C = B/A;break;
            }
            push(C);
            i++;
        }
        else{
            // ignore spaces and invalid characters 
            i++;
        }
    }
    return pop();
}

int main(){
    char postfix[SIZE];
    printf("Enter postfix expression: ");
    scanf("%s",postfix);
    printf("%s = %d",postfix,postfixEvalution(postfix));
    return 0;
}