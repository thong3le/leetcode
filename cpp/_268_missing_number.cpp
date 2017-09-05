/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 268 - Missing Number
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
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for(int i = 0; i < nums.size(); i++)
            ans ^= i ^ nums[i];
        return ans;
    }
};


int main() {
	return 0;
}
