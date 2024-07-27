#include <iostream>
using namespace std;

int solve(long long nStairs, int dp[])
{
    if (nStairs <= 1)
    {
        return dp[nStairs] = 1;
    }

    if (dp[nStairs] != -1)
    {
        return dp[nStairs];
    }

    dp[nStairs] = solve(nStairs - 1, dp) + solve(nStairs - 2, dp);
    return dp[nStairs];
}

int main()
{
    int n = 4;
    int dp[n + 1];
    memset(dp, -1, sizeof dp);
    cout << "Number of ways = " << solve(n, dp);
    return 0;
}