class Solution {
public:
    int recr(int index,vector<int>& cost,vector<int>&dp){
        if(index>=cost.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        return dp[index]=cost[index]+min(recr(index+1,cost,dp),recr(index+2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //vector<int>dp(n);
        //dp[0]=cost[0];
        //dp[1]=cost[1];
        int twostep=cost[0]; //dp[i-1]
        int onestep=cost[1]; //dp[i-2]
        for(int i=2;i<n;i++){
            int curr=cost[i]+min(onestep,twostep);// dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
            twostep=onestep;
            onestep=curr;
        }
        return min(onestep,twostep);
        // return min(dp[n-1],dp[n-2]);
        // return min(recr(0,cost,dp),recr(1,cost,dp));
    }
};
