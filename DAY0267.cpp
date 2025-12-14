// 374. Guess Number Higher or Lower
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left=0,right=n,mid,g;
        while(true){
            mid=left+(right-left)/2;
            g=guess(mid);
            if(g==0) return mid;
            else if(g==-1) right=mid-1;
            else left=mid+1;
        }
        return 0;
    }
};