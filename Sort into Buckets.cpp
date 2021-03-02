#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;
int bineray_check(ll a){
    int count=0;
    while(a){
        if(a%2==1) count++;
        a/=2;
    }
    return count;
}

void countingSort(ll array[], int size, ll place)
{
    ll max = 10, output[size], count[max];

    for (int i = 0; i < max; ++i)
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

void radixsort(ll array[], int size)
{
    ll max = *max_element(array, array + size);

    for (ll place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

int main(){
    int N;
    cin >> N;
    ll arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<ll>arr1[61];
    for (int j = 0; j < N; j++){
        arr1[bineray_check(arr[j])].push_back(arr[j]);
        }
    for(int j = 1; j < 61; j++){
        if(arr1[j].size()!=0){
            ll arr2[arr1[j].size()];
            for(int i=0;i<arr1[j].size();++i)  arr2[i]=arr1[j][i];
            radixsort(arr2, arr1[j].size());
            // sort(arr2,arr2+arr1[j].size());
            for(int i=0;i<arr1[j].size();++i)  cout<<arr2[i]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}