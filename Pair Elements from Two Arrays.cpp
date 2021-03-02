#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

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
    int N,M,a,count=0;
    cin>>a;
    for(int i=0;i<a;++i){
        cin>>N>>M;
        ll array[N],array1[M];
        for (int j = 0; j < N; j++)  cin >> array[j];
        for (int j = 0; j < M; j++)  cin >> array1[j];
        if(N<=M){
           
            radixsort(array, N);
            radixsort(array1, M);
            for (int j = 0; j < N; j++){
                if(array[j]<=array1[j]){
                    cout<<0<<"\n";
                    count=1;
                    break;
                }
            }
            if(count==0) cout<<1<<"\n";
            count=0;
        }
        else cout<<0<<"\n";
    }
    return 0;
}