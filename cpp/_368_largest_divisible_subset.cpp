/* 
*    Author: Thong Le
*    Date: May 2, 2017
*   
*    LeetCode 368 - Largest Divisible Subset
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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        sort(nums.begin(), nums.end());
        int pre[n];
        int count[n];
        int max = 1, index = 0;
        for(int i = 0; i < n; i++){
            pre[i] = -1;
            count[i] = 1;
            for(int j = i-1; j >= 0; j--){
                if (nums[i] % nums[j] == 0 && count[i] < count[j] + 1) {
                    count[i] = count[j] + 1;
                    pre[i] = j;
                }
            }
            if (count[i] > max) {
                max = count[i];
                index = i;
            }
        }
        vector<int> result;
        while (index != -1) {
            result.push_back(nums[index]);
            index = pre[index];
        }
        return result;
    }
};


int main() {
	return 0;
}
