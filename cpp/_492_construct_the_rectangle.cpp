/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 492 - Construct the Rectangle
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
    vector<int> constructRectangle(int area) {
    	int W = (int)sqrt(area);
    	while (area%W) W--;
    	return {area/W, W};
    }
};


int main() {
	Solution sol;
	vector<int> result = sol.constructRectangle(20);
	for(int n : result)
		cout << n << ' ';
	cout << endl;

	vector<int> nums = {10, 20, 30, 40, 50};
	for(int n : nums)
		cout << n << ' ';
	cout << endl;
	return 0;
}
