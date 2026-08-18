// 3471. Find the Largest Almost Missing Integer
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int size=nums.size();
        vector<int>map(51,0);
        for(int i=0;i<=size-k;i++){
            vector<bool>seen(51,false);
            for(int j=i;j<i+k;j++){
                seen[nums[j]]=true;
            }
            for(int x=0;x<=50;x++){
                if(seen[x]) map[x]++;
            }
        }
        for(int i=50;i>=0;i--){
            if(map[i]==1) return i;
        }
        return -1;
    }
};