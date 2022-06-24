class Solution {
public:
    void f(vector<int> &v,vector<vector<int>> &End, vector<int> &ds, int index){
        int n = v.size();
        if(index == n){
            End.push_back(ds);
            return;
        }
        // ignore
        f(v,End,ds,index+1);
        // take and move
        ds.push_back(v[index]);
        f(v,End,ds,index+1);
        ds.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& v) {
        vector<int> emptyDS;
        vector<vector<int>> End;
        f(v,End,emptyDS,0);
        return End;
    }
};

//https://leetcode.com/problems/subsets/submissions/