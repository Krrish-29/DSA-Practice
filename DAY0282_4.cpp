// 875. Koko Eating Bananas
class Solution {
private:
    int pileTime(vector<int>&piles,int time){
        int count=0;
        for(int num:piles){
            count+=(num+time-1)/time;
        }
        return count;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size=piles.size();
        long long minSpeed=0,maxSpeed=0,midSpeed;
        for(int num:piles){
            if(maxSpeed<=num) maxSpeed=num;
            minSpeed+=num;
        }
        minSpeed=(minSpeed+h-1)/h;
        while(minSpeed<maxSpeed){
            midSpeed=minSpeed+(maxSpeed-minSpeed)/2;
            if(pileTime(piles,midSpeed)>h) minSpeed=midSpeed+1;
            else maxSpeed=midSpeed;
        }
        return minSpeed;
    }
};