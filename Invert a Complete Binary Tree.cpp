#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *create_node(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

void PreOrderedTransversal(struct Node * root){
    if(root!=NULL){
        cout<<root->data<<" ";
        PreOrderedTransversal(root->left);
        PreOrderedTransversal(root->right);
    }
}

struct Node* bineryTreeFormation(int index,vector<int>&array,int arraySize){
    if(index<arraySize){
        Node *node= create_node(array[index]);
        node->right=bineryTreeFormation(2*index+1,array,arraySize);
        node->left=bineryTreeFormation(2*index+2,array,arraySize);
        return node;
    }
    return NULL;
}
Node *remove_null_nodes(Node *root){
    if (root == NULL || root->data == INT_MAX)
        return NULL;

    root->left = remove_null_nodes(root->left);
    root->right = remove_null_nodes(root->right);

    return root;
}

void PostOrderedTransversal(struct Node * root){
    if(root!=NULL){
        PostOrderedTransversal(root->left);
        PostOrderedTransversal(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    string line;
    struct Node * root;
    vector<int>array;
    while (cin>>line){
        if(line=="null") array.push_back(INT_MAX);
        else array.push_back(stoi(line));
    }
    root=bineryTreeFormation(0,array,array.size());
    root = remove_null_nodes(root);
    PostOrderedTransversal(root);
}