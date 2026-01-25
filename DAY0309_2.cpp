// 3819. Rotate Non Negative Elements
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>temp;
        for(int &num:nums){
            if(num>=0) {
                temp.push_back(num);
                num=INT_MAX;
            }
        }
        int size=temp.size();
        if(size==0) return nums;
        k%=size;
        for(int start=0,current,count=0,prev,t;count<size;start++){
            current=start;
            prev=temp[start];
            do{
                t=temp[(current-k+size)%size];
                temp[(current-k+size)%size]=prev;
                prev=t;
                count++;
                current=(current-k+size)%size;
            }while(start!=current);
        }
        int i=0;
        for(int &num:nums){
            if(num==INT_MAX) {
                num=temp[i];
                i++;
            }
        }
        return nums;
    }
};