// 799. Champagne Tower
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>prev(1,poured);
        for(int i=1;i<=query_row;i++){
            vector<double>current(i+1,0.0);
            for(int j=0;j<i;j++){
                if(prev[j]>1){
                    double extra=(prev[j]-1)/2.0;
                    current[j]+=extra;
                    current[j+1]+=extra;
                }
            }
            prev=current;
        }
        return min(1.0,prev[query_glass]);
    }
};