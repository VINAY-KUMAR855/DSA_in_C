#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left, *right;
};
struct node* create(){
    int x;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);
    if (x==0) return 0;
    newNode->data = x;
    printf("Enter left child of %d\n",x);
    newNode->left = create();
    printf("Enter right child of %d\n",x);
    newNode->right = create();
    return newNode;
}
void inorder(struct node* root){
    if(root==0) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

}
int main(){
    struct node* root;
    root = create();
    printf("Inorder :");
    inorder(root);
}
// Eg output :-

// Enter data(-1 for no node):1
// Enter left child of 1
// Enter data(-1 for no node):2
// Enter left child of 2
// Enter data(-1 for no node):0
// Enter right child of 2
// Enter data(-1 for no node):0
// Enter right child of 1
// Enter data(-1 for no node):3
// Enter left child of 3
// Enter data(-1 for no node):0
// Enter right child of 3
// Enter data(-1 for no node):0
// Inorder :2 1 3 

