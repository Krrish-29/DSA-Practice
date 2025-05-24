// 2942. Find Words Containing Character
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>answer;
        int size=words.size();
        for(int i=0;i<size;i++){
            int wordLength=words[i].size();
            for(int j=0;j<wordLength;j++){
                if(words[i][j]==x) {
                    answer.push_back(i);
                    break;
                }
            }
        }
        return answer;
    }
};