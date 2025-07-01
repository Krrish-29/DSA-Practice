// 3330. Find the Original Typed String I
class Solution {
public:
    int possibleStringCount(string word) {
        int non_unique=0,size=word.size();
        for(int i=1;i<size;i++){
            if(word[i-1]==word[i]) non_unique++;
        }
        return non_unique+1;
    }
};