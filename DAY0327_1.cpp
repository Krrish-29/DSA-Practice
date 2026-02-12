// 3713. Longest Balanced Substring I
class Solution {
private:
    bool check(vector<int>&freq){
        bool flag=false;
        int prev;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            if(!flag){
                flag=true;
                prev=freq[i];
            }
            else if(freq[i]!=prev){
                return false;
            }
        }
        return true;
    }
public:
    int longestBalanced(string s) {
        int size=s.size(),maxLen=INT_MIN;
        for(int i=0;i<size;i++){
            vector<int>freq(26,0);
            int dist=0,maxFreq=0;
            for(int j=i;j<size;j++){
                if(freq[s[j]-'a']==0) dist++;
                freq[s[j]-'a']++;
                maxFreq=max(maxFreq,freq[s[j]-'a']);
                if(dist*maxFreq==j-i+1) maxLen=max(maxLen,j-i+1);
                // if(check(freq)) maxLen=max(maxLen,j-i+1);
            }
        }
        return maxLen;
    }
};