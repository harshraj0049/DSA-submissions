class Solution {
public:
    int climbStairs(int n) {
    if(n<=2) return n;
    int onestep=1;
    int twostep=2;
    int ans=0;
    for(int i=3;i<=n;i++){
        ans=onestep+twostep;
        onestep=twostep;
        twostep=ans;
    }
    return ans;

    // vector<int>dp(n+1);
    // dp[1]=1;
    // dp[2]=2;
    // for(int i=3;i<=n;i++){
    //     dp[i]=dp[i-1]+dp[i-2];
    // }
    // return dp[n];
    // if(n<=2) return n;
    // return climbStairs(n-1)+climbStairs(n-2);    
    }
};
