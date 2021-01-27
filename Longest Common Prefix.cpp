#include <iostream>
#include <string>
using namespace std;

string common_prefix_of_two_strings(string str1, string str2)
{
	string common_prefix = "";
	int len1 = str1.length(), len2 = str2.length();

	for (int i = 0, j = 0; i <= len1 - 1 && j <= len2 - 1; i++, j++)
	{
		if (str1[i] != str2[j])
			break;
		common_prefix+=str1[i];
	}

	return common_prefix;
}

string get_longest_common_prefix(string arr[], int low, int high)
{
	if (low == high)
	{
		return (arr[low]);
	}
	if (high > low)
	{
		// Avoids overflow for large low and high values, but same as (low + high)/2.
		int mid = (low + high) / 2;

		string str1 = get_longest_common_prefix(arr, low, mid);
		string str2 = get_longest_common_prefix(arr, mid + 1, high);

		return common_prefix_of_two_strings(str1, str2);
	}
}

int main()
{
	int n;
	cin >> n;
	string arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	string longest_prefix = get_longest_common_prefix(arr, 0, n - 1);

	if (longest_prefix.length())
		cout << longest_prefix;
	else
		cout << -1;

	return 0;
}