class Solution {
public:
    int robb(int index,vector<int>& nums,vector<int>& dp){
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        return dp[index]=max(nums[index]+robb(index-2,nums,dp),robb(index-1,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        // vector<int>dp(n,-1);
        int twostep=nums[0];
        int onestep=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int curr=max(nums[i]+twostep,onestep);
            twostep=onestep;
            onestep=curr;
        }
        return onestep;
        // return robb(n-1,nums,dp);
    }
};
