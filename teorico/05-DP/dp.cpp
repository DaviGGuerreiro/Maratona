#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int t = 1e5;

int lis(){
    int answer = 0;
    vector<int> dp(t);
    for (int j = 0; j < t; ++j) {
        dp[j] = 1;
        for (int i = j - 1; i >= 0; --i) {
            if (a[i] < a[j]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        answer = max(answer, dp[j]);
    }
    return answer;
}

string a, b;
vector<vector<int>> dyp;

int best(int i, int j){
    if (i < 0 or j < 0) return 0;
    if (dyp[i][j] != -1) return dyp[i][j];

    dyp[i][j] = 0;
    if (a[i] == b[j]) {
        dyp[i][j] = 1 + best(i - 1, j - 1);
    } else {
        dyp[i][j] = max(best(i - 1, j), best(i, j - 1));
    }
    return dyp[i][j];
}

int lcs(){
    int n, m;
    cin>>a; cin>>n;
    cin>>b; cin>>m;
    dyp = vector<vector<int>> (n,vector<int>(m,-1));
    return best(n-1, m-1);
}

bool subsetSum() {
    int t = 1;
    vector<int> a = {3, 4, 7, 2};
    vector<bool> dp(t + 1);
    dp[0] = true;
    for (int x : a) {
        for (int i = t - x; i >= 0; --i) {
            if (dp[i]) {
                dp[i + x] = true;
            }
        }
    }
    return dp[t];
}

int knap() {
    int n = 4, W = 7;
    vector<int> w = {3, 4, 2, 6};
    vector<int> v = {4, 5, 3, 7};
    vector<int> knapsack(W + 1);
    for (int i = 0; i < n; ++i) {
        for (int k = W - w[i]; k >= 0; --k) {
            knapsack[k + w[i]] = max(knapsack[k + w[i]], knapsack[k] + v[i]);
        }
    }
    return knapsack[W];
}