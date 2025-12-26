// 3760. Maximum Substrings With Distinct Start
class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<int,int>freq;
        for(char ch:s){
            freq[ch-'a']++;
        }
        return freq.size();
    }
};