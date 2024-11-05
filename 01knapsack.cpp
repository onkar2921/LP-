#include <iostream>
#include <vector>

using namespace std;

int help(int index,vector<int>&wei,vector<int>&val,int cap,int n,vector<vector<int>>&dp){
    if(index==n)return 0;
    if(dp[index][cap]!=-1)return dp[index][cap];
    int t=0;
    if(cap-wei[index]>=0){
        t=val[index]+help(index+1,wei,val,cap-wei[index],n,dp);
    }

    int nt=help(index+1,wei,val,cap,n,dp);

    return dp[index][cap]=max(t,nt);
}




int knapsack(int cap, vector<int> &weights, vector<int> &values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1,0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= cap; w++) {
           int t=0;
            if (weights[i - 1] <= w)
               t=values[i-1]+dp[i-1][w-1];
            int nt=dp[i-1][w-1];

            dp[i][w]=max(t,nt);
            
        }
    }

    return dp[n][cap];
}

int main() {
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;

    vector<int> weights(n), values(n);
    cout << "Enter weights and values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    int maxValue = knapsack(W, weights, values, n);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
