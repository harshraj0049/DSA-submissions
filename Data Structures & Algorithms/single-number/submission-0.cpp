class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int xored=0;
    //0^a=a 
    // a^a=0
    for(int i=0;i<nums.size();i++){
        xored=xored^nums[i];
    }    
    return xored;
    }
};
