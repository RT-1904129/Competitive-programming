/*
Auther:-Rishabh Tripathi
Quick Sort algorithim
Lomoto Parition Scheme Algorithim
*/
#include <iostream>
using namespace std;

typedef long long int rt;
rt Pivot_giving_function(rt array[],rt low,rt high){
    rt i=low-1,temp;
    rt pivat=array[high];
    for(rt j=low;j<=(high-1);j++){
        if(array[j]<=pivat){
            i++;
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }
    temp=array[i+1];
    array[i+1]=pivat;
    array[high]=temp;
    return(i+1);
}

void quickSort(rt array[],rt low,rt high){
    if(low<high){
        rt pivat=Pivot_giving_function(array,low,high);
        quickSort(array,low,pivat-1);
        quickSort(array,pivat+1,high);
    }
}
int main(){
    rt array[]={4,5,2,1,7,8,9,2,6};
    rt size=sizeof(array)/sizeof(rt);
    quickSort(array,0,size-1);
    for(rt i=0;i<9;++i) cout<<array[i]<<" ";
    return 0;
}