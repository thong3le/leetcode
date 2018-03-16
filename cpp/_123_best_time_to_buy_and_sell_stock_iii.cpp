/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 123 - Best Time to Buy and Sell Stock III
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
        //zero balance at the beginning
        // buy1 is the balance after buying 1st stock
        // sell1 is the banlace after selling 1st stock
        // buy2 is the balance after buying 2nd stock
        // sell2 is the balance after selling 2nd stock
        int buy1 = -prices[0], buy2 = -prices[0], sell1 = 0, sell2 = 0;
        for(int i = 1; i < prices.size(); i++){
            sell2 = max(sell2, buy2 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy1 = max(buy1, -prices[i]);
        }
        return sell2;
    }
};


int main() {
	return 0;
}
