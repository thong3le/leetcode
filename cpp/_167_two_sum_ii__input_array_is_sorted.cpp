/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 167 - Two Sum II - Input array is sorted
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1, sum;
        while (i < j) {
            sum = numbers[i] + numbers[j];
            if ( sum == target) return {i+1,j+1};
            else if (sum > target) j--;
            else i++;
        }
        return {};
    }
};


int main() {
	return 0;
}
