// 3494. Find the Minimum Amount of Time to Brew Potions
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        // preprocess the time
        vector<long long>prev(skill.size()+1,0);
        vector<long long>curr(skill.size()+1,0);
        long long diff=0;
        for(int j=0;j<skill.size();j++){
            prev[j+1]=prev[j]+(mana[0]*skill[j]);
        }
        // simply calculate the time for curr potion starting from 0
        // then check how much time does we need to shift the start to fix any collisions
        // then recalculate the time with that diff
        for(int i=1;i<mana.size();i++){
            for(int j=0;j<skill.size();j++){
                curr[0]=0;
                curr[j+1]=curr[j]+(mana[i]*skill[j]);
                diff=max(diff,prev[j+1]-curr[j]);
            }
            curr[0]=diff;
            for(int j=0;j<skill.size();j++){
                curr[j+1]=curr[j]+(mana[i]*skill[j]);
            }
            prev=curr;
        }
        return prev[skill.size()];
    }
};