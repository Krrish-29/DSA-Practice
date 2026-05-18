// 3932. Count K-th Roots in a Range
class Solution {
private:
    int binary_search(int target,int k){
        int left=0,right=1e9,mid,best;
        long long num;
        while(left<=right){
            mid=left+(right-left)/2;
            num=1;
            for(int i=0;i<k;i++){
                num*=mid;
                if(num>target) break;
            }
            if(num>target) {
                right=mid-1;
            }
            else if(num<=target){
                best=mid;
                left=mid+1;
            }
        }
        return best;
    }
public:
    int countKthRoots(int l, int r, int k) {
        // k* (n/2)
        // only base case is if k=1 then all nums are valid in l to r
        // else we do not need to worry about the 10^9 range because 
        // taking k=2 max we can go up to 31,622.7766016838 after that its power to 2 will exceed 10^9
        // int count=0,num;
        // if(k==1) return r-l+1;
        // for(int i=0;i<1e5;i++){
        //     num=1;
        //     for(int j=0;j<k;j++){
        //         num*=i;
        //     }
        //     if(num>r) break;
        //     else if(num>=l && num<=r) count++;
        // }
        // return count;

        // binary search approach 
        if(k==1) return r-l+1;
        int bestLeft=binary_search(l-1,k),bestRight=binary_search(r,k);
        return bestRight-bestLeft;
    }
};