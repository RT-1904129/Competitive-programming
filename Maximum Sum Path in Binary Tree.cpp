#include<iostream>
#include<climits>
#include <queue>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
} * root;

Node *create_node(int data){
    Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

Node *remove_null_nodes(Node *root){
    if (root == NULL || root->data == INT_MAX)
        return NULL;
    root->left = remove_null_nodes(root->left);
    root->right = remove_null_nodes(root->right);
    return root;
}

Node *insert_node(Node *root, int value, queue<Node *> &queue)
{
    Node *new_node = create_node(value);
    if (root == NULL)
        root = new_node;
    else if (queue.front()->left == NULL)
        queue.front()->left = new_node;
    else
    {
        queue.front()->right = new_node;
        queue.pop();
    }

    if (value != INT_MAX)
        queue.push(new_node);
    return root;
}

void build_tree(){
    string temp;
    queue<Node *> queue;
    while (cin >> temp){
        if (temp == "null")
            root = insert_node(root, INT_MAX, queue);
        else
            root = insert_node(root, stoi(temp), queue);
    }
    root = remove_null_nodes(root);
}

int max_sum(Node* root,int &length){
    int length1=0,length2=0;
    if(root==NULL) return 0;
    length1=max_sum(root->left,length);
    length2=max_sum(root->right,length);
    length=max(length,length1+length2+root->data);
    length=max(length,root->data+length2);
    length=max(length,root->data+length1);
    return root->data+max(length2,length1);
}

int main(){
    build_tree();
    int length=INT_MIN;
    max_sum(root,length);
    cout<<length;
    return 0;

}