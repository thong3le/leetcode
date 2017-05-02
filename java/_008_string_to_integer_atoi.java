/* 
* Author: Thong Le
* Date: May 2, 2017
*
* LeetCode 8 - String to Integer (atoi)
*
* Solution Approach: 
*
*
*
*/


import java.util.*;

public class _008_string_to_integer_atoi {
	public int atoi(String str) {
        if (str == null) {
            return 0;
        }

        // a named group is used here: number
       	Pattern p = Pattern.compile("^\\s*(?<number>[\\+-]?\\d+).*$");
        Matcher m = p.matcher(str);

        if (m.find()) {
            String numberStr = m.group("number");
            char signChar = numberStr.charAt(0);

            if (signChar >= '0' && signChar <= '9') {
                signChar = '+';
            }

            int number = -1;
            try {
                number = Integer.parseInt(numberStr);
            } catch (Exception e) {
                if (signChar == '-') {
                    number = Integer.MIN_VALUE;
                } else {
                    number = Integer.MAX_VALUE;
                }
            }

            return number;
            
        }

        return 0;
    }
}
