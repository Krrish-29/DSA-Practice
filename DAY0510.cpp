// 3090. Maximum Length Substring With Two Occurrences
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0,right=0,size=s.size(),len=0;
        unordered_map<char,int>freq;
        while(right<size){
            freq[s[right]]++;
            while(freq[s[right]]>2){
                freq[s[left]]--;
                left++;
            }
            right++;
            len=max(len,right-left);
        }
        return len;
    }
};