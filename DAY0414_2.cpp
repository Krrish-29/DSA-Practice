// 3926. Count Valid Word Occurrences
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
         unordered_map<string,int>map;
        string total;
        for(auto &s:chunks){
            total+=s;
        }
        int size=total.size();
        string curr;
        for(int i=0;i<size;i++){
            if(total[i]>='a'&&total[i]<='z') curr+=total[i];
            else if(total[i]=='-'&&i>0&&i+1<size&&total[i-1]>='a'&&total[i-1]<='z'&&total[i+1]>='a'&&total[i+1]<='z') curr+=total[i];
            else{
                map[curr]++;
                curr="";
            }
        }
        map[curr]++;
        vector<int>ans;
        for(auto &query:queries){
            ans.push_back(map[query]);
        }
        return ans;
    }
};