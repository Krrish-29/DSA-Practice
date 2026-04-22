// 2452. Words Within Two Edits of Dictionary
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        int size=dictionary.size(),strSize=dictionary[0].size();
        for(string &query:queries){
            for(int i=0;i<size;i++){
                int diff=0;
                for(int j=0;j<strSize;j++){
                    if(query[j]!=dictionary[i][j]) diff++;
                    if(diff>2) break;
                }
                if(diff<=2) {
                    ans.push_back(query);
                    break;
                }
            }
        }
        return ans;
    }
};