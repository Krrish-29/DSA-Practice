// 135. Candy
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size=ratings.size();
        vector<int>candy(size,1);
        for(int i=1;i<size;i++){
            if(ratings[i]>ratings[i-1]) candy[i]=candy[i-1]+1;
        }
        int answer=0;
        for(int i=size-1;i>0;i--){
            if (ratings[i-1]>ratings[i]&&candy[i-1]<=candy[i]) candy[i-1]=candy[i]+1;
            // answer+=candy[i-1];
        }
        for(int i=0;i<size;i++) answer+=candy[i];
        vector<int>().swap(candy);
        return answer;//+candy[size-1];
    }
};