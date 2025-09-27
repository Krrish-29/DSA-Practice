// 3692. Majority Frequency Characters
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int>hashmap(26,0);
        for(char ch:s) hashmap[ch-'a']++;
        string maxChar;
        int maxFreq=INT_MIN,currFreq=0;
        for(int i=0;i<26;i++){
            if(hashmap[i]==0) continue;
            currFreq=hashmap[i];
            string currChar(1,'a'+i);
            for(int j=i+1;j<26;j++){
                if(hashmap[j]==currFreq) {
                    currChar.push_back('a'+j);
                }
            }
            if(maxChar.size()<currChar.size()){
                maxChar=currChar;
                maxFreq=currFreq;
            }
            else if(maxChar.size()==currChar.size()&&maxFreq<currFreq){
                maxChar=currChar;
                maxFreq=currFreq;
            }
        }
        return maxChar;
    }
};