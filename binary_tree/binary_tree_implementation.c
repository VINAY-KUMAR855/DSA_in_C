#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left,*right; 
};
struct node* create(){
    int x;
    printf("Enter data: ");
    scanf("%d",&x);
    if (x==-1){
        return 0;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    printf("Enter left child of %d\n",x);
    newNode->left = create();
    printf("Enter right child of %d\n",x);
    newNode->right = create();
    return newNode;
}

int main(){
    struct node* root;
    root = create();
}