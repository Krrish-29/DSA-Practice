// 3775. Reverse Words With Same Vowel Count
class Solution {
private:
    void swap(string &s,int i,int j){
        char temp;
        while(i<j){
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
    }
public:
    string reverseWords(string s) {
        int size=s.size(),vowels=0;
        string vowel="aeiou";
        int i=0,j;
        while(i<size&&s[i]!=' '){
            if(vowel.find(s[i])!=string::npos) vowels++;
            i++;
        }
        int currVowel=0;
        for(i;i<size;i++){
            if(s[i]==' ') {
                if(currVowel==vowels) swap(s,j,i-1);
                j=i+1;
                currVowel=0;
            }
            if(vowel.find(s[i])!=string::npos) currVowel++;
        }
        if(currVowel==vowels) swap(s,j,i-1);
        return s;
    }
};  