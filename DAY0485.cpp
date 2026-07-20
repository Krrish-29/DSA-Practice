// 3992. Rearrange String to Avoid Character Pair
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        // string permutation;
        // for(char &ch:s){
        //     if(ch==y) permutation = y + permutation ;
        //     else permutation+=ch;
        // }
        // return permutation;
        int left=0,right=s.size()-1,size=s.size();
        while(left<size||right>=0){
            while(left<=size){
                if(s[left]==x) break;
                left++;
            }
            while(right>=0){
                if(s[right]==y) break;
                right--;
            }
            if(left<right) swap(s[left],s[right]);
            else break;
            left++;
            right--;
        }
        return s;
    }
};