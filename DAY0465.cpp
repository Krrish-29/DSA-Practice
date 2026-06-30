// 1358. Number of Substrings Containing All Three Characters
class Solution {
public:
    int numberOfSubstrings(string s) {
        int size=s.size();
        int strCount=0;
        int i=0,j=0;
        vector<int>abc(3,0);
        while(j<size){
            abc[s[j]-'a']++;
            while(abc[0]>0&&abc[1]>0&&abc[2]>0) {
                strCount+=(size-j);
                abc[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return strCount;
    }
};