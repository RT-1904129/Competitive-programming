#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

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

Node *insert_node(Node *root, int value, queue<Node *> &queue){
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

Node* build_tree(){
    string temp;
    queue<Node *> queue;
    Node*root=NULL;
    while (cin >> temp){
        if(temp=="-1") break;
        if (temp == "null")
            root = insert_node(root, INT_MAX, queue);
        else
            root = insert_node(root, stoi(temp), queue);
    }
    root = remove_null_nodes(root);
    return root;
}
bool isBST(Node* node,int min,int max){
    if(node==NULL)
        return 1;
    if((node->data<min)||(node->data>max))
        return 0;
    return (isBST(node->left,min,node->data-1)&&isBST(node->right,node->data+1,max)) ;
}

int main(){
    int a;
    cin>>a;
    while(a--){
        Node* root=build_tree();
        cout<<isBST(root,INT_MIN,INT_MAX)<<"\n";
    }
    return 0;
}