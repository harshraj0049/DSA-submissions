class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>>mpp;
    for(auto & it:strs){
        vector<int>key(26,0);
        for(char & c:it){
            key[c-'a']++;
        }
        string k="";
        for(int i=0;i<26;i++){
            k+=','+to_string(key[i]);
        }
        mpp[k].push_back(it);
    }   
    vector<vector<string>>ans;
    for(auto & it:mpp){
        ans.push_back(it.second);
    }
    return ans;
    }
};
