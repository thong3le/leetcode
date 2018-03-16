/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 121 - Best Time to Buy and Sell Stock
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
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy = prices[0], profit = 0;
        for(int i = 1; i < prices.size(); i++){
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i] - buy);
        }
        return profit;
    }
};


int main() {
	return 0;
}
