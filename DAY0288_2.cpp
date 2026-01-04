// 3799. Word Squares II
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int size=words.size(),count=0;
        vector<vector<string>>ans;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i==j) continue;
                for(int k=0;k<size;k++){
                    if(j==k||i==k) continue;
                    for(int l=0;l<size;l++){
                        if(l==i||l==j||l==k) continue;
                        string top=words[i],bottom=words[l],left=words[j],right=words[k];
                        if(top[0]==left[0]&&top[3]==right[0]&&bottom[0]==left[3]&&bottom[3]==right[3])
                            ans.push_back({top,left,right,bottom});
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};