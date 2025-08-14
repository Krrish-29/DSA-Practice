// 1545. Find Kth Bit in Nth Binary String
class Solution {
public:
    char findKthBit(int n, int k) {
        stack<int>stack;
        stack.push(1);
        for(int i=1;i<n;i++){
            stack.push(2*stack.top()+1);
        }
        k--;
        int shift=0,size;
        while(!stack.empty()&&stack.top()>1){
            size=stack.top()-1;
            stack.pop();
            if(k>size/2){
                shift++;
                k=(size-k);
            }
            else if(k==size/2){
                return (shift%2==0?'1':'0');
            }
        }
        return (shift%2==0?'0':'1');
    }
};