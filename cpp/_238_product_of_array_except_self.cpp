/* 
*    Author: Thong Le
*    Date: May 2, 2017
*   
*    LeetCode 238 - Product of Array Except Self
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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,1);
        for(int i = 1; i < n; i++){
            result[i] = result[i-1] * nums[i-1];
        }
        int p = 1;
        for(int i = n-1; i >= 0; i--){
            result[i] *= p;
            p *= nums[i];
        }
        return result;
    }
};


int main() {
	return 0;
}
