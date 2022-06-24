class Solution {
public:
    vector<vector<int>> End;
    void f(vector<int> &v, int index){
        int n = v.size();
        if(index== n){
            End.push_back(v);
            return;
        }
        for(int i=index;i<n;i++){
            swap(v[i],v[index]);
            f(v,index+1);
            swap(v[i],v[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums,0);
        return End;
    }
};

//https://leetcode.com/problems/permutations/submissions/

    // vector<bool> vis;
    // vector<vector<int>> End;
    // void f(vector<int>&v , vector<int> &ds){
    //     // loop and not visited then visist
    //     int n = v.size();
    //     if(ds.size()==n){
    //         End.push_back(ds);
    //     }
    //     for(int i=0;i<n;i++){
    //         if(!vis[i]){
    //             ds.push_back(v[i]);
    //             vis[i] = 1;
    //             // make a recusrive call
    //             f(v,ds);
    //             ds.pop_back();
    //             vis[i] = 0;
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
        // // BruteForce
        // //TC : n! * n
        // //SC : n + n 
        // int n = nums.size();
        // vis.resize(n,0);
        // vector<int> emptyDS;
        // f(nums,emptyDS);
        // return End;
    // }