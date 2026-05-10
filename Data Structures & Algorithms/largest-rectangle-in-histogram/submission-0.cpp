class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    int pse=0;
    int nse=0;
    stack<int>st;
    int h=0;
    int n=heights.size();
    int maxarea=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            nse=i;
            h=heights[st.top()];
            st.pop();
            pse=st.empty()?-1:st.top();
            maxarea=max(maxarea,(nse-pse-1)*h);
        }
        st.push(i);
    }   
    while(!st.empty()){
        nse=n;
        h=heights[st.top()];
        st.pop();
        pse=st.empty()?-1:st.top();
        maxarea=max(maxarea,(nse-pse-1)*h);
    }
    return maxarea;
    }
};
