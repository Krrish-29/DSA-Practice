// 2904. Shortest and Lexicographically Smallest Beautiful String
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // simple sliding window , with count of 1's in it 
        // and if count of 1's == k then update the minLen string 
        // if minlen is empty or the substr of left to right is smaller directly update the minLen string
        // else if len is same then compare for lexicographically smallest 
        int left=0,right=0,size=s.size(),count=0,len;
        string minLen;
        while(right<size){
            if(s[right]=='1') count++;
            while(count>k || s[left]=='0'){
                if(s[left]=='1') count--;
                left++;
            }
            if(count==k){
                len=right-left+1;
                if(minLen.empty() || minLen.size() > len) minLen=s.substr(left,len);
                else if(minLen.size() == len && minLen > s.substr(left,len)) minLen=s.substr(left,len);
            }
            right++;
        }   
        return minLen;
    }
};