class Solution {
public:
    bool powOF2(int n){
        double d = log2(n);
        if(ceil(d)==floor(d)) return true;
        return false;
    }
    vector<int> countBits(int n) {
        // // n lg(n) complexity
        // int i;
        // vector<int> v(n+1);
        // for(i=0;i<=n;i++){
        //     v[i] = __builtin_popcount(i);
        // }
        // return v;
        
        // // usign dyamic programming
        // //NEETCODE : https://www.youtube.com/watch?v=RyBM56RIWrM
        vector<int> dp(n+1,0);
        int i;
        int offset=1;
        for(i=1;i<=n;++i){
            if(powOF2(i)) offset = i;
            dp[i] = 1 + dp[i - offset];
        }
        return dp;
    }
};

// https://leetcode.com/problems/counting-bits/submissions/