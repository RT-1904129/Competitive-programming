/*
Authure-Rishabh Tripathi
Implimentation of heap Sort by recursion
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
        array[index]=array[largest];        //swapping
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

void heap_sort(rt array[],rt size){
    build_max_heap(array,size);
    rt temp;
    for(rt i=size-1;i>1;--i){
        temp=array[i];
        array[i]=array[1];      //swapping
        array[1]=temp;
        max_heapify(array,1,i);
    }
}
int main() {
    rt array[]={0,2,3,4,5,6,7,8,9,10,1,23,78};
    rt size=sizeof(array)/sizeof(array[0]);
    heap_sort(array,size);
    for(rt i=0;i<size;++i) cout<<array[i]<<" ";
    return 0;
}