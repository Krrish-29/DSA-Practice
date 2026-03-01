// 3852. Smallest Pair With Different Frequencies
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int>freq(100,0);
        int first=-1,second=-1;
        for(int &num:nums){
            freq[num-1]++;
        }
        for(int i=0;i<100;i++){
            if(freq[i]!=0&&first==-1){
                first=i+1;
            }
            else if(first!=-1&&freq[i]!=0&&freq[first-1]!=freq[i]){
                second=i+1;
                break;
            }
        }
        if(first==-1||second==-1) return {-1,-1};
        return {first,second};
    }
};