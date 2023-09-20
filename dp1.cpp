int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return knapSackmain(W, wt, val, n, dp);
    }

    int knapSackmain(int W, int wt[], int val[], int n, vector<vector<int>>& dp)
    {
        if (n == 0 || W == 0)
        {
            return 0;
        }

        if (dp[n][W] != -1)
        {
            return dp[n][W];
        }

        if (wt[n - 1] > W)
        {
            dp[n][W] = knapSackmain(W, wt, val, n - 1, dp);
        }
        else
        {
            dp[n][W] = max(val[n - 1] + knapSackmain(W - wt[n - 1], wt, val, n - 1, dp),knapSackmain(W, wt, val, n - 1, dp));
        }

        return dp[n][W];
    }
