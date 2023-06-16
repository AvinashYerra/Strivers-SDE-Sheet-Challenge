#include <bits/stdc++.h>
int help(int ind, int w, vector<int> &values, vector<int> &weights, int n,
         vector<vector<int>> &dp) {
  if (ind == 0) {
    if (weights[0] <= w) {
      return values[0];
    }
    return 0;
  }
  if (dp[ind][w] != -1)
    return dp[ind][w];
  int npick = help(ind - 1, w, values, weights, n, dp);
  int pick = INT_MIN;
  if (weights[ind] <= w) {
    pick =
        values[ind] + help(ind - 1, w - weights[ind], values, weights, n, dp);
  }
  return dp[ind][w] = max(pick, npick);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
  // Write your code here
  vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
  return help(n - 1, w, values, weights, n, dp);
}