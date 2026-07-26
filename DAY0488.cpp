// 1081. Smallest Subsequence of Distinct Characters
class Solution {
public:
    string smallestSubsequence(string s) {
        // simple logic 
        // we need subseq of unique chars which is lexi smallest 
        // for that we start with building our result 
        // every time we see a char we reduce its freq and check is it in our result string 
        // if yes then move on
        // if not then we try to add it for that first check if result is empty or not if not
        // the problem is smallest lexi string for that we will remove all chars that are larger than our 
        // current char but make sure that the char that is being removed can be seen later using freq
        // remove chars from result as well as seen check 
        // and then add current char to seen and result 
        vector<int>chars(26,0);
        vector<bool>seen(26,false);
        for(char &ch:s) {
            chars[ch-'a']++;
        }
        string ans;
        for(char &ch:s){
            chars[ch-'a']--;
            if(!seen[ch-'a']){
                while(!ans.empty()&& ans.back()>ch&&chars[ans.back()-'a']>0){
                    seen[ans.back()-'a']=false;
                    ans.pop_back();
                }
                ans.push_back(ch);
                seen[ch-'a']=true;
            }
        }
        return ans;
    }
};