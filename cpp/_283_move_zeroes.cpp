/* 
*    Author: Thong Le
*    Date: May 2, 2017
*   
*    LeetCode 283 - Move Zeroes
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
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);     
    }
};


int main() {
	return 0;
}
