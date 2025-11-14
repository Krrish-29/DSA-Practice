// 3738. Longest Non-Decreasing Subarray After Replacing at Most One Element
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // int size=nums.size();
        // int start=0,end;
        // vector<vector<int>>points;
        // for(int i=1;i<size;i++){
        //     if(nums[i-1]>nums[i]){
        //         points.push_back({start,i-1});
        //         start=i;
        //     }
        // }
        // points.push_back({start,size-1});
        // int pSize=points.size();
        // if(pSize==1) return points[0][1]-points[0][0]+1;
        // int maxSize=0;
        // for(int i=1;i<pSize;i++){
        //     if(((points[i-1][1]-points[i-1][0]==0)||(points[i][1]-points[i][0]==0))||((nums[points[i-1][1]-1]<=nums[points[i][0]])||(nums[points[i-1][1]]<=nums[points[i][0]+1]))){
        //         maxSize=max(maxSize,points[i][1]-points[i-1][0]+1);
        //     }
        //     maxSize=max({maxSize,points[i-1][1]-points[i-1][0]+2,points[i][1]-points[i][0]+2});
        // }
        // return maxSize;



        //compressed version
        int size=nums.size();
        int maxSize=0,end=0,prev=0;
        for(int i=1;i<=size;i++){
            if(i==size||nums[i-1]>nums[i]){
                maxSize=max(maxSize,i-end+1);
                if(end>1&&nums[end-2]<=nums[end]) maxSize=max(maxSize,i-end+prev);
                if(end>0&&end+1<i&&nums[end-1]<=nums[end+1]) maxSize=max(maxSize,i-end+prev);
                prev=i-end;
                end=i;
            }
        }    
        return min(size,maxSize);
    }
};