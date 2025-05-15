// 2900. Longest Unequal Adjacent Groups Subsequence I
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int size=groups.size();
        if(size==1) return words;
        vector<string>answer;
        answer.push_back(words[0]);
        for(int i=1;i<size;i++){
            if(groups[i]!=groups[i-1]){
                answer.push_back(words[i]);
            }
        }
        return answer;
    }
};


class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int i=0;
        while(i<groups.size()-1){
            if(groups[i]==groups[i+1]){
                words.erase(words.begin()+i);
                groups.erase(groups.begin()+i);
            }
            else{
                i++;
            }
        }
        return words;
    }
};