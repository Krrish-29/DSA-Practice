// 1611. Minimum One Bit Operations to Make Integers Zero
class Solution {
private:
    int getSetBit(int &n){
        for(int i=31;i>=0;i--){
            if((n>>i)&1) return i;
        }
        return -1;
    }
public:
    int minimumOneBitOperations(int n) {
        // using trial and error , what i found is that 
        // we can convert a 1000 -> 0100 in just 2^3 operations and also the set bit is at 2^3
        // but this can be only done when the prevBit of the MSB is 0 
        // else the situation is like 1100___ , then using 1 operation it becomes 01____
        // considering all ___ are zero , so we can recursively call on 0100 and also ___ to be coverted to 0
        // so what we do is first get MSB index if its -1 then no MSB return 0 
        // if 1 then the MSB is at last position and we need only 1 operation , 1 -> 0 (last bit can be freely fliped)
        // else we find the prevBit of the MSB
        // if its not set then simple remove the MSB and shift it using n^num1^num2
        // where num1 is the 1<<MSB index and num2 is 1<< (MSB index-1)
        // so doing n^num1^num2 removes MSB and shifts it to right 
        // if the prevBit is set as well then the procedure becomes 
        // to remove all ones to the right of prevBit and then shift 11 to 01 in 1 operation 
        // and since 01000 is still left do recursive operations to get 00000
        // since the ___ is also number we can recursively try to convert it to 0 as well 
        
        // also even if n = 100100 -> doing 2^i operations we will have 010100 -> only the MSB shifts 
        int idx = getSetBit(n);
        if(idx==-1) return 0;
        else if(idx==0) return 1;
        int num1 = 1<<idx,num2 = 1<<(idx-1);
        bool prevBit = ((n>>(idx-1))&1);
        int op=0;
        if(prevBit){
            op+=1+ // converting 11 to 01
            minimumOneBitOperations(num2)+ // operation to convert the left off 01000 to 00100
            minimumOneBitOperations(n^num1^num2); // operations to convert ___ to all 0 
        }else{
            op+=(num1+minimumOneBitOperations(n^num1^num2));// adding num1 since num1 == 2^i bit which is set 
            // and the amount of operations required to shift it 
        }
        return op;
    }
};