// 1967. Number of Strings That Appear as Substrings in Word
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        // unordered_set<string>pattern;
        // int size=word.size();
        // string str;
        // for(int i=0;i<size;i++){
        //     str="";
        //     for(int j=i;j<size;j++){
        //         str+=word[j];
        //         pattern.insert(str);
        //     }
        // }
        // int count=0;
        // for(string &str:patterns){
        //     if(pattern.find(str)!=pattern.end()) count++;
        // }
        // return count;
        int count=0;
        for(string &str:patterns){
            if(word.find(str)!=string::npos){
                count++;
            }
        }
        return count;
    }
};