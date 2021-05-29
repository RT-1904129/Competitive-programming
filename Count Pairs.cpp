#include <iostream> 
#include <vector>
typedef long long ll;
using namespace std; 
  

ll merge(ll A[], ll temp[], int left, int mid, int right) 
{ 
    ll inversions = 0; 
  
    int i = left, j = mid, k = left; 
    while ((i <= mid - 1) && (j <= right)) 
    { 
        if (A[i] <= A[j]) 
            temp[k++] = A[i++]; 
        else
        { 
            temp[k++] = A[j++]; 
  
            inversions += (mid - i); 
        } 
    } 

    while (i <= mid - 1) 
        temp[k++] = A[i++]; 
  
    while (j <= right) 
        temp[k++] = A[j++]; 
  
    for (i=left; i <= right; i++) 
        A[i] = temp[i]; 
  
    return inversions; 
} 

ll mergeSort(ll A[], ll temp[], int left, int right) 
{ 
    int mid;
    ll mergeInv = 0, leftInv = 0, rightInv = 0, total = 0;
    if (right > left) 
    { 

        mid = (right + left)/2; 

        leftInv  = mergeSort(A, temp, left, mid); 
        rightInv = mergeSort(A, temp, mid+1, right); 
        mergeInv = merge(A, temp, left, mid+1, right); 
    } 
    total = leftInv + rightInv + mergeInv;
    return total; 
} 

ll countPairs(ll A[], int n) 
{ 

    for (int i=0; i<n; i++) 
        A[i] = i*A[i]; 

    ll temp[n]; 
    return mergeSort(A, temp, 0, n - 1); 
} 
  

int main() 
{   int n; 
    cin>>n;
    ll A[n];
    for(int i=0; i<n; i++) 
    {
        cin>>A[i];
    }
    
    cout<< countPairs(A,n); 
    return 0; 
}