/*
Authure-Rishabh Tripathi
Implimentation of min heap by recursion and Check for Min Heap
*/

#include <iostream>
using namespace std;
typedef long long int rt;

void min_heapify(rt array[],rt index,rt heap_size){
    rt smallest;
    rt left=2*index;
    rt right=2*index+1;
    if((left<heap_size)&&(array[left]<array[index])) {
        smallest=left;
}
    else   smallest=index;
    if((right<heap_size)&&(array[right]<array[smallest])) {
        smallest=right;
    }
    if(smallest!=index){
        rt temp=array[index];
        array[index]=array[smallest];
        array[smallest]=temp;
        min_heapify(array,smallest,heap_size);
    }
}

void build_min_heap(rt array[],rt size){
    rt iteration_start=(size/2) ;
    for(rt i=iteration_start;i>=1;--i) {
        min_heapify(array,i,size);
    }
}
int main() {
    rt a;
    cin>>a;
    rt array[a+1],array1[a+1];
    array1[0]=0;array[0]=0;
    for(rt i=1;i<a+1;++i) {cin>>array[i];array1[i]=array[i];}
    build_min_heap(array,a+1);
    for(rt i=0;i<a+1;++i) {
        if(array[i]!=array1[i]) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}