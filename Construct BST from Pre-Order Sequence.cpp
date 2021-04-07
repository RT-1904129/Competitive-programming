#include <bits/stdc++.h>
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
    if(root!=NULL){
        postorder_traverse(root->left);
        postorder_traverse(root->right);
        cout<<root->data<<' ';
    }
    return;
}

struct Node* insert(struct Node* root,struct Node*node){
    if(root==NULL){
        root = node;
    }
    else if(root->data>node->data){
        root->left = insert(root->left,node);
    }
    else if(root->data<=node->data){
        root->right = insert(root->right,node);
    }
    return root;
    
}

int main()
{
    string n;
    vector<int>v;
    while(cin>>n){
        if (n=="null"){
            continue;
        }
        else{
            v.push_back(stoi(n));
        }
    }
    
    struct Node*root = NULL;
    for(int i=0;i<v.size();i++){
        struct Node* node = create_node(v[i]);
        root = insert(root,node);
    }
    
    postorder_traverse(root);
    return 0;
}