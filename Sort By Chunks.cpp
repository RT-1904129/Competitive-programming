#include <iostream>
#include<cmath>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

void countingSort(ll array[], int size, ll place)
{
    ll max = 10, output[size], count[max];

    for (int i = 0; i < max; i++)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
        output[--count[(array[i] / place) % 10]] = array[i];

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixsort(ll array[], int size,ll start,ll end){
    //ll max = *max_element(array, array + size);

    for (ll place = start;  place < end; place *= 10)
        countingSort(array, size, place);
}

int main(){
    int N,count=0;
    cin >> N;
    ll array[N];
    for(int i = 0; i < N; i++)  {
        cin >> array[i];
        
    }
    ll max = *max_element(array, array + N);
    while(max){
        count++;
        max/=10;
    }
    int j=0;
    while(count>0){
        ll arr[N];
        for(int i = 0; i < N; i++) arr[i]=array[i];
        radixsort(arr, N,pow(10,3*j),pow(10,3+3*j));
        for(int i = 0; i < N; i++)  cout << arr[i] << " ";
        count-=3;
        j++;
        cout<<"\n";
    }
    return 0;
}