// 1750. Minimum Length of String After Deleting Similar Ends
class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        char ch;
        while(i<j&&s[i]==s[j]){
            ch=s[i];
            while(ch==s[i]&&i<=j) i++;
            while(ch==s[j]&&i<=j)  j--;
        }
        return max(0,j-i+1);
    }
};