class Solution {
public:
    bool hasAlternatingBits(int n) {
        int before = n&1,cur=0;
        n>>=1;
        while(n>0){
            cur = n&1;
            // cout << before <<" " << cur<<"\n";
            if(before==cur) return false;
            before = cur;
            n>>=1;
        }
        return true;
    }
};

// https://leetcode.com/problems/binary-number-with-alternating-bits/