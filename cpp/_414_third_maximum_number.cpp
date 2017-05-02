/* 
*    Author: Thong Le
*    Date: May 2, 2017
*   
*    LeetCode 414 - Third Maximum Number
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
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if (nums[i] > first)
                first = nums[i];
        }
        for(int i = 0; i < n; i++){
            if (nums[i] != first && nums[i] >= second)
                second = nums[i];
        }
        for(int i = 0; i < n; i++){
            if (nums[i] != first && nums[i] != second && nums[i] >= third){
                third = nums[i];
                flag = true;
            }
        }
        return flag ? third : first;
    }
};


int main() {
	return 0;
}
