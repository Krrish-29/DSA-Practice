// 189. Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size(),temp,current,prev;
        if(k==0||size==1) return;
        k%=size;
        for(int count=0,start=0;count<size;start++){
            current=start;
            prev=nums[start];
            do{
                temp=nums[(current+k)%size];
                nums[(current+k)%size]=prev;
                prev=temp;
                current=(current+k)%size;
                count++;
            }while(current!=start);
        }
    }
};