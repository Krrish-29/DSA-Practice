// 3517. Smallest Palindromic Rearrangement I
class Solution {
public:
    string smallestPalindrome(string s) {
        // for lexicographically smallest and palindrome
        // each char at i should be also at size-1-i 
        // so that we need to split all chars in two halfs
        // anything left (one char or none) will be middle 
        // time n space 1

        // another approach is to use first half from string palindrome and reverse copy
        // time nlogn space 1 

        vector<int>freq(26,0);
        for(char &c:s){
            freq[c-'a']++;
        }
        string firstHalf;
        string secondHalf;
        for(int i=0;i<26;i++){
            firstHalf += string(freq[i]/2,'a'+i);
            secondHalf = string(freq[i]/2,'a'+i) + secondHalf;
            freq[i]-=2 * (freq[i]/2);
        }
        string middle;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1) {
                middle = 'a'+i;
            }
        }
        return firstHalf+middle+secondHalf;
    }
};