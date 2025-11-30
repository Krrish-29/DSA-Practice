// 3494. Find the Minimum Amount of Time to Brew Potions
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        // int potSize=mana.size(),skillSize=skill.size();
        // vector<long>prevTime(skillSize+1,0);
        // long long prev=0;
        // for(int i=0;i<potSize;i++){
        //     vector<long>currTime(skillSize+1,0);
        //     long long curr=prevTime[1]+prev;
        //     for(int j=1;j<skillSize;j++) {
        //         currTime[j]=(currTime[j-1]+skill[j-1]*mana[i]);
        //         curr=max(curr,prevTime[j+1]+prev-currTime[j]);
        //     }   
        //     currTime[skillSize]=(currTime[skillSize-1]+skill[skillSize-1]*mana[i]);
        //     prevTime=currTime;
        //     prev=curr;
        // }
        // return prevTime[skillSize]+prev;
        int potSize=mana.size(),skillSize=skill.size();
        vector<long>prevTime(skillSize+1,0);
        long long prevDiff=0,currDiff;
        for(int i=0;i<potSize;i++){
            currDiff=prevTime[1]+prevDiff;
            long temp;
            for(int j=1;j<skillSize;j++) {
                temp=(prevTime[j-1]+skill[j-1]*mana[i]);
                currDiff=max(currDiff,prevTime[j+1]+prevDiff-temp);
                prevTime[j]=temp;
            }   
            prevTime[skillSize]=(prevTime[skillSize-1]+skill[skillSize-1]*mana[i]);
            prevDiff=currDiff;
        }
        return prevTime[skillSize]+prevDiff;
    }
};