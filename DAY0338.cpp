// 1461. Check If a String Contains All Binary Codes of Size K
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int size=s.size();
        if(k>size) return false;
        unordered_set<string>set;
        for(int i=0;i<=size-k;i++){
            set.insert(s.substr(i,k));
        }
        if(set.size()==(1<<k)) return true;
        return false;
    }
};