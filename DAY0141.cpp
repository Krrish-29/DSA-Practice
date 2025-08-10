// 869. Reordered Power of 2
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num=to_string(n);

        vector<int>nums(10,0);
        int size=num.size();
        for(char ch:num) nums[ch-'0']++;

        // precomputing powers of 2 and hashing
        // vector<string>power={"1","2","4","16","32","64","128","256","512","1024","2048","4096","8192","16384","32768","65536","131072","262144","524288","1048576","2097152","4194304","8388608","16777216","33554432","67108864","134217728","268435456","536870912","1073741824"};
        // int idx=0;
        // for(string s:power){
        //     if(s.size()==size) break;
        //     idx++;
        // }
        // while(idx<30&&power[idx].size()==size){
        //     vector<int>current(10,0);
        //     for(char ch:power[idx]) current[ch-'0']++;
        //     if(nums==current) return true;
        //     idx++;
        // }

        // computing power of 2 on the fly with hashing
        for(int i=0;i<30;i++){
            vector<int>current(10,0);
            string power=to_string(1<<i);
            for(char ch:power) current[ch-'0']++;
            if(nums==current) return true;
        }


        //  sorting approach 
        // sort(num.begin(),num.end());
        // for(int i=0;i<30;i++){
        //     string curr=to_string(1<<i);
        //     sort(curr.begin(),curr.end());
        //     if(curr==num) return true;
        // }

        return false;
    }
};