/*
Authure-Rishabh Tripathi
extraxt maximum from max heap
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

rt extrac_mxa(rt array[],rt heap_size){
    rt max=array[1];
    array[1]=array[heap_size-1];
    heap_size=heap_size-1;
    max_heapify(array,1,heap_size);
    return max;
}
int main() {
    rt array[]={1,2,3,4,5,6,7,8,9,10};
    rt size=sizeof(array)/sizeof(array[0]);
    build_max_heap(array,size);
    for(rt i=0;i<size;++i) cout<<array[i]<<" ";
    rt max=extrac_mxa(array,size);
    cout<<"\n Extract_max--"<<max<<'\n';
    for(rt i=0;i<size-1;++i) cout<<array[i]<<" ";
    return 0;
}