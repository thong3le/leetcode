/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 455 - Assign Cookies
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty() || g.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]){
                i++; j++;
            }
            else j++;
        }
        return i;
    }
};


int main() {
	return 0;
}
