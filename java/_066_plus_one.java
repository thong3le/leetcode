/* 
* Author: Thong Le
* Date: May 2, 2017
*
* LeetCode 66 - Plus One
*
* Solution Approach: 
*
*
*
*/




public class _066_plus_one {
	public int[] plusOne(int[] digits) {
        int[] result = new int[digits.length+1];
        int carry = 1;
        for (int i = digits.length - 1; i >= 0; i--){
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;
        }
        if (carry == 1){
            result[0] = 1;
            for (int i = 1; i <= digits.length; i++){
                result[i] = digits[i-1];
            }
            return result;
        }
        else return digits;
    }
}
