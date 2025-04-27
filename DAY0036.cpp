// 11. Container With Most Water
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left_wall=0,right_wall=height.size()-1,max_amount=0;
            while(left_wall<right_wall){
                max_amount=max(min(height[left_wall],height[right_wall])*(right_wall-left_wall),max_amount);
                height[left_wall]<height[right_wall]?left_wall++:right_wall--;
            }
            height.clear();
            height.shrink_to_fit();
            return max_amount;
        }
    };