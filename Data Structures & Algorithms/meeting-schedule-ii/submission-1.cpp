/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(),intervals.end(),[&](auto & a,auto & b){
        return a.start<b.start;
    });
    vector<int>starts;
    vector<int>ends;
    for(auto it:intervals){
        starts.push_back(it.start);
        ends.push_back(it.end);
    }
    sort(starts.begin(),starts.end());
    sort(ends.begin(),ends.end());
    int maxroom=0;
    int count=0;
    int s=0;
    int e=0;
    while(s<intervals.size()){
        if(starts[s]<ends[e]){
            s++;
            count++;
        }
        else{
            e++;
            count--;
        }
        maxroom=max(maxroom,count);
    }
    return maxroom;
    }
};
