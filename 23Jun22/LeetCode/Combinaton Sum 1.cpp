class Solution {
public:
    // vector<vector<int>> fin;
    
    void uq(vector<int> &v, vector<int> &ds,vector<vector<int>> &End, int index, int target){
        int n = v.size();
        // if(v[index] > target or target<0) return
        if(index == n and target==0){
            for(auto e : ds) cout << e <<" ";
            cout << "\n";
            // fin.push_back(ds); // O(n)
            End.push_back(ds);
            return;
        }
        if(index == n) return;
        // take the cuurent index and 
        // still stay on the same index
        if (v[index] <= target){
            ds.push_back(v[index]);
            uq(v,ds,End,index, target - v[index]);
            ds.pop_back();
        }
         
        // ignore the current index and move to next index
        uq(v,ds,End,index+1,target);
    }
     
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //take the coins in sorted maner
        // sort(candidates.begin(), candidates.end());
        vector<int> emptyDS;
        vector<vector<int>> End;
        uq(candidates,emptyDS,End,0,target);
        // for(auto v : fin){
        //     for(auto e : v){
        //         cout << e <<" ";
        //     }
        //     cout << "\n";
        // }
        return End;
    }
};




//https://leetcode.com/problems/combination-sum/