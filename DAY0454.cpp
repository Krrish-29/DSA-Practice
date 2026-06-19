// 1732. Find the Highest Altitude
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude=0,currAltitude=0;
        for(int &g:gain){
            currAltitude+=g;
            maxAltitude=max(maxAltitude,currAltitude);
        }
        return maxAltitude;
    }
};