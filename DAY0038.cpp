// 9. Palindrome Number
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         // if(x<0 ||(x%10==0&&x!=0)) return false;
//         int num=x;
//         long temp=0;
//         while(num>0){
//             temp=(num%10)+temp*10;
//             num/=10;
//         }
//         if(temp==x) return true;
//         return false;
//     }
// };
class Solution {
    public:
        bool isPalindrome(int x) {
            if(x<0||(x%10==0&&x!=0)) return false;   
            int temp=0;
            while(x>temp){
                temp=(x%10)+temp*10;
                x/=10;
            }
            return temp==x||temp/10==x;
        }
    };