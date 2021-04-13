#include <iostream>
#include<climits>
#include <vector>
using namespace std;

struct Node{
    int data, height;
    Node *left, *right;
} * root;

Node *get_new_node(int &data){
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int get_height(Node *node){
    if (node == NULL)
        return 0;
    return node->height;
}

Node *rightRotate(Node *node){
    Node *pivot = node->left;
    Node *temp = pivot->right;
    pivot->right = node;
    node->left = temp;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    pivot->height = max(get_height(pivot->left), get_height(pivot->right)) + 1;
    return pivot;
}

Node *leftRotate(Node *node){
    Node *pivot = node->right;
    Node *temp = pivot->left;
    pivot->left = node;
    node->right = temp;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    pivot->height = max(get_height(pivot->left), get_height(pivot->right)) + 1;
    return pivot;
}

int get_balance_factor(Node *node){
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

Node *insert(Node *node, int data){
    if (node == NULL)
        return (get_new_node(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(get_height(node->left), get_height(node->right));
    int balanceFactor = get_balance_factor(node);

    if (balanceFactor > 1)
    {
        if (data < node->left->data)
            return rightRotate(node);

        else if (data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balanceFactor < -1)
    {
        if (data > node->right->data)
            return leftRotate(node);

        else if (data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

void build_tree(){
    string temp;
    while (cin >> temp){
        if(temp== "null") continue;
        else
            root = insert(root, stoi(temp));
    }
    return;
}


Node *deleteNode(Node *root, int &key){
    if (root == NULL)
        return root;

    if (key < root->data)
       root->left=deleteNode(root->left, key);
    else if (key > root->data)
        root->right=deleteNode(root->right, key);
    
    else{
        // Case 1: node to be deleted is a leaf node
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        // Case 2: node to be deleted has two children
        else if (root->left && root->right)
        {
            // find its in-order successor node
            Node *successor = root->right;
            while (successor->left != NULL)
                successor = successor->left;

            root->data = successor->data;

            // recursively delete the successor.
            root->right=deleteNode(root->right, successor->data);
        }

        // Case 3: node to be deleted has only one child
        else
        {
            Node *child = (root->left) ? root->left : root->right;
            Node *node_to_delete = root;

            root = child;
            delete node_to_delete;
        }
    }
    if(root==NULL) 
        return root;
        
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    int balanceFactor = get_balance_factor(root);

    if (balanceFactor > 1){
        if (get_balance_factor(root->left) >= 0){
            return rightRotate(root);
        }
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (balanceFactor < -1){
        if (get_balance_factor(root->right) <= 0){
            return leftRotate(root);
        }
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

void postorder_traversal(Node *node){
    if (node == NULL)
        return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout << node->data << " ";
    return;
}

int main(){
    int a;
    cin>>a;
    build_tree();
    root=deleteNode(root,a);
    postorder_traversal(root);
    return 0;
}