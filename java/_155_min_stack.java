/* 
* Author: Thong Le
* Date: May 2, 2017
*
* LeetCode 155 - Min Stack
*
* Solution Approach: 
*
*
*
*/

class _155_min_stack {
 Node dummy;
 Node topNode;
    class Node {
        int val;
        int min;
        Node next;
        public Node(int val) {
            this.val = val;
        }
    }
     
    public _155_min_stack() {
     dummy = new Node(0);
        dummy.min = Integer.MAX_VALUE;
        topNode = dummy;
    }
     
    public void push(int x) {
        Node n = new Node(x);
        n.next = topNode;
        n.min = n.val<=topNode.min ? n.val : topNode.min;
        topNode = n;
    }
 
    public void pop() {
        if(topNode==dummy) return;
        topNode = topNode.next;
        return;
    }
 
    public int top() {
        return topNode.val;
         
    }
 
    public int getMin() {
        return topNode.min;
    }
}
