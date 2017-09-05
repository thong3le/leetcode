class Solution {
public:
    bool canPlaceFlowers(vector<int>& F, int n) {
        int count = 0, prev, next;
        for(int i = 0; i < F.size() && count < n; i++){
            if (F[i] != 0) continue;
            prev = 0, next = 0;
            if (i > 0) prev = F[i-1];
            if ( i < F.size() - 1) next = F[i+1];
            if (prev == 0 && next == 0) {
                F[i] = 1;
                count++;
            }
        }
        return count == n;
    }
};