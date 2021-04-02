#include<iostream>
#include<climits>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
} * root;

Node *create_node(int data)
{
    Node *node = new Node;
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

void get_left_side_view(struct Node *root, int level, vector<int> &left_side_view)
{
    if (root == NULL)
        return;

    if (level == left_side_view.size())
        left_side_view.push_back(root->data);

    get_left_side_view(root->left, level + 1, left_side_view);
    get_left_side_view(root->right, level + 1,left_side_view);

    return;
}

vector<int> get_left_side_view(struct Node *root)
{
    vector<int> left_side_view;
    get_left_side_view(root, 0, left_side_view);

    return left_side_view;
}

int main()
{
    build_tree();
    vector<int> result = get_left_side_view(root);
    // for (auto i : result)
    cout << result[result.size()-1] << " ";
    return 0;
}