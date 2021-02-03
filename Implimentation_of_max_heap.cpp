/*
Authure-Rishabh Tripathi
Implimentation of max heap by recursion
*/
#include <iostream>
using namespace std;
typedef long long int rt;

void max_heapify(rt array[],rt index,rt heap_size){
    rt largest;
    rt left=2*index;
    rt right=2*index+1;
    if((left<heap_size)&&(array[left]>array[index])) {
        largest=left;
}
    else   largest=index;
    if((right<heap_size)&&(array[right]>array[largest])) {
        largest=right;
    }
    if(largest!=index){
        rt temp=array[index];
        array[index]=array[largest];
        array[largest]=temp;
        max_heapify(array,largest,heap_size);
    }
}

void build_max_heap(rt array[],rt size){
    rt iteration_start=(size/2) ;
    for(rt i=iteration_start;i>=1;--i) {
        max_heapify(array,i,size);
    }
}
int main() {
    rt array[]={1,2,3,4,5,6,7,8,9,10};
    rt size=sizeof(array)/sizeof(array[0]);
    build_max_heap(array,size);
    for(rt i=0;i<size;++i) cout<<array[i]<<" ";
    return 0;
}