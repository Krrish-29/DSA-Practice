// 1833. Maximum Ice Cream Bars
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // nlogn time , 1 space
        // sort(costs.begin(),costs.end());
        // int bars=0,idx=0;
        // while(coins>0&&idx<costs.size()){
        //     if(costs[idx]>coins) break;
        //     coins-=costs[idx];
        //     idx++;
        //     bars++;
        // }
        // return bars;

        // n time , n space
        int maxEle=INT_MIN;
        for(int &cost:costs){
            maxEle=max(maxEle,cost);
        }
        vector<int>freq(maxEle+1,0);
        for(int &cost:costs){
            freq[cost]++;
        }
        int bars=0,bought;
        for(int cost=1;cost<=maxEle;cost++){
            if(cost>coins) break;
            bought=min(coins/cost,freq[cost]);// min(how many can u buy, how many are available)
            bars+=bought;
            coins-=cost*(bought);
        }
        return bars;
    }
};