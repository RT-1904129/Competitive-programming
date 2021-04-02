#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
} * root;

struct Node *create_node(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

Node *build_tree(int start, int end, vector<int> const &pre_order, int &pre_ind, unordered_map<int, int> &map)
{
    // base case
    if (start > end)
        return nullptr;

    // The next element in pre_order[] will be the root node of subtree
    Node *root = create_node(pre_order[pre_ind++]);

    // get the index of root node in in_order to determine the left and right subtree
    int index = map[root->data];

    // recursively construct the left subtree
    root->left = build_tree(start, index - 1, pre_order, pre_ind, map);

    // recursively construct the right subtree
    root->right = build_tree(index + 1, end, pre_order, pre_ind, map);

    // return current node
    return root;
}

void build_tree(vector<int> const &in_order, vector<int> const &pre_order)
{
    int len = in_order.size();

    // create a map to efficiently find the index of an element in in_order sequence
    unordered_map<int, int> map;
    for (int i = 0; i < len; i++)
        map[in_order[i]] = i;

    // stores index of next unprocessed node in pre_order sequence
    int pre_index = 0;

    root = build_tree(0, len - 1, pre_order, pre_index, map);
}

void post_order_traversal(struct Node *node)
{
    if (node == NULL)
        return;

    post_order_traversal(node->left);
    post_order_traversal(node->right);
    cout << node->data << " ";
}

int main()
{
    int temp;
    vector<int> in_order;
    vector<int> pre_order;

    while (1)
    {
        cin >> temp;
        if (temp == -1)
            break;
        pre_order.push_back(temp);
    }
    while (1)
    {
        cin >> temp;
        if (temp == -1)
            break;
        in_order.push_back(temp);
    }

    build_tree(in_order, pre_order);
    post_order_traversal(root);
    return 0;
}