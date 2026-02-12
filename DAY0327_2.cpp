// 3714. Longest Balanced Substring II
class Solution {
private:
    void check(char ch1,char ch2,int &maxLen,string &s){
        unordered_map<int,int>map;
        int val=0,size=s.size();
        map[0]=-1;
        for(int i=0;i<size;i++){
            if(s[i]==ch1) val++;
            else if(s[i]==ch2) val--;
            else {
                unordered_map<int,int>map1;
                map=map1;
                map[0]=i;
                val=0;
                continue;
            }
            if(map.count(val)) maxLen=max(maxLen,i-map[val]);
            else map[val]=i;
        }
    }
public:
    int longestBalanced(string s) {
        // int size=s.size(),maxLen=INT_MIN;
        // for(int i=0;i<size;i++){
        //     vector<int>freq(3,0);
        //     int dist=0,maxFreq=0;
        //     for(int j=i;j<size;j++){
        //         if(freq[s[j]-'a']==0) dist++;
        //         freq[s[j]-'a']++;
        //         maxFreq=max(maxFreq,freq[s[j]-'a']);
        //         if(dist*maxFreq==j-i+1) maxLen=max(maxLen,j-i+1);
        //     }
        // }
        // return maxLen;

        int size=s.size(),aCount=0,bCount=0,cCount=0,maxLen=1;

        // 1. check for a single char only
        int len=1;
        for(int i=1;i<size;i++){
            if(s[i]==s[i-1]) len++;
            else {
                maxLen=max(maxLen,len);
                len=1;
            }
        }
        maxLen=max(maxLen,len);

        // 2. check for 2 chars only 
        // a and b
        check('a','b',maxLen,s);
        // b and c
        check('b','c',maxLen,s);
        // a and c
        check('a','c',maxLen,s);

        // 3. check for all 3 chars
        unordered_map<string,int>map;
        map["0#0"]=-1;
        for(int i=0;i<size;i++){
            if(s[i]=='a') aCount++;
            else if(s[i]=='b') bCount++;
            else cCount++;

            string key=to_string(aCount-bCount)+"#"+to_string(aCount-cCount);
            if(map.count(key)) maxLen=max(maxLen,i-map[key]);
            else map[key]=i;
        }
        return maxLen;
    }
};