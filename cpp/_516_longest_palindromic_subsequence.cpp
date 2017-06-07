/* 
*    Author: Thong Le
*    Date: May 2, 2016
*   
*    LeetCode 516 - Longest Palindromic Subsequence
*
*    Solution Approach: Dynamic Programming
*
*
*
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(), pre, tmp;
        vector<int> dp(n,1);
        for (int j = 1; j < n; j++){
            pre = 0;
            for (int i = j-1; i >= 0; i--){
                tmp = dp[i];
                dp[i] = (s[i] == s[j]) ? 2 + pre : max(dp[i+1], dp[i]);
                pre = tmp;
            }
        }
        return dp[0];
    }
};

int main() {
	return 0;
}
