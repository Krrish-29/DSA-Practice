// 125. Valid Palindrome
class Solution {
private:
    char to_lower(char c){
        if(c>=65&&c<=90) return c+32;
        return c;
    }
    bool is_not_alpha(char c){
        if((c>=65&&c<=90)||(c>=97&&c<=122)||(c>=48&&c<=57)) return false;
        return true;
    }
public:
    bool isPalindrome(string s) {
        int size=s.size();
        for(int i=0,j=size-1;i<j;i++,j--){
            if(is_not_alpha(s[i])) {
                j++;
                continue;
            }
            if(is_not_alpha(s[j])) {
                i--;
                continue;
            }
            if(to_lower(s[i])!=to_lower(s[j])) {
                return false;
            }
        }
        return true;
    }
};