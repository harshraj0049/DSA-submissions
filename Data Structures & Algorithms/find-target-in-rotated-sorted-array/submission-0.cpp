class Solution {
public:
    int search(vector<int>& nums, int target) {
    int low=0;
    int n=nums.size();
    int high=n-1;
    int mid=-1;
    while(low<=high){
        mid=low+(high-low)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<nums[n-1]){
            if(nums[mid]<target && target<=nums[n-1]){
                low=mid+1;
            }
            else high=mid-1;
        }
        else{
            if(nums[0]<=target && target<nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }    
    return -1;
    }
};
