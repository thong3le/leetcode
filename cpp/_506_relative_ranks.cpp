/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 506 - Relative Ranks
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
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<int> rank;
        vector<string> result(n);
        for(int i = 0; i < n; i++) rank.push_back(i);
        sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a] > nums[b];});
        if (n > 0) result[rank[0]] = "Gold Medal";
        if (n > 1) result[rank[1]] = "Silver Medal";
        if (n > 2) result[rank[2]] = "Bronze Medal";
        for(int i = 3; i < n; i++){
            result[rank[i]] = to_string(i+1);
        }
        return result;
    }
};

int main() {
	return 0;
}
