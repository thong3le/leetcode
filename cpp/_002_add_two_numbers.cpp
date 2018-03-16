/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 2 - Add Two Numbers
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum;
        ListNode *cur1 = l1, *cur2 = l2;
        ListNode dummy(-1), *head = &dummy, *cur = head;
        while (cur1 || cur2 || carry) {
            sum = carry;
            if (cur1) sum += cur1->val, cur1 = cur1->next;
            if (cur2) sum += cur2->val, cur2 = cur2->next;
            carry = sum / 10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
        }
        return head->next;
    }
};

int main() {
	return 0;
}
