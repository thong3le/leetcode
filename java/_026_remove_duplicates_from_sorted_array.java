/* 
* Author: Thong Le
* Date: May 2, 2017
*
* LeetCode 26 - Remove Duplicates from Sorted Array
*
* Solution Approach: 
*
*
*
*/




public class _026_remove_duplicates_from_sorted_array {
    public int removeDuplicates(int[] A) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i : A){
            if (list.isEmpty() || i != list.get(list.size() - 1) ) list.add(i);
        }
        for (int i = 0; i < list.size(); i++)
            A[i] = list.get(i);
        return list.size();
    }
}
