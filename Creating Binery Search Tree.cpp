#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node *create_node(int data){
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

void postorder_traverse(Node *root) {
    if(root==NULL) return;
    postorder_traverse(root->left);
    postorder_traverse(root->right);
    cout<<root->data<<" ";
}

Node* BstInsert(struct Node* node,struct Node* root){
    if(root==NULL){
        return node;
    }
    if(node->data < root->data){
        root->left=BstInsert(node,root->left) ;
    }
    else{
        root->right=BstInsert(node,root->right) ;
    }
    return root; 
}

int main(){
    int a,b;
    struct Node *root=NULL,*node;
    while(cin>>a){
        node=create_node(a);
        root=BstInsert(node,root);
    }
    postorder_traverse(root);
    return 0;
}