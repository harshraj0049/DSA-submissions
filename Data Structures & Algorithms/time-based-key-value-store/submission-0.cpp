class TimeMap {
public:
    unordered_map<string,map<int,string>>keystore;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
    keystore[key].insert({timestamp,value});  
    }
    
    string get(string key, int timestamp) {
    if(keystore.find(key)==keystore.end()) return "";
    auto& m=keystore[key];
    auto it=m.upper_bound(timestamp);
    return it==m.begin() ? "" :(--it)->second;
    }
};
