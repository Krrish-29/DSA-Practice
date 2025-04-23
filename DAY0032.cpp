// 5. Longest Palindromic Substring
class Solution {
    public:
        string longestPalindrome(string s) {
            string s1="#";
            for(char ch : s){
                s1+=(ch+string("#"));
            }
            int size=s1.size(),C=0,R=0;
            vector<int>check(size,0);
            for(int i=0;i<size;i++){
                if(i<R) {
                    check[i]=min(check[2*C-i],R-i);
                }
                while(i+check[i]+1<size&&i-check[i]-1>=0&&s1[i+check[i]+1]==s1[i-check[i]-1]){
                    check[i]++;
                }
                if(i+check[i]>R){
                    C=i;
                    R=check[i]+i;
                }
            }
            C=0,R=0;
            for(int i=0;i<size;i++){
                if(check[i]>R){
                    R=check[i];
                    C=i;
                }
            }
            return s.substr((C-R)/2 ,R); 
        }
    };