/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 3 - Longest Substring Without Repeating Characters
*
*    Solution Approach: 
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
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int count[256] = {0}, ans = 0;
        for(int l = 0, r = 0; l < n && r < n; count[s[l++]]--){
            while (r < n && count[s[r]] == 0)  count[s[r++]]++;
            if (r-l > ans) ans = r-l;
        }
        return ans;
    }
};


int main() {
	return 0;
}
