class Solution {
public:
    
    void f(vector<int>&v, vector<vector<int>> &End, vector<int>&ds, int index){
        int n = v.size();
        // if(index == n){
        //     End.push_back(ds);
        //     return;
        // }
        // now go through the int array
        int i;
        int before =-100;//due to constraint
        for(i=index; i<n ;++i){
            //take from given index
            // if a is taken then do not take a again
            if (before != v[i]){
                // ignore 
                // f(v,End,ds,i+1);
                // do the task
                before = v[i];
                ds.push_back(v[i]);
                End.push_back(ds);
                f(v,End,ds,i+1);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        // sort the array for easiness
        sort(v.begin(),v.end());
        vector<int> emptyDS;
        vector<vector<int>> End;
        End.push_back(emptyDS);
        f(v,End,emptyDS,0);
        return End;
    }
};

//https://leetcode.com/problems/subsets-ii/submissions/

