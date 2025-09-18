// 17. Letter Combinations of a Phone Number
class Solution {
private:
    vector<string>num={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void backTrack(string digits,vector<string>&answer,int index){
        if(digits.size()==index) return ;
        vector<string>temp;
        if(answer.empty()){
            for(char ch:num[digits[index]-'0']){
                temp.push_back(string(1,ch));
            }
        }
        else{
            for(string &s:answer){
                for(char ch:num[digits[index]-'0']){
                    temp.push_back(s+ch);
                }
            }
        }
        answer=temp;
        backTrack(digits,answer,index+1);
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>answer;
        backTrack(digits,answer,0);
        return answer;
    }
};