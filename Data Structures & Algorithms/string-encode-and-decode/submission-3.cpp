class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        int count=0;
        for(auto & it:strs){
            for(char c:it){
                count++;
            }
            encoded+=(to_string(count)+'#'+it);
            count=0;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>res;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#') j++;
            int lenght= stoi(s.substr(i,j-i));
            i=j+1;
            res.push_back(s.substr(i,lenght));
            i=i+lenght;
        }
        return res;
    }
};
