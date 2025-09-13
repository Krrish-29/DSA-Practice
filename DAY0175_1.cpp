// 3541. Find Most Frequent Vowel and Consonant
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>freq(26,0);
        int vowel=0,consonants=0;
        for(char ch:s) {
            freq[ch-'a']++;
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') vowel=max(vowel,freq[ch-'a']);
            else consonants=max(consonants,freq[ch-'a']);
        }
        return vowel+consonants;
    }
};