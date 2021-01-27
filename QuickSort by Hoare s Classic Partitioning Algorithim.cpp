/*
Auther:-Rishabh Tripathi
Quick Sort algorithim
Hoare's Classic Partitioning Algorithim
*/
#include <iostream>
using namespace std;

typedef long long int rt;
rt Pivot_giving_function(rt array[],rt low,rt high){
    rt pivat=array[low];
    rt i=low-1;
    rt j=high+1;
    while(true){
        do{
            j--;
        }while(array[j]>pivat);
        do{
            i++;
        }while(array[i]<pivat);
        if(i<j){
            rt temp=array[j];
            array[j]=array[i];
            array[i]=temp;
        }
        else return j;
    }
}

void QuickSort(rt array[],rt low,rt high){
    if(low<high){
        rt pivat=Pivot_giving_function(array,low,high);
        QuickSort(array,low,pivat);
        QuickSort(array,pivat+1,high);
    }
}

int main(){
    rt array[]={4,5,2,1,7,8,9,2,6};
    rt size=sizeof(array)/sizeof(rt);
    QuickSort(array,0,size-1);
    for(rt i=0;i<9;++i) cout<<array[i]<<" ";
    return 0;
}