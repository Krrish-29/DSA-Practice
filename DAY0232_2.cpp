// 3740. Minimum Distance Between Three Equal Elements I
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // unordered_map<int,vector<int>>map;
        // int size=nums.size();
        // for(int i=0;i<size;i++){
        //     map[nums[i]].push_back(i);
        // }
        // int minVal=INT_MAX;
        // for(auto it:map){
        //     if(it.second.size()>2){
        //         vector<int>arr=it.second;
        //         int curr=abs(arr[0]-arr[1])+abs(arr[1]-arr[2])+abs(arr[0]-arr[2]);
        //         minVal=min(minVal,curr);
        //         for(int i=3;i<arr.size();i++){
        //             curr-=(abs(arr[i-3]-arr[i-2])+abs(arr[i-3]-arr[i-1]));
        //             curr+=(abs(arr[i-2]-arr[i])+abs(arr[i-1]-arr[i]));
        //             minVal=min(minVal,curr);
        //         }
        //     }
        // }
        // return minVal==INT_MAX?-1:minVal;
        int size=nums.size();
        vector<int>l1(size+1,-1),l2(size+1,-1);
        int minVal=INT_MAX;
        for(int i=0;i<size;i++){
            if(l2[nums[i]]!=-1){
                minVal=min(2*(i-l2[nums[i]]),minVal);
            }
            l2[nums[i]]=l1[nums[i]];
            l1[nums[i]]=i;
        }   
        return minVal==INT_MAX?-1:minVal; 
    }
};