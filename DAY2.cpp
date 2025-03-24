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
        // string longestCommonPrefix(vector<string>& strs) {
        //     for(int i=1;i<strs.size();i++){
        //         if(strs[i].length()==0){
        //             strs[0]="";
        //             break;
        //         }
        //         if(strs[i].size()<strs[0].size()){
        //             strs[0].erase(strs[i].size(),strs[0].size()-strs[i].size());
        //         }
        //         for(int j=0;j<strs[i].size()&&j<strs[0].size();j++){
        //             if(strs[i][j]!=strs[0][j]){
        //             strs[0].erase(j);
        //             break;
        //             }
        //         }
        //     }
        //     return strs[0];
        // }
    };  