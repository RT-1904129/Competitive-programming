// C++ program to sort an 
// array using bucket sort
#include <algorithm>
#include <iostream>
#include<cmath>
#include <vector>
using namespace std;
typedef long long int rt;
// Function to sort arr[] of 
// size n using bucket sort
void bucketSort(float arr[], rt n,rt bucket_size){
    
	float maxi_element=*(max_element(arr,arr+n*sizeof(float)));
	float mini_element=*(min_element(arr,arr+n*sizeof(float)));
	float range=(maxi_element-mini_element)/bucket_size;
	
	// 1) Create n empty buckets
	vector<float> b[bucket_size];

	// 2) Put array elements 
	// in different buckets
	for (rt i = 0; i < n; i++) {
		rt bi = (arr[i]-mini_element)/range; // Index in bucket
		b[bi].push_back(arr[i]);
	}

	// 3) Sort individual buckets
	for (rt i = 0; i < bucket_size; i++)
		sort(b[i].begin(), b[i].end());

	// 4) Concatenate all buckets into arr[]
	rt index = 0;
	for (rt i = 0; i < bucket_size; i++)
		for (rt j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

/* Driver program to test above function */
int main()
{
	float arr[]= { 9.8 , 0.6 , 10.1 , 1.9 , 3.07 , 3.04 , 5.0 , 8.0 , 4.8 , 7.68 };
	rt n = sizeof(arr) / sizeof(arr[0]);
	
	bucketSort(arr, n,5);

	cout << "Sorted array is \n";
	for (rt i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}