// 7. Reverse Integer
class Solution {
    public:
        int reverse(int x) {
            long reverse=0,sign=(x>0?1:-1);
            x=x*sign;
            while(x>0){
                reverse=(x%10)+reverse*10;
                if(reverse>INT_MAX) return 0;
                x/=10;
            }
            return reverse*sign;
        }
    };