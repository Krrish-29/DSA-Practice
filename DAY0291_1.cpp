// 345. Reverse Vowels of a String
class Solution {
public:
    void swap(string &s,int left,int right){
        char ch=s[left];
        s[left]=s[right];
        s[right]=ch;
    }
    string reverseVowels(string s) {
        string vowel="aeiouAEIOU";
        int left=0,right=s.size()-1;
        // bool l=false,r=false;
        while(left<right){
            // if(vowel.find(s[left])!=string::npos) l=true;
            // if(vowel.find(s[right])!=string::npos) r=true;
            // if(!l) left++;
            // if(!r) right--;
            // if(l&&r) {
            //     swap(s,left,right);
            //     l=false;
            //     r=false;
            //     left++;
            //     right--;
            // }
            if(vowel.find(s[left])==string::npos) left++;
            else if(vowel.find(s[right])==string::npos) right--;
            else{
                swap(s,left,right);
                left++;
                right--;
            }
        }
        return s;
    }
};