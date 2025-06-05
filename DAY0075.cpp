// 67. Add Binary
class Solution {
public:
    string addBinary(string &a, string &b) {
        int sizeA=a.length(),sizeB=b.length();
        if(sizeA>sizeB) {
            swap(b,a);
            swap(sizeB,sizeA);
        }
        int carry=0;
        while(--sizeA>=0){
            b[--sizeB]+=(a[sizeA]-'0'+carry);
            carry=0;
            if(b[sizeB]>='2'){
                carry=1;
                b[sizeB]-=2;
            }
        }
        while(sizeB--){
            b[sizeB]+=(carry);
            carry=0;
            if(b[sizeB]>='2'){
                carry=1;
                b[sizeB]-=2;
            }
        }
        if(carry==1) b.insert(b.begin(),'1');
        return b;
    }
};