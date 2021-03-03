/*
Auther:-Rishabh Tripathi
RandomizedSelection of Kth smallest element from set of n distinct element
*/
#include <iostream>
#include <cstdlib> 
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

rt RadomizePartition(rt array[],rt low,rt high){
    srand(time(NULL));      //initialize random seed
    rt index=rand()%(high-low)+low; //choose random index
    rt temp=array[high];        //swapping them to make avoid wrost case scinerio
    array[high]=array[index];
    array[index]=temp;
    return Pivot_giving_function(array,low,high);
}

rt RandomizedSelection(rt array[],rt low,rt high,rt K_value){
    if(low==high) return array[low];
    //cout<<"ram";
    
    rt pivat=RadomizePartition(array,low,high);
    rt k=pivat-low+1;
    if(k==K_value) return array[pivat];
    else if(K_value<k){
       return RandomizedSelection(array,low,pivat-1,K_value);
    }
    else {
       return RandomizedSelection(array,pivat+1,high,K_value-k);
    }
}

int main(){
    rt array[]={1,2,2,2,2,2,2,2,2,3,4,5,6,7,8,9,10};
    rt size=sizeof(array)/sizeof(rt);
    cout<<"3rd smallest elementof given array  "<<RandomizedSelection(array,0,size-1,5);
    return 0;
}