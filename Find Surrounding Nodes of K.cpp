#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
} * root;

struct position{
    int value;
    Node* right;
    Node*left;
    Node*parent;
};

Node *get_new_node(int &data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int get_height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

Node *rightRotate(Node *node)
{
    Node *pivot = node->left;
    Node *temp = pivot->right;
    pivot->right = node;
    node->left = temp;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    pivot->height = max(get_height(pivot->left), get_height(pivot->right)) + 1;
    return pivot;
}

Node *leftRotate(Node *node)
{
    Node *pivot = node->right;
    Node *temp = pivot->left;
    pivot->left = node;
    node->right = temp;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    pivot->height = max(get_height(pivot->left), get_height(pivot->right)) + 1;
    return pivot;
}

int get_balance_factor(Node *node)
{
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

Node *insert(Node *node, int data)
{
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

void inorder(Node *root, Node *parent ,position &x){
    if (root == NULL)
        return;
    inorder(root->left, root, x);
    if (root->data == x.value){
        x.left=root->left;
        x.right=root->right;
        x.parent = parent;
        return;
    }
    inorder(root->right, root, x);
}

void check_parent_child(Node *root, int m){
    position x = {m,NULL,NULL, NULL};
    inorder(root, NULL, x);
    // cout<<(1==0)? 2 :-1;
    cout<<((x.parent==NULL)? -1:x.parent->data);
    cout<<" "<<((x.left==NULL)? -1:x.left->data);
    cout<<" "<<((x.right==NULL)? -1:x.right->data);

}

void delete_tree(Node *root){
    if (root == NULL)
        return;
    delete_tree(root->right);
    delete_tree(root->left);
    delete root;
}

void build_tree()
{
    int temp;
    while (cin >> temp)
        root = insert(root, temp);

    return;
}

int main(){
    int serach_number;
    cin>>serach_number;
    build_tree();
    check_parent_child(root,serach_number);
    delete_tree(root);
    return 0;
}