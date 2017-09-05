/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 453 - Minimum Moves to Equal Array Elements
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
    int minMoves(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int m = nums[0], ans = 0;
        for(int x : nums) m = min(x, m);
        for(int x : nums) ans += x - m;
        return ans;
    }
};


int main() {
	return 0;
}
