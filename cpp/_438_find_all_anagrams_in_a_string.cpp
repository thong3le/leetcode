/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 438 - Find All Anagrams in a String
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
	vector<int> findAnagrams(string s, string p) {
		int n = s.length(), k = p.length();
        vector<int> result;
        if (k > n) return result;
        
        int count[26] = {0};
        for(int i = 0; i < k; i++) count[p[i]-'a']++;

        int l = 0, r = 0;
    	while (r < n) {
    		count[s[r++]-'a']--;
    		if (all_of(count, count+26, [](int i){return i==0;})) result.push_back(l);
    		if (r-l == k) count[s[l++]-'a']++;
    	}
    	return result;

	}
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), k = p.length();
        vector<int> result;
        if (k > n) return result;
        
        int count[26] = {0};
        for(int i = 0; i < k; i++) count[p[i]-'a']++;
        
        int l = 0, r = 0, diff = k;
        while (r < n) {
            if (count[s[r]-'a'] >= 1) diff--; // if s[r] is in p
            count[s[r++]-'a']--;
            if (diff == 0) result.push_back(l); // there is no difference
            if (r-l == k) { // make sure the window has size k by moving the left pointer
                if (count[s[l]-'a'] >= 0) diff++; // 
                count[s[l++]-'a']++;
            }   
        }
        return result;
    }
};


int main() {
	return 0;
}
