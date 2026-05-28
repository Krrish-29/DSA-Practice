// 3120. Count the Number of Special Characters I
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>seen(26,0); // 1 -> small seen , 2 -> capital seen , 3 -> both seen
        for(char &c:word){
            if(c<='z'&&c>='a'&&seen[c-'a']!=3){
                if(seen[c-'a']==2) seen[c-'a']=3;
                else seen[c-'a']=1;
            }
            else if(c<='Z'&&c>='A'&&seen[c-'A']!=3){
                if(seen[c-'A']==1) seen[c-'A']=3;
                else seen[c-'A']=2;
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(seen[i]==3) count++;
        }
        return count;
    }
};  