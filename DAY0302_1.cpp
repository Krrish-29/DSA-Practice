// 3813. Vowel-Consonant Score
class Solution {
public:
    int vowelConsonantScore(string s) {
        string vowel="aeiou";
        int v=0,c=0;
        for(char ch:s){
            if(vowel.find(ch)!=string::npos) v++;
            else if(ch<='z'&&ch>='a') c++;
        }
        if(c==0) return 0;
        return v/c;
    }
};