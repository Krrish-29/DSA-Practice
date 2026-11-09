// 991. Broken Calculator
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // a brute force bfs/dfs approach can work but upto a certain limit
        // queue<pair<int,int>>q; // value , moves
        // unordered_set<int>seen;
        // q.push({startValue,0});
        // seen.insert(startValue);
        // while(!q.empty()){
        //     auto [x,moves] = q.front(); q.pop();
        //     if(x == target) return moves;
        //     if(x < target && !seen.count(2*x)){
        //         q.push({2*x,moves+1});
        //         seen.insert(2*x);
        //     }
        //    if(!seen.count(x-1)){
        //         q.push({x-1,moves+1});
        //         seen.insert(x-1);
        //     }
        // }
        // return -1;

        // for optimized solution 
        // flip the problem
        // cause if the start is even or odd doing * 2 will result in an even number and also if we 
        // subtract 1 and then multiply or first multiply then subtract 1 ,both paths can be used to reach the target, and none of them is intuitive for smallest operations, meaning we cannot do * 2 greadily 
        // but dividing is intuitive as doing / 2, till the startValue < target
        // (num + 2) /2 => 3 operations,  num + 1 / 2 => 2 operations, reducing the operations with same results 
        // also we need to make sure while dividng the number must be even since if odd number is 
        // integer divided by 2 then the info for the bit 0 will be lost, therefore add 1 if odd
        // and for each operations count it and at last return operations + (start - target) 
        // and if target > start, we divide and add accordingly 
        // if == or target < start we only add 0 or some number which is handled by (start - target)  automatically 
        // the time complexity is log(target) and space is constant
        int op=0;
        while(startValue < target){
            if(target%2 == 0 ) target/=2;
            else target++;
            op++;
        }
        return op + (startValue-target);
    }
};