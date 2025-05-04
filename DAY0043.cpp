// 1128. Number of Equivalent Domino Pairs
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int hashmap[100],size=dominoes.size(), answer=0;
            for(int i=0;i<size;i++){
                int index=min(dominoes[i][0],dominoes[i][1])*10+max(dominoes[i][0],dominoes[i][1]);
                answer+=hashmap[index];
                hashmap[index]++;
            }
            vector<vector<int>>().swap(dominoes);
            return answer; 
        }
    };