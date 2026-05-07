class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),[&](auto &a,auto &b){
        return a[0]<b[0];
    });
    vector<vector<int>>res;
    for(int i=0;i<intervals.size()-1;i++){
        if(intervals[i][1]<intervals[i+1][0]){
            res.push_back(intervals[i]);
        }
        else if(intervals[i][1]>=intervals[i+1][0]){
            intervals[i+1][0]=min(intervals[i+1][0],intervals[i][0]);
            intervals[i+1][1]=max(intervals[i+1][1],intervals[i][1]);
        }
    }
    // res.push_back(intervals[intervals.size()-2]);
    res.push_back(intervals[intervals.size()-1]);
    return res;
    }
};
