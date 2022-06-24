class Solution {
public:
    int hammingWeight(uint32_t n) {
        // int cnt=0;
        // while(n>0){
        //     cnt += n&1;
        //     n>>=1;
        // }
        int cnt = __builtin_popcount(n);
        
        return cnt;
    }
};

//https://leetcode.com/problems/number-of-1-bits/submissions/