/*
Recursive Approach for PreOrderedTransversal
*/
#include <iostream>
using namespace std;


struct bineryTree{
  int data;
  struct bineryTree * leftChild=NULL;
  struct bineryTree * rightChild=NULL;
};

void PreOrderedTransversal(bineryTree * root){
    if(root!=NULL){
        cout<<root->data;
        PreOrderedTransversal(root->leftChild);
        PreOrderedTransversal(root->rightChild);
    }
}

/*
iterative Approach for PreOrderedTransversal
*/

#include<iostream>
#include<stack>
using namespace std;

void PreOrderedTransversal(bineryTree* root){
    if(root!=NULL){
            stack<int>array;
            array.push(root);
            while(!array.empty()){
                root=array.top();
                array.pop();
                cout<<root->data;
                array.push(root->rightChild);
                array.push(root->leftChild);
            }
    }
}

/*
Recursive Approach InOrderedTransversal
*/
#include <iostream>
using namespace std;


struct bineryTree{
  int data;
  struct bineryTree * leftChild=NULL;
  struct bineryTree * rightChild=NULL;
};

void InOrderedTransversal(bineryTree * root){
    if(root!=NULL){
        InOrderedTransversal(root->leftChild);
        cout<<root->data;
        InOrderedTransversal(root->rightChild);
    }
}


/*
iterative  Approach InOrderedTransversal
*/
#include<iostream>
#include<stack>
using namespace std;

void InOrderedTransversal(bineryTree* root){
    stack<int>array;
    while((root!=NULL)||(!array.empty())){
        while(root!=NULL){
            array.push(root);
            root=root->leftChild;
        }
        root=array.top();
        array.pop();
        cout<<root->data;
        array.push(root->rightChild);
    }
}


/*
Recursive Approach PostOrderedTransversal
*/
#include <iostream>
using namespace std;


struct bineryTree{
  int data;
  struct bineryTree * leftChild=NULL;
  struct bineryTree * rightChild=NULL;
};

void PostOrderedTransversal(bineryTree * root){
    if(root!=NULL){
        PostOrderedTransversal(root->leftChild);
        PostOrderedTransversal(root->rightChild);
        cout<<root->data;
    }
}
    
/*
Iterative Approach PostOrderedTransversal
*/    
    
void PostOrderedTransversal(bineryTree *root){
    stack<int>array;
    array.push(root);
    while(!array.empty()){
        while(root!=NULL){
            array.push(root->rightChild);
            array.push(root);
            root=root->leftChild;
        }
        root=array->top();
        root->pop();
        if(root->rightChild==array.top()){
            array.pop();
            array.push(root);
            root=root->rightChild;
        }
        else{
            cout<<root->data;
            root=NULL;
        }
    }
}


/*
Iterative Approach LevalOrderedTransversal
*/ 
#include <iostream>
#include<queue> 
using namespace std;

void LevalOrderedTransversal(bineryTree *root){
    queue<int>array;
    array.push(root);
    while(!array.empty()){
        root=array.front()
        array.pop();
        cout<<root->data;
        array.push(root->leftChild);
        array.push(root->rightChild);
    }
}
    
 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}