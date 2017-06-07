/* 
* Author: Thong Le
* Date: May 2, 2017
*
* LeetCode 27 - Remove Element
*
* Solution Approach: 
*
*
*
*/



public class _027_remove_element {
	public int removeElement(int[] A, int elem) {
        int count = A.length;
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i : A){
            if (i == elem) count--;
            else list.add(i);
        }
        for (int i = 0; i < count; i++) A[i] = list.get(i);
        return count;
    }
}
