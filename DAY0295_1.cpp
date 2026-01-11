// 3803. Count Residue Prefixes
class Solution {
public:
    int residuePrefixes(string s) {
        unordered_map<int,int>map;
        int dist=0,count=0;
        for(int i=0;i<s.size();i++){
            if(map.find(s[i])==map.end()) dist++;
            map[s[i]]++;
            if(dist==((i+1)%3)) count++; 
        }
        return count;
    }
};