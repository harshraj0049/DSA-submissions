class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int xored=nums[0];
    //0^a=a 
    // a^a=0
    for(int i=1;i<nums.size();i++){
        xored=xored^nums[i];
    }    
    return xored;
    }
};
