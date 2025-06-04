// 3403. Find the Lexicographically Largest String From the Box I
class Solution {
public:
    string answerString(string word, int numFriends) {
        // int size=word.size();
        // if(numFriends==1) return word;
        // string answer="";
        // for(int i=0;i<size;i++){
        //     if(word.substr(i,size-numFriends+1)>answer){
        //         answer=word.substr(i,size-numFriends+1);
        //     }
        // }
        // return answer;
        if(numFriends==1) return word;
        const size_t size=word.length()-numFriends+1;
        const string str=subString(word);
        return str.substr(0,min(str.length(),size));
    }
    string subString(string s){
        int i=0,j=1,k=0;
        while(j+k<s.length()){
            if(s[i+k]==s[j+k]){
                k++;
            }
            else if(s[i+k]>s[j+k]){
                j=j+k+1;
                k=0;
            }
            else{
                i=max(i+k+1,j);
                j=i+1;
                k=0;
            }
        }
        return s.substr(i);
    }
};