/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 442 - Find All Duplicates in an Array
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
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if (nums[abs(nums[i])-1] < 0) result.push_back(abs(nums[i]));
            else nums[abs(nums[i])-1]*=-1;
        }
        return result;   
    }
};


int main() {
	return 0;
}
