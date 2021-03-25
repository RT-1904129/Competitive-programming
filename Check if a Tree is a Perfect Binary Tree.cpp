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

int get_depth(struct Node *node){
    int d = 0;
    while (node != NULL){
        d++;
        node = node->left;
    }
    return d;
}

bool check_perfect_binary_tree(Node *root,int level,int depth){
    if (root == NULL)
        return true;

    // Check if root is a leaf node
    if (root->left == NULL && root->right == NULL)
        return (level + 1 == depth);

    // If root has both the children
    if ((root->left==NULL) || (root->right==NULL)) return false;
    
    return (check_perfect_binary_tree(root->left,level+1,depth) && check_perfect_binary_tree(root->right,level+1,depth));

}

bool check_perfect_binary_tree(struct Node *node){
    int depth = get_depth(node);
    return check_perfect_binary_tree(node, 0, depth);
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
    check_perfect_binary_tree(root) ? cout << "True" : cout << "False";
}