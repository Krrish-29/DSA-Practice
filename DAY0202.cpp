// 3147. Taking Maximum Energy From the Mystic Dungeon
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int size=energy.size(),maxEnergy=INT_MIN;
        for(int i=size-1-k;i>=0;i--){
            energy[i]+=energy[i+k];
        }
        for(int i=0;i<size;i++) maxEnergy=max(maxEnergy,energy[i]);
        return maxEnergy;
    }
};