class Solution {
public:
 int robb(vector<int>& nums,int start,int end){
    int twostep=0;
    int onestep=0;
    for(int i=start;i<end;i++){
        int curr=max(nums[i]+twostep,onestep);
        twostep=onestep;
        onestep=curr;
    }
    return onestep;
 }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int last=robb(nums,0,n-1);
        int seclast=robb(nums,1,n);
        return max(last,seclast);
    }
};
