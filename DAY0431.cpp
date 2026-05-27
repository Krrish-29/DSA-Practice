// 3121. Count the Number of Special Characters II
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>first(26,-1),last(26,-1);// first occ of uppercase and last occ of lowercase
        for(int i=0;i<word.size();i++){
            if(word[i]<='z'&&word[i]>='a') last[word[i]-'a']=i;
            else if(word[i]<='Z'&&word[i]>='A'&&first[word[i]-'A']==-1) first[word[i]-'A']=i;
        }
        int count=0;
        for(int i=0;i<26;i++) {
            if(first[i]!=-1&&last[i]!=-1&&last[i]<first[i]) count++;
        }
        return count;
    }
};