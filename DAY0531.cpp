// 242. Valid Anagram
class Solution {
public:
    bool isAnagram(string s, string t) {
        // time n, space n
        // vector<int>freq(26,0);
        // for(char &c:s){
        //     freq[c-'a']++;
        // }
        // for(char &c:t){
        //     freq[c-'a']--;
        // }
        // for(int i=0;i<26;i++) {
        //     if(freq[i]!=0) return false;
        // }
        // return true;

        // time nlogn, space 1
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};