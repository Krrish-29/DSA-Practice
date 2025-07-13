// 2410. Maximum Matching of Players With Trainers
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int pSize=players.size(),tSize=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int res=0;
        for(int i=0,j=0;i<pSize&&j<tSize;j++){
            if(players[i]<=trainers[j]){
                i++;
                res++;
            }
        }
        return res;
    }
};