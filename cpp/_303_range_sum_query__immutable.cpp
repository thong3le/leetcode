/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 303 - Range Sum Query - Immutable
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

class NumArray {
    vector<int> cumsum;
public:
    NumArray(vector<int> nums) {
        cumsum.push_back(0);
        for(int i = 0; i < nums.size(); i++)
            cumsum.push_back(cumsum.back() + nums[i]);
    }
    
    int sumRange(int i, int j) {
        return cumsum[j+1] - cumsum[i];
    }
};



int main() {
	return 0;
}
