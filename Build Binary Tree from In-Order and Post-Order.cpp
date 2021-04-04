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

struct Node *create_node(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

Node *build_tree(int start, int end, vector<int> const &post_order, int &post_ind, unordered_map<int, int> &map){
    // base case
    if (start > end)
        return nullptr;
    
    // The next element in post_order[] will be the root node of subtree
    Node *root = create_node(post_order[post_ind--]);
    
    // get the index of root node in in_order to determine the left and right subtree
    int index = map[root->data];
    // recursively construct the right subtree
    root->right = build_tree(index + 1, end, post_order, post_ind, map);
    // recursively construct the left subtree
    root->left = build_tree(start, index - 1, post_order, post_ind, map);

    // return current node
    return root;
}

void build_tree(vector<int> const &in_order, vector<int> const &post_order){
    int len = in_order.size();

    // create a map to efficiently find the index of an element in in_order sequence
    unordered_map<int, int> map;
    for (int i = 0; i < len; i++)
        map[in_order[i]] = i;

    // stores index of  pre_order sequence
    int post_index = len-1;

    root = build_tree(0, len - 1, post_order, post_index, map);
}

void pre_order_traversal(struct Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
    
}

int main(){
    int temp;
    vector<int> in_order;
    vector<int> post_order;

    while (1){
        cin >> temp;
        if (temp == -1)
            break;
        in_order.push_back(temp);
    }
    
    while (1){
        cin >> temp;
        if (temp == -1)
            break;
        post_order.push_back(temp);
    }

    build_tree(in_order, post_order);
    pre_order_traversal(root);
    return 0;
}