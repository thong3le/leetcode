/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 532 - K-diff Pairs in an Array
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
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        if (k < 0) return 0;
        for(int i = 0; i < nums.size(); i++) count[nums[i]]++;
        int result = 0;
        for(auto it = count.begin(); it != count.end(); it++){
            if (k == 0) result += (it->second >= 2);
            else if (count.find(it->first + k) != count.end()) result++;
        }
        return result;
    }
};


int main() {
	vector<int> nums({1,2,3,4,5});
	cout << findPairs(nums, 1) << endl;
	return 0;
}
