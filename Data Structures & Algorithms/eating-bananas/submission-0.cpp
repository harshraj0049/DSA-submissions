class Solution {
public:
    long long valid(vector<int>&piles,int mid){
        long long count=0;
        for(int i=0;i<piles.size();i++){
                count+=(piles[i]+mid-1)/mid;
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    int low=1;
    int high=piles[0];
    for(int i=1;i<piles.size();i++){
        high=max(high,piles[i]);
    } 
    int mid=-1;
    int ans=0;
    while(low<=high){
        mid=low+(high-low)/2;
        if(valid(piles,mid)<=h){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    } 
    return ans;  
    }
};
