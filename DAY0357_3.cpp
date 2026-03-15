// 3868. Minimum Cost to Equalize Arrays Using Swaps
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        int size=nums1.size();
        for(int i=0;i<size;i++){
            map1[nums1[i]]++;
        }
        for(int i=0;i<size;i++){
            map2[nums2[i]]++;
        }
        if(map1==map2) return 0;
        for(auto [key,f1]:map1){
            int f2=map2[key];
            if((f1+f2)%2==1) return -1;
        }
        for(auto [key,f2]:map2){
            int f1=map1[key];
            if((f1+f2)%2==1) return -1;
        }
        int op=0;
        for(auto [key,f1]:map1){
            int f2=map2[key];
            map2[key]=f1;
            op+=abs(f1-f2)/2;
            
        }
        for(auto [key,f2]:map2){
            int f1=map1[key];
            map1[key]=f2;
            op+=abs(f1-f2)/2;
        }
        return op/2;
    }
};