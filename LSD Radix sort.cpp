#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

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
    ll array[N];
    for (int i = 0; i < N; i++)
        cin >> array[i];

    radixsort(array, N);
    for (int i = 0; i < N; i++)
        cout << array[i] << " ";
    return 0;
}