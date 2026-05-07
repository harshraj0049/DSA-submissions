class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.size()==0) return {};
    sort(intervals.begin(),intervals.end(),[&](auto &a,auto &b){
        return a[0]<b[0];
    });
    // vector<vector<int>>res;
    int count=0;
    for(int i=0;i<intervals.size()-1;i++){
        if(intervals[i][1]>intervals[i+1][0]){
            intervals[i+1][0]=max(intervals[i+1][0],intervals[i][0]);
            intervals[i+1][1]=min(intervals[i+1][1],intervals[i][1]);
            count++;
        }
    }
    return count;   
    }
};
