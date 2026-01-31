// 3823. Reverse Letters Then Special Characters in a String
class Solution {
private:
    void reverse(vector<pair<char,int>>&str){
        int size=str.size();
        for(int i=0;i<size/2;i++){
            int temp=str[i].second;
            str[i].second=str[size-1-i].second;
            str[size-1-i].second=temp;
        }
    }
public:
    string reverseByType(string s) {
       vector<pair<char,int>>chars1,chars2;
        int size=s.size();
        for(int i=0;i<size;i++){
            if(s[i]<='z'&&s[i]>='a')  chars1.push_back({s[i],i});
            else chars2.push_back({s[i],i});
        }
        reverse(chars1);
        reverse(chars2);
        for(int i=0;i<chars1.size();i++){
            auto temp=chars1[i];
            s[temp.second]=temp.first;
        }
        for(int i=0;i<chars2.size();i++){
            auto temp=chars2[i];
            s[temp.second]=temp.first;
        }
        return s;
    }
};