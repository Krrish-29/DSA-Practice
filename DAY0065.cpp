// 131. Palindrome Partitioning
class Solution {
public:
    bool isPalindrome(string &s,int left,int right){
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            right--;
            left++;
        }
        return true;
    }
    void back_track(string &s,int start,vector<string>&temp,vector<vector<string>>&answer){
        if(start==s.size()){
            answer.push_back(temp);
            return ;
        }
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                back_track(s,i+1,temp,answer);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>answer;
        vector<string>temp;
        back_track(s,0,temp,answer);
        return answer;
    }
};