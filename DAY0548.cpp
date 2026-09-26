// 4054. Count Shadow Pairs I
class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        // brute force 
        // since we go from i+1 to n for j and we need to make sure any k in b/w is not less than nums[i] , if found then break
        // and if nums[i]<nums[j] count++;
        long long pairs=0;
        int size=nums.size();
        // for(int i=0;i<size;i++){
        //     for(int j=i+1;j<size;j++){
        //         if(nums[i]<nums[j]) pairs++;
        //         else if(nums[i]>nums[j]) break;
        //     }
        // }
        // return pairs;

        // any elems greater before than curr nums[i] will be usless (cannot be used to make any pair because of nums[i] being smaller than prev elems)
        // also the copy of the curr nums[i] seen before cannot be used with the curr other prev can be used
        // therefore it is monotonic stack since elems will increase in it or stay same
        // to migitate counting same elem pairs we can use pair to store nums[i] and freq

        vector<pair<int,int>>store;// num , freq
        store.push_back({nums[0],1});
        int storeSize=1;
        for(int i=1;i<size;i++){
            while(!store.empty() && store.back().first>nums[i]) { // keeping monotonic stack consistent
                storeSize-=store.back().second;
                store.pop_back();
            }
            if(store.empty() || store.back().first != nums[i]){ // storing new elem and counting pairs formed using this with prev elems 
                pairs+=storeSize;
                store.push_back({nums[i],1});
            }
            else{ // same elems added so increment freq only and count pairs excluding the curr duplicate
                pairs+=(storeSize-store.back().second);
                store.back().second++;
            }
            storeSize++;
        }
        return pairs;
    }
};