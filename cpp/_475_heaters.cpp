/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 475 - Heaters
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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int radius = 0, r;
        for(int i = 0; i < houses.size(); i++){
            r = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            if (r == 0) radius = max(radius, heaters[r] - houses[i]);
            else if (r == heaters.size()) radius = max(radius, houses[i] - heaters.back());
            else  radius = max(radius, min(houses[i] - heaters[r-1],heaters[r] - houses[i]));
        }
        return radius;
    }
};


int main() {
	return 0;
}
