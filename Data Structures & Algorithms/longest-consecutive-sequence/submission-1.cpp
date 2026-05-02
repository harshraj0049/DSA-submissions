class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int maxlen=0;
    unordered_set<int>s;
    for(int i=0;i<nums.size();i++) s.insert(nums[i]);
    for(int i=0;i<nums.size();i++){
        if(s.find(nums[i]-1)==s.end()){
            int lenght=1;
            while(s.find(nums[i]+lenght)!=s.end()){
                lenght++;
            }
            maxlen=max(maxlen,lenght);
        }
    }
    return maxlen;    
    }
};
