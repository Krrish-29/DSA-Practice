// 3853. Merge Close Characters
class Solution {
public:
    string mergeCharacters(string s, int k) {
        int merges=0;
        unordered_map<char,int>map;
        for(int i=0;i<s.size();i++){
            if(map.find(s[i])==map.end()){
                map[s[i]]=i;
            }
            else {
                if(i-map[s[i]]<=k){
                    s.erase(s.begin()+i);
                    i--;
                }
                else{
                    map[s[i]]=i;
                }
            }
        }
        return s;
    }
};