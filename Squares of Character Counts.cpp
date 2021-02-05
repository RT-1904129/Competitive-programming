#include <iostream>
#include <queue>
using namespace std;

long long int min_sum(string str, int k){
    int len = str.length();
    // Find Frequency of every character
    int char_frequency[26] = {0};
    for (int i = 0; i < len; i++)
        char_frequency[str[i] - 'a']++;
        
    // Push frequency of every character in S.
    priority_queue<int> queue;
    for (int i = 0; i < 26; i++)
        if (char_frequency[i] > 0)
            queue.push(char_frequency[i]);

    /* We get top element from priority_queue and decrement its frequency count 
	        and again push it back */
    while(k--){
        int temp = queue.top();
        queue.pop();
        temp = temp - 1;
        queue.push(temp);
    }

    // Find sum
    long long int result = 0;
    while (!queue.empty()){
        int val = queue.top();
        queue.pop();
        result += val * val;
    }
    return result;
}

int main(){
    string S;
    int K;
    cin >> S;
    cin >> K;
    cout << min_sum(S, K);
    return 0;
}