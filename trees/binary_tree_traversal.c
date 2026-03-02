#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left,* right;
};
struct node* cretateNode(int value){
    struct node* newNode =(struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL; 
}
void inorder(struct node* root){
    if (root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root){
    if (root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct node * root =cretateNode(1);
    root->left = cretateNode(2);
    root->right = cretateNode(3);
    root->left->left = cretateNode(4);
    root->left->right = cretateNode(5);
    // inorder
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);

}