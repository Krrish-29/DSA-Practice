// 3876. Construct Uniform Parity Array II
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int>even,odd;
        for(int &num:nums1){
            if(num%2==0) even.push_back(num);
            else odd.push_back(num);
        }
        if(even.size()==0||odd.size()==0) return true;
        sort(odd.begin(),odd.end());
        for(int &num:even){
            auto it=lower_bound(odd.begin(),odd.end(),num);
            if(it!=odd.begin()){
                --it;
            }
            // printf("%d %d\n",*it,num);
            if(*it>num) return false;
        }
        return true;
    }
};