// 3136. Valid Word
class Solution {
public:
    bool isValid(string word) {
        int size=word.size();
        if(size<3) return false;
        bool consonant=false,vowel=false;
        string vowels="aeiouAEIOU";
        while(--size>=0){
            if(!((word[size]<='9'&&word[size]>='0')||(word[size]<='Z'&&word[size]>='A')||(word[size]<='z'&&word[size]>='a'))) return false;
            // if(word[size]=='a'||word[size]=='e'||word[size]=='i'||word[size]=='o'||word[size]=='u'||word[size]=='A'||word[size]=='E'||word[size]=='I'||word[size]=='O'||word[size]=='U') vowel=true;
            if(vowels.contains(word[size])) vowel=true;
            else if((word[size]<='Z'&&word[size]>='A')||(word[size]<='z'&&word[size]>='a')) consonant=true;
        }
        return true&&consonant&&vowel;
    }
};