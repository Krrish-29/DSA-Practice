// 3861. Minimum Capacity Box
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int size=capacity.size();
        int idx=-1;
        for(int i=0;i<size;i++){
            if(capacity[i]>=itemSize){
                if(idx==-1) idx=i;
                else if(capacity[idx]>capacity[i]) idx=i;
            }
        }
        return idx;
    }
};