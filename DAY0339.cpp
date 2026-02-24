// 60. Permutation Sequence
class Solution {
private:
    vector<string>perms;
    void getPerm(int n,vector<int>freq,string s){
        if(s.size()==n) {
            perms.push_back(s);
        }
        else{
            for(int i=1;i<=n;i++){
                if(freq[i-1]!=1){
                    freq[i-1]=1;
                    getPerm(n,freq,s+to_string(i));
                    freq[i-1]=0;
                }
            }
        }
        return ;
    }
public:
    string getPermutation(int n, int k) {
        // vector<int>freq(n,0);
        // getPerm(n,freq,"");
        // return perms[k-1];
        vector<int>nums(n,0);
        vector<int>factorials(n,1);
        for(int i=0;i<n;i++) {
            nums[i]=i+1;
            if(i>0) factorials[i]=factorials[i-1]*i;
        }
        string s;
        k--;
        while(nums.size()!=0){
            int x=k/factorials[n-1];
            s+=to_string(nums[x]);
            nums.erase(nums.begin()+x);
            k-=(x*factorials[n-1]);
            n--;
            printf("%d %d %d\n",x,k,n);
        }
        return s;
    }
};