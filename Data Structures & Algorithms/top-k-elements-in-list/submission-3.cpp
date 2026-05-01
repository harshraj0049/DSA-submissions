class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>mpp;
    int n=nums.size();
    vector<vector<int>>bucket(n+1) ;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }  
    for(const auto & it:mpp){
        bucket[it.second].push_back(it.first);
    }
    vector<int>ans;
    for(int i=n;i>0;i--){
        for(auto e:bucket[i]){
            ans.push_back(e);
            if(ans.size()==k) return ans;
        }
    }
    return ans;
    }
};
