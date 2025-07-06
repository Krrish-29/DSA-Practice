// 1865. Finding Pairs With a Certain Sum
class FindSumPairs {
    vector<int>_nums1,_nums2;
    map<int,int>freq_nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->_nums1=nums1;
        this->_nums2=nums2;
        int size=nums2.size();
        for(int i=0;i<size;i++){
            freq_nums2[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        freq_nums2[_nums2[index]]--;
        _nums2[index]+=val;
        freq_nums2[_nums2[index]]++;
    }
    
    int count(int tot) {
        int size=_nums1.size(),ans=0;
        for(int i=0;i<size;i++){
            ans+=freq_nums2[tot-_nums1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */