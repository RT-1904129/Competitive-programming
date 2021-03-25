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

struct Node* bineryTreeFormation(int index,vector<int>&array,int arraySize){
    if(index<arraySize){
        Node *node= create_node(array[index]);
        node->left=bineryTreeFormation(2*index+1,array,arraySize);
        node->right=bineryTreeFormation(2*index+2,array,arraySize);
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

bool check_full_binary_tree(Node *root){
    if (root == NULL)
        return true;

    // Check if root is a leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // If root has both the children
    if ((root->left) && (root->right))
        return (check_full_binary_tree(root->left) && check_full_binary_tree(root->right));

    return false;
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
    check_full_binary_tree(root) ? cout << "True" : cout << "False";
}