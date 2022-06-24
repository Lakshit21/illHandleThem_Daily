class Solution {
public:
    void uq(vector<int> &v , vector<vector<int>> &End , vector<int> &ds, int index, int target){
        int n = v.size();
        if(target == 0){
            End.push_back(ds);
            return;
        }
        // becoz the v is in sorted order
        // if(v[index] > target) return; // target can not be met
        
        //take the index and move to next index
        bool open = 1;
        int before=-1;
        for(int i=index; i<n ;i++){
            if(before != v[i]){
                // found some different value
                // open the lock
                open = 1;
            }
            if(open){
                open = 0;//close the lock
                before = v[i];// store the uniq value
                // make a recursion call with that value
                if(v[i] > target) break;
                if(v[i] <= target){
                    ds.push_back(v[i]);
                    uq(v,End,ds,i+1,target-v[i]);// also go to next index
                    ds.pop_back();
                }
                //ignore that value
                // uq(v,End,ds,i+1,target);
            }
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        // sort the v for ans in sorted order
        sort(v.begin(), v.end());
        vector<vector<int>> End;
        vector<int> emptyDS;
        uq(v,End,emptyDS,0,target);
        return End;
    }
};
//https://leetcode.com/problems/combination-sum-ii/

/*
****combination sum 1
-> unlimited supply
-> two case
1) ignore it and move to same index
2) take it and stay on same index
-> go to at the depth of length n
   and check target is 0 or not

      f(index,target)
     /               \
f(index+1,target)    f(index, target - v[index])
//ignore and move     //take it and stay

****combination sum2
->limited supply
-> one case
1) if possible ( v[i] <= target) move to that index+1
(always increment index not works)
2) check for uniq index always
if v[a] = v[b] then check(ind : a) for target - v[a], a+1
and ignore (ind : b) // for uniqueness
-> going to at depth of n is not neccesory
   check whether target is zero or not
   beyond that index target-v[indx] is negetive 
   and we also not carry that target to length n
   (because ignre that index is not the option)
-> sorting before searching is neccesory

//  n sorted values are there
let say 6 vals
f(i,t)
[...,a,a,a,b,b,c,..] here t < c and t=b and t>a
     i   

1)f(i,t-a) // take and move to next
2)ignore i+1 (a is already taken)
3)ignore i+2 (a is already taken)
4)f(i+3,t-b) //take and move to next
but t-b = 0 hence take that sqn 
5) ignore i+4 (b is already taken)
6)here t>c so break the loop and return
t-c<0 , and our target is 0
which is lessthen out target


*/