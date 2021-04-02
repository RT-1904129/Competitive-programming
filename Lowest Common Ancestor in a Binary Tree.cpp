#include <iostream>
#include <cstdlib>
#include <climits>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
} * root;

struct Node *create_node(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

struct Node *remove_null_nodes(struct Node *root)
{
    if (root == NULL || root->data == INT_MAX)
        return NULL;

    root->left = remove_null_nodes(root->left);
    root->right = remove_null_nodes(root->right);

    return root;
}

struct Node *insert_node(struct Node *root, int value, queue<struct Node *> &queue)
{
    struct Node *new_node = create_node(value);
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

void build_tree()
{
    string temp;
    queue<struct Node *> queue;
    while (cin >> temp)
    {
        if (temp == "null")
            root = insert_node(root, INT_MAX, queue);
        else
            root = insert_node(root, stoi(temp), queue);
    }
    root = remove_null_nodes(root);
}

int lowest_common_ancestor(struct Node *root, int M, int N, int &ans){
    if (root == NULL)
        return 0;
    int left = lowest_common_ancestor(root->left, M, N, ans) ? 1 : 0;
    int right = lowest_common_ancestor(root->right, M, N, ans) ? 1 : 0;
    int current = (root->data == M || root->data == N) ? 1 : 0;

    if (left + right + current >= 2)
        ans = root->data;

    return (left + right + current > 0);
}

int main()
{
    int M, N, ans;
    cin >> M >> N;
    build_tree();

    lowest_common_ancestor(root, M, N, ans);
    cout << ans;
    return 0;
}