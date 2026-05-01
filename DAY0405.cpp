// 396. Rotate Function
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // 4 3 2 6
        // 0 1 2 3 -> 25
        // 3 0 1 2 -> 26
        // 2 3 0 1 -> 23
        // 1 2 3 0 -> 16

        // simple thought make the coeff rotate make array fixed
        // then see that current elem and its forw elems coeff are decrease by 1
        // only the prev of the curr elem is increased by size-1 times and the 
        // coeff of elems prev to that as well decrease by 1 (except the idx 0 case)
        // use prefix and suffix to store that sum so that we can decrease instantly

        int size=nums.size();
        int total=0;
        vector<int>prefix(size,0),suffix(size,0);
        prefix[0]=nums[0];
        for(int i=1;i<size;i++){
            prefix[i]=prefix[i-1]+nums[i];
            total+=(i*nums[i]);
        }
        suffix[size-1]=nums[size-1];
        for(int i=size-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        int maxVal=total;
        for(int i=1;i<size;i++){
            total+=(nums[i-1]*(size-1));
            total-=suffix[i];
            if(i-2>=0) total-=prefix[i-2];
            maxVal=max(maxVal,total);
        }
        return maxVal;
    }
};