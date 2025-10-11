// 3707. Equal Score Substrings
class Solution {
public:
    bool scoreBalance(string s) {
        int i=0,j=s.size()-1;
        int left=0,right=0;
        while(i<=j){
            if(left<right){
                left+=(s[i]-'a'+1);
                i++;
            }
            else{
                right+=(s[j]-'a'+1);
                j--;
            }
        }
        return left==right;
    }
};