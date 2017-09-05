class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.empty()) return m*n;
        int mina = ops[0][0], minb = ops[0][1];
        for(int i = 1; i < ops.size(); i++){
            mina = min(mina, ops[i][0]);
            minb = min(minb, ops[i][1]);
        }
        return mina*minb;
    }
};