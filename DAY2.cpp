// 14. Longest Common Prefix
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            std::sort(strs.begin(), strs.end());
            std::string answer;//,str1=strs[0],str2=strs[];
            for(int i=0;i<strs[0].length();i++){
                if(strs[0][i]==strs[strs.size()-1][i]){
                    answer+=(strs[0][i]);
                }
                else{
                    break;
                }
            }
    
            return answer;
        }
    };  