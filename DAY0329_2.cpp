// 3839. Number of Prefix Connected Groups
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int count=0,size=words.size();
        unordered_map<string,int>map;
        for(int i=0;i<size;i++){
            map[words[i].substr(0,k)]++;
        }
        for(auto it = map.begin(); it != map.end(); ++it){
            if(it->second>1&&it->first.size()==k) count++;
        }
        return count;
    }
};