// 38. Count and Say
class Solution {
    public:
        string countAndSay(int n) {
            string answer="1";
            for(int i=0;i<n-1;i++){
                int count=1;
                string newstr="";
                int j;
                for(j=1;j<answer.size();j++){
                    if(answer[j]==answer[j-1]) {count++;}
                    else {
                        newstr+=(to_string(count)+answer[j-1]);
                        count=1;
                    }
                }
                newstr+=(to_string(count)+answer[j-1]);
                answer=newstr;
            }
            return answer;
        }
    };