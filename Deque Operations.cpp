#include<iostream>
#include<deque>
using namespace std;

typedef  long long int rt;

void Deque_Operations(rt array[],rt size_array,rt array3[],rt size_array3,rt max_value){
    rt one,second,start=0;
    deque<rt>array2;
    rt array1[max_value+1][2];
    array1[0][0]=0;
    array1[0][1]=0;
    for(rt i=0;i<size_array;++i) array2.push_back(array[i]);        //Deque Operations
    while(max_value--){
        start++;
        one=array2.front();
        array2.pop_front();
        second=array2.front();
        array2.pop_front();
        if(one>second) {array2.push_front(one);array2.push_back(second);}
        else {array2.push_front(second);array2.push_back(one);}
        array1[start][0]=array2[0];
        array1[start][1]=array2[1];
    }
    for(rt i=0;i<size_array3;++i){
        cout<<array1[array3[i]][0]<<" ";
        cout<<array1[array3[i]][1]<<"\n";           
    }
}

int main(){
    rt a,b,f,max=0;
    cin>>a>>b;
    rt array[a];
    rt array3[b];
    for(rt i=0;i<a;++i) cin>>array[i];
    for(rt i=0;i<b;++i){
        cin>>f;
        array3[i]=f;
        if(max<f) max=f;
    }
    Deque_Operations(array,a,array3,b,max);
}