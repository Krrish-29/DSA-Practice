// 189. Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        k%=size;
        for(int start=0,current,count=0,prev,temp;count<size;start++){
            current=start;
            prev=nums[start];
            do{
                temp=nums[(current+k)%size];
                nums[(current+k)%size]=prev;
                prev=temp;
                count++;
                current=(current+k)%size;
            }while(start!=current);
        }
    }
};