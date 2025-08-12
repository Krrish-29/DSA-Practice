// 500. Keyboard Row
class Solution { 
public:
    bool checkRow(string s){
        int size=s.size();
        string row1="QWERTYUIOPqwertyuiop",row2="ASDFGHJKLasdfghjkl",row3="ZXCVBNMzxcvbnm";
        if(row1.contains(s[0])){
            for(int i=1;i<size;i++){
                if(!row1.contains(s[i])) return false;
            }
        }
        else if(row2.contains(s[0])){
            for(int i=1;i<size;i++){
                if(!row2.contains(s[i])) return false;
            }
        }
        else if(row3.contains(s[0])){
            for(int i=1;i<size;i++){
                if(!row3.contains(s[i])) return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        int size=words.size();
        for(int i=0;i<size;i++){
            if(!checkRow(words[i])){
                words.erase(words.begin()+i);
                i--;
                size--;
            }
        }
        return words;
    }
};