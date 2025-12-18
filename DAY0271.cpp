// 3755. Find Maximum Balanced XOR Subarray Length
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int,int>,int>map;
        map[{0,0}]=-1;
        int size=nums.size();
        int diff=0;
        int pxor=0;
        int ans=0;
        for(int i=0;i<size;i++){
            pxor^=nums[i];
            if(nums[i]%2==0) diff++;
            else diff--;
            pair<int,int>key={pxor,diff};
            if(map.find(key)!=map.end()){
                ans=max(ans,i-map[key]);
            }
            else {
                map[key]=i;
            }
        }
        return ans;
    }
};