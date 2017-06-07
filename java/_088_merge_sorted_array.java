/* 
* Author: Thong Le
* Date: May 2, 2017
*
* LeetCode 88 - Merge Sorted Array
*
* Solution Approach: 
*
*
*
*/




public class _088_merge_sorted_array {
	public void merge(int A[], int m, int B[], int n) {
        int[] C = new int[m+n];
        int c = 0;
        int a = 0;
        int b = 0;
        while ((c < m+n) && (a < m) && (b < n)){
            if (A[a] < B[b]){
                C[c++] = A[a++];
            }
            else if (A[a] > B[b]){
                C[c++] = B[b++];
            }
            else{
                C[c++] = A[a++];
                C[c++] = B[b++];
            }
        }
        
        if ( a < m){
            for (int i = a; i < m; i++) C[c++] = A[a++];
        }
        if ( b < n){
            for (int i = b; i < n; i++) C[c++] = B[b++];
        }
        for (int i = 0; i < m+n; i++) A[i] = C[i];
    }
}
