class Solution {
public:
    string foreignDictionary(vector<string>& words) {
    vector<vector<int>>adj(26);
    unordered_set<char> st;
    for(int i=0;i<words.size();i++){
        for(char c:words[i]){
            st.insert(c);
        }
    }
    for(int i=0;i<words.size()-1;i++){
        int n=words[i].size();
        int m=words[i+1].size();
        int size=min(n,m);
        bool diff=false;
        for(int j=0;j<size;j++){
            if(words[i][j]!=words[i+1][j]){
                adj[words[i][j]-'a'].push_back(words[i+1][j]-'a');
                diff=true;
                break;
            }
            if(!diff && n>m) return "";
        }
    } 
    vector<int>indegree(26,0);
    vector<int>toposort;
    queue<int>q;
    for(int i=0;i<26;i++){
        for(auto &it:adj[i]){
            indegree[it]++;
        } 
    }
    for(int i=0;i<26;i++){
        if(indegree[i]==0 && st.find(i+'a')!=st.end()){
        q.push(i);
    }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        toposort.push_back(node);
        for(auto & it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(toposort.size()!=st.size()) return "";
    string ans="";
    for(int i=0;i<toposort.size();i++){
        ans+=(toposort[i]+'a');
    }
    return ans;
    }
};
