// 1482. Minimum Number of Days to Make m Bouquets
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int minDays=*min_element(bloomDay.begin(),bloomDay.end()),
        maxDays=*max_element(bloomDay.begin(),bloomDay.end()),midDays,size=bloomDay.size();
        if(size<m*1LL*k) return -1;
        while(minDays<=maxDays){
            midDays=minDays+(maxDays-minDays)/2;
            int count=0,bouquet=0;
            for(int i=0;i<size;i++){
                if(bloomDay[i]<=midDays){
                    count++;
                }
                else{
                    bouquet+=count/k;
                    count=0;
                } 
            }
            bouquet+=count/k;
            if(bouquet>=m) maxDays=midDays-1;
            else minDays=midDays+1;
        }
        return minDays;
    }
};