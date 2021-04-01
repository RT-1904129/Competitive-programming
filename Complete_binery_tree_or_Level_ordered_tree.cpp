/*
recursive complete binery tree formation or leval order tree formation
*/
#include <iostream>
#include<cstdlib>
#include<queue> 
using namespace std;

struct bineryTree{
  int data;
  struct bineryTree *leftChild=NULL;
  struct bineryTree *rightChild=NULL;
};


bineryTree*complete_ bineryTreeFormation(int index,int array[],int arraySize){
    if(index<arraySize){
        bineryTree *node= new bineryTree;
        node->data=array[index];
        node->leftChild=complete_bineryTreeFormation(2*index+1,array,arraySize);
        node->rightChild=complete_bineryTreeFormation(2*index+2,array,arraySize);
        return node;
    }
    return NULL;
}


int main(){
    int array[]={1,2,3,4,5,6};
    struct bineryTree *root=complete_bineryTreeFormation(0,array,6);
    cout<<root->leftChild->rightChild->data;
    

}