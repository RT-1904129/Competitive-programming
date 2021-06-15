#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double average(vector<int> students)
{
    double avg = 0;
    for (int i = 0; i < students.size(); i++)
    {
        avg += students[i];
    }
    avg /= students.size();
    return avg;
}

double sums(vector<int> students)
{
    double total = 0;
    for (int i = 0; i < students.size(); i++)
    {
        total += students[i];
    }

    return total;
}

int main()
{
    double new_avg;
    int no_of_students, avg;
    cin >> no_of_students >> avg;
    vector<int> students(no_of_students);
    for (int i = 0; i < no_of_students; i++)
    {
        cin >> students[i];
    }

    new_avg = average(students);
    if (avg == 100 && new_avg != avg)
        cout << -1;
    else{
        double total = sums(students);
        int result = 0;
        while (total / students.size() < avg ){
            total += 100;
            students.push_back(100);
            result++;
        }
        cout << result;
    }
    return 0;
}