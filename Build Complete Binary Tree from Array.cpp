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
        node->left=bineryTreeFormation(2*index+1,array,arraySize);
        node->right=bineryTreeFormation(2*index+2,array,arraySize);
        return node;
    }
    return NULL;
}

int getnumber(string str){
    int sum=0;
    for(int i=0;i<str.length();++i){
        sum=sum*10+(str[i]-'0');    
    }
    return sum;
}

int main()
{
    string line,number;
    int count=0;
    getline(cin,line);
    stringstream X(line);
    struct Node * root;
    vector<int>array;
    while (getline(X, number, ' ')) {
        array.push_back(getnumber(number));
    }
    root=bineryTreeFormation(0,array,array.size());
    PreOrderedTransversal(root);
    return 0;
}