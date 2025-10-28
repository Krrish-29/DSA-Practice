// 1456. Maximum Number of Vowels in a Substring of Given Length
class Solution {
public:
    int maxVowels(string s, int k) {
        string vowel="aeiou";
        int size=s.size();
        int maxSize=0,currSize=0;
        for(int i=0;i<k;i++){
            if(vowel.find(s[i])!=string::npos) currSize++;
        }
        maxSize=max(maxSize,currSize);
        for(int i=k;i<size;i++){
            if(vowel.find(s[i-k])!=string::npos) currSize--;
            if(vowel.find(s[i])!=string::npos) currSize++;
            maxSize=max(maxSize,currSize);
        }
        return maxSize;
    }
};