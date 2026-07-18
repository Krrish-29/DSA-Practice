// 633. Sum of Square Numbers
class Solution {
public:
    bool judgeSquareSum(int c) {
        // brute force
        // unordered_set<long long>set;
        // // 2^31 is smaller than 10^10 and then at max a or b can reach to 10^5
        // for(long long i=0;i<=10e5;i++){
        //     if(set.count(i*i)) return true;
        //     if(2*(i*i)==c) return true;// missing case
        //     if(c>=(i*i)) set.insert(c-(i*i));
        // }
        // return false;

        // optimization
        // since the left and right cannot physically more than sqrt of c 
        // and if sum is more than c than right has to be decreased 
        // and if sum is less than c than left has to be increase 
        // to cover the difference
        long long left=0,right=sqrt(c);
        long long sum;
        while(left<=right){
            sum = (left*left) + (right*right);
            if(sum==c) return true;
            if(sum>c) right--;
            else left++;
        }
        return false;
    }
};