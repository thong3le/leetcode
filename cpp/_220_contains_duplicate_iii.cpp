/* 
*    Author: Thong Le
*    Date: May 2, 2017
*   
*    LeetCode 220 - Contains Duplicate III
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

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k <= 0 || t < 0) return false;
        long w = (long) t + 1;
        unordered_map<long, long> d;
        for (int i = 0; i < nums.size(); i++) {
            long m = getID(nums[i], w);
            if (d.find(m) != d.end()) return true;
            if (d.find(m-1) != d.end() && abs(d[m-1] - nums[i]) < w) return true;
            if (d.find(m+1) != d.end() && abs(d[m+1] - nums[i]) < w) return true;
            d[m] = nums[i];
            if (i >= k) d.erase(getID(nums[i-k], w));
        }
        return false;
    }

    long getID(long i, long w) {
        return i < 0 ? (i+1)/w - 1 : i / w;
    }

    bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k <= 0 || t < 0) return false;
        for (int i = 1; i < nums.size(); i++){
            for (int j = i-1; j >= max(0, i-k); j--){
            	if (nums[i] >= nums[j]){
            		if (nums[i] <= 0 && nums[i] <= nums[j] + t) return true;
            		if (nums[i] > 0 && nums[i] - t <= nums[j]) return true;
            	}
            	else
                	if (nums[j] <= 0 && nums[j] <= nums[i] + t) return true;
            		if (nums[j] > 0 && nums[j] - t <= nums[i]) return true;
            }
        }
        return false;
    }

    bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k <= 0 || t < 0) return false;
        set<long> window;
        for (int i = 0; i < nums.size(); i ++) {
            set<long>::iterator low = window.lower_bound((long)nums[i] - t);
            if (low != window.end() && *low - nums[i] <= t) return true;
            window.insert(nums[i]);
            if (i >= k) window.erase(nums[i-k]);
        }
        return false;
    }
};


int main() {
	return 0;
}
