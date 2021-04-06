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


int get_min(struct Node *root) {
    if(root->left==NULL){
        return root->data;
    }
    return get_min(root->left);
}


int get_max(struct Node *root) {
    if(root->right==NULL){
        return root->data;
    }
    return get_max(root->right);
}


void preorder_traverse(Node *root) {
    if(root!=NULL){
        cout<<root->data<<' ';
        preorder_traverse(root->left);
        preorder_traverse(root->right);
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
    int max = get_max(root);
    int min = get_min(root);
    cout<<min<<' '<<max<<"\n";
    preorder_traverse(root);
    return 0;
}