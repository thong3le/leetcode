/* 
* Author: Thong Le
* Date: May 2, 2017
*
* LeetCode 118 - Pascal's Triangle
*
* Solution Approach: 
*
*
*
*/




public class _118_pascals_triangle {
	public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> last = new ArrayList<Integer>();
        
        if (numRows<= 0) return result;
        
        last.add(1);
        result.add(last);
        
        for (int i = 2; i <= numRows; i++){
            List<Integer> current = new ArrayList<Integer>();
            current.add(1);
            for (int j = 1; j < last.size(); j++) {
                current.add(last.get(j-1) + last.get(j));
            }
            current.add(1);
            result.add(current);
            last = current;
        }
        return result;
    }
}
