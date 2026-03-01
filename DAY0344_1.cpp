// 3856. Trim Trailing Vowels
class Solution {
public:
    string trimTrailingVowels(string s) {
        string vowel="aeiou";
        int i;
        for(i=s.size()-1;i>=0;i--){
            if(vowel.find(s[i])==string::npos){
                break;
            }
        }
        return s.substr(0,i+1);
    }
};