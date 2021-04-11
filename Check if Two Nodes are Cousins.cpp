#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct position{
    int value;
    int level;
    Node*parent;
};

struct Node *create_node(int data){
    struct Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

struct Node* insert(struct Node* root,struct Node*node){
    if(root==NULL){
        root = node;
    }
    else if(root->data>node->data){
        root->left = insert(root->left,node);
    }
    else if(root->data<=node->data){
        root->right = insert(root->right,node);
    }
    return root;
}

void inorder(Node *root, Node *parent, int level, position &x, position &y){
    if (root == NULL)
        return;
    inorder(root->left, root, level + 1, x, y);
    if (root->data == x.value){
        x.level = level;
        x.parent = parent;
    }
    else if (root->data == y.value){
        y.level = level;
        y.parent = parent;
    }
    inorder(root->right, root, level + 1, x, y);
}

int check_cousins(Node *root, int m, int n){
    position x = {m, 1, NULL};
    position y = {n, 1, NULL};
    inorder(root, NULL, 1, x, y);

    if ((x.level == y.level) && (x.parent != y.parent))
        return 1;
    return 0;
}

void delete_tree(Node *root){
    if (root == NULL)
        return;
    delete_tree(root->right);
    delete_tree(root->left);
    delete root;
}

int main(){
    int a,b,c;
    cin>>a;
    while(a--){
        cin>>b>>c;
        string n;
        vector<int>v;
        while(cin>>n){
            if(n=="-1") break;
            if(n=="null"){
                continue;
            }
            else{
                v.push_back(stoi(n));
            }
        }
        struct Node*root = NULL;
        for(int i=0;i<v.size();i++){
            struct Node* node = create_node(v[i]);
            root = insert(root,node);
        }
        cout<<check_cousins(root,b,c)<<"\n";
        delete_tree(root); 
    }
    return 0;
}