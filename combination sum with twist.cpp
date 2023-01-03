class Solution {
public:
    void solve(int i, int k, int n,vector<vector<int>>& ans, vector<int>& arr){
        if(k == 0){
            if(n == 0){
                ans.push_back(arr);
            }
            return;
        }
        for(int j = i;j<=9;j++){
            arr.push_back(j);
            solve(j+1, k-1, n-j, ans, arr);
            arr.pop_back();
        } 
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(1,k,n,ans,arr);
        return ans;
    }
};