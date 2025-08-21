class Solution {
private:

    void solve(vector<int>&nums, vector<int>output, int i, vector<vector<int>>&ans){
        if(i>=nums.size()){
            ans.push_back(output);
            return ;
        }

        //exclude and move to next index
        solve(nums,output,i+1,ans);

        //include this element

        output.push_back(nums[i]);
        solve(nums,output,i+1,ans);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> output;
        int ind = 0;
        solve(nums,output,ind,ans);
        return ans;
        
    }
};