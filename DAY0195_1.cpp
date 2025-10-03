// 42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        // O(n) space and O(n) time
        // int size=height.size();
        // vector<vector<int>>table(size,vector<int>(3,0));
        // table[0][0]=height[0];
        // table[size-1][1]=height[size-1];
        // for(int i=1;i<size;i++){
        //     table[i][0]=max(height[i],table[i-1][0]);
        // }
        // for(int i=size-2;i>=0;i--){
        //     table[i][1]=max(height[i],table[i+1][1]);
        // }
        // for(int i=0;i<size;i++){
        //     table[i][2]=min(table[i][0],table[i][1]);
        // }
        // int water=0;
        // for(int i=0;i<size;i++){
        //     if(table[i][2]-height[i]>0) water+=(table[i][2]-height[i]);
        // }
        // return water;

        // O(1) space and O(n) time
        int size=height.size();
        int maxL=height[0],maxR=height[size-1];
        int left=0,right=size-1;
        int water=0;
        while(left<=right){
            if(maxL<maxR){
                if(maxL-height[left]>0) water+=maxL-height[left];
                maxL=max(maxL,height[left]);
                left++;
            }
            else{
                if(maxR-height[right]>0) water+=maxR-height[right];
                maxR=max(maxR,height[right]);
                right--;
            }
        }
        return water;
    }
};