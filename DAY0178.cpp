// 2197. Replace Non-Coprime Numbers in Array
class Solution {
private:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>stack;
        int size=nums.size(),m,n,g;
        for(int i=0;i<size;i++){
            stack.push(nums[i]);
            while(stack.size()>=2){
                m=stack.top();
                stack.pop();
                n=stack.top();
                stack.pop();
                g=gcd(m,n);
                if(g>1){
                    stack.push(m*1LL*n/g);
                }
                else{
                    stack.push(n);
                    stack.push(m);
                    break;
                }
            }
        }
        vector<int>answer;
        while(!stack.empty()) {
            answer.push_back(stack.top());
            stack.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};