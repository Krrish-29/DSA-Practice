// 3474. Lexicographically Smallest Generated String
class Solution {
public:
    string generateString(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        // for every true make changes to the ans and if there exists a overlap b/w two values in ans
        // then return ""
        // then make all left elems as 'a'
        // then check if any false is true because of that and then try to move from right to left
        // from that i+n-1 to i any if you can change any elem to make true to back false
        // else return ""
        string ans(m+n-1,'0');
        vector<bool>change(m+n-1,true);
        for(int i=0;i<m;i++){
            if(str1[i]=='T'){
                int j=i;
                for(int idx=0;idx<n;idx++){
                    if(ans[j]!='0'&&ans[j]!=str2[idx]) return "";
                    ans[j]=str2[idx];
                    change[j]=false;
                    j++;
                }
            }
        }
        for(int i=0;i<m+n-1;i++){
            if(ans[i]=='0') ans[i]='a';
        }
        for(int i=0;i<m;i++){
            if(str1[i]=='F'){
                if(str2==ans.substr(i,n)){
                    bool flag=true;
                    for(int j=i+n-1;j>=i;j--){
                        if(change[j]==true){
                            ans[j]++;
                            flag=false;
                            break;
                        }
                    }
                    if(flag) return "";
                }
            }
        }
        return ans;
    }
};