/* 
* Author: Thong Le
* Date: May 2, 2017
*
* LeetCode 119 - Pascal's Triangle II
*
* Solution Approach: 
*
*
*
*/




public class _119_pascals_triangle_ii {
	public List<Integer> getRow(int rowIndex) {
        List<Integer> result = new ArrayList<Integer>();
        if (rowIndex < 0) return result;
        result.add(1);
        if (rowIndex == 0) return result;
        result.add(1);
        if (rowIndex == 1) return result;
        
        for (int i = 2; i <= rowIndex; i++){
            int last;
            int prev = result.get(0);
            for (int j = 1; j < i; j++){
                last = result.get(j);
                result.set(j, last + prev);
                prev = last;
            }
            result.add(1);
        }
        return result;
    }
}
