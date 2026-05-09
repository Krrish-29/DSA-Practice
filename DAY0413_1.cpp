// 3921. Score Validator
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0,counter=0;
        for(auto &str:events){
            if(str>="0"&&str<="6") score+=stoi(str);
            else if(str=="W") counter++;
            else if(str=="WD"||str=="NB") score++;
            if(counter==10) break;
        }
        return {score,counter};
    }
};