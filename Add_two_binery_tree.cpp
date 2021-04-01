#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
} *root1 = NULL, *root2 = NULL;

struct Node *create_node(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

Node *remove_null_nodes(Node *root)
{
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

void build_tree(struct Node **root)
{
    string temp;
    queue<Node *> queue;
    while (1)
    {
        cin >> temp;
        if (temp == "-1")
            break;

        if (temp == "null")
            *root = insert_node(*root, INT_MAX, queue);
        else
            *root = insert_node(*root, stoi(temp), queue);
    }
    *root = remove_null_nodes(*root);
    return;
}

struct Node *merge_trees(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;
    root1->data += root2->data;
    root1->left = merge_trees(root1->left, root2->left);
    root1->right = merge_trees(root1->right, root2->right);
    return root1;
}

void inorder_traversal(struct Node *node)
{
    if (node == NULL)
        return;

    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
}

int main()
{
    build_tree(&root1);
    build_tree(&root2);

    merge_trees(root1, root2);
    inorder_traversal(root1);
    return 0;
}