/* 
*    Author: Thong Le
*    Date: May 2, 2017
*   
*    LeetCode 467 - Unique Substrings in Wraparound String
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
    int findSubstringInWraproundString(string p) {
        vector<int> count(26,0);
        int max_contiguous = 1;
        for(int i = 0; i < p.size(); i++){
            if (i > 0 && (p[i] - p[i-1] == 1 || p[i-1] - p[i] == 25))
                max_contiguous++;
            else
                max_contiguous = 1;
            count[p[i] - 'a'] = max(count[p[i] - 'a'], max_contiguous);
        }
        int ans = 0;
        for(int i = 0; i < 26; i++)
            ans += count[i];
        return ans;
    }
};


int main() {
	return 0;
}
