// 3. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>hashtable;
        int start=0,maxLength=0;
        for(int end=0;end<s.size();end++){
            if(hashtable.find(s[end])!=hashtable.end()&&hashtable[s[end]]>=start){
                start=hashtable[s[end]]+1;
            }
            hashtable[s[end]]=end;
            maxLength=max(maxLength,end-start+1);
            }
        return maxLength;
    }
};
