// 3403. Find the Lexicographically Largest String From the Box I
class Solution {
private:
    int getMaxLexStrLen(string & s){
        int i=0,j=1;
        int size=s.size();
        while(j<size){
            if(s[i]<s[j]) i=j;//if u get better start a j make i=j
            else if(s[i]==s[j]){// if u get similar start at j find which will output better  
                int k=1;
                while(j+k<size){
                    if(s[i]<s[j+k]){//if u get a whole lot better elem than i at j+k
                        j+=k;i=j;break;
                    }
                    if(s[i+k]==s[j+k]) k++; // if u get same comparison elems start again
                    else {
                        if(s[i+k]<s[j+k]) i=j; // if u get a better results with starting from j
                        break;                 // cause elem at i+k < j+k 
                    } 
                }
            }
            j++;
        }
        return i;
    }
public:
    string answerString(string word, int numFriends) {
        // simple approach just find the best point to start the string 
        // if u get better start at j move i to j
        // if u get a similar start at i & j find which will be better by comparing next elems
        // also check if u get even better elem at any point while comparing the next elems of i and j than i
        if(numFriends==1) return word;
        int size=word.size();
        int maxLen=size-numFriends+1;
        int len=getMaxLexStrLen(word);
        // sub with maxLen to get the string size in control
        return (word.substr(len)).substr(0,maxLen);
    }
};