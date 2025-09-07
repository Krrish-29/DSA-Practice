// 392. Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size1=s.size(),size2=t.size();
        int i=0,j=0;
        for(i,j;i<size1&&j<size2;j++){
            if(s[i]==t[j]) i++;
        }
        return i==size1;
    }
};