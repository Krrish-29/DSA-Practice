// 2251. Number of Flowers in Full Bloom
class Solution {
private:
    int upperBound(vector<int>&nums,int target){
        int left=0,right=nums.size(),mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]<=target) left=mid+1;
            else right=mid;
        }
        return left;
    }
    int lowerBound(vector<int>& nums,int target){
        int left=0,right=nums.size(),mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]<target) left=mid+1;
            else right=mid;
        }
        return left;
    }
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>sortedStart,sortedEnd;
        for(vector<int> &flower:flowers){
            sortedStart.push_back(flower[0]);
            sortedEnd.push_back(flower[1]);
        }
        sort(sortedStart.begin(),sortedStart.end());
        sort(sortedEnd.begin(),sortedEnd.end());
        for(int &p:people){
            p=upperBound(sortedStart,p)-lowerBound(sortedEnd,p);
            // p=lowerBound(sortedStart,p+1)-lowerBound(sortedEnd,p);
        }
        return people;
    }
};