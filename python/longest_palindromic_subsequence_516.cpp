class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n <= 1) return n;
        vector<int> dp(n,1), dp_previous(n,0);
        for (int k = 1; k < n; k++){
            for (int i = 0; i < n-k; i++){
                dp_previous[i] = dp[i];
                dp[i] = max(dp[i], dp[i+1]);
                if (s[i] == s[i+k])
                    dp[i] = max(dp[i], 2 + dp_previous[i+1]);
            }
        }
        return dp[0];
    }
};