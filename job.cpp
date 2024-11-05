#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct jobStructure
{
    int jobId;
    int deadline;
    int profit;
};

int main()
{

    int n;
    cout << "how many jobs do u want? " << endl;
    cin >> n;
    vector<jobStructure> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i].jobId;
        cin >> inp[i].deadline;
        cin >> inp[i].profit;
    }

    sort(inp.begin(), inp.end(), [](jobStructure &a, jobStructure &b)
         { return a.profit > b.profit; });

    int maxiDeadline = 0;
    for (auto x : inp)
    {
        maxiDeadline = max(maxiDeadline, x.deadline);
    }

    vector<int> res(maxiDeadline, -1);

    int maxProfit = 0;
    for (auto x : inp)
    {
        int jid = x.jobId;
        int deadline = x.deadline;
        int profit = x.profit;

        for (int i = min(maxiDeadline, deadline) - 1; i >= 0; i--)
        {
            if (res[i] == -1)
            {
                maxProfit += profit;
                res[i] = jid;
                break;
            }
        }
    }

    cout << "Selected job IDs: ";
    for (int i = 0; i < maxiDeadline; i++)
    {
        if (res[i] != -1)
        {
            cout << res[i] << " ";
        }
    }
    cout << "\nMaximum profit: " << maxProfit << endl;

    return 0;
}