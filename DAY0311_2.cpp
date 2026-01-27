// 1552. Magnetic Force Between Two Balls
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int size=position.size();
        int minDist=1,maxDist=position[size-1]-position[0],midDist;
        while(minDist<=maxDist){
            midDist=minDist+(maxDist-minDist)/2;
            int prev=position[0],balls=1;
            for(int i=1;i<size;i++){
                if(position[i]-prev>=midDist) {
                    prev=position[i];
                    balls++;
                }
                if(balls==m) break;
            }
            if(balls>=m) minDist=midDist+1;
            else maxDist=midDist-1;
        }
        return minDist-1;
    }
};