// 151. Reverse Words in a String
class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        string character;
        for(char ch:s){
            if(ch==' '){
                if(!character.empty()) words.push_back(character);
                character="";
            }
            else character+=ch;
        }
        if(!character.empty()) {
            words.push_back(character);
        }
        s="";
        for(int i=words.size()-1;i>0;i--){
            s+=(words[i]+" ");
        }
        s+=words[0];
        return s;
    }
};