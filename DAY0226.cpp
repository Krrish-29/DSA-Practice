// 1578. Minimum Time to Make Rope Colorful
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // int size=colors.size(),minTime=0;
        // stack<int>stack;
        // stack.push(0);
        // for(int i=1;i<size;i++){
        //     int prev=stack.top();
        //     if(colors[prev]==colors[i]){
        //         if(neededTime[i]>neededTime[prev]){
        //             minTime+=neededTime[prev];
        //             stack.pop();
        //         }
        //         else{
        //             minTime+=neededTime[i];
        //             continue;
        //         }
        //     }
        //     stack.push(i);
        // }
        // return minTime;

        int size=colors.size(),minTime=0;
        int left=0,right=1;
        while(right<size){
            printf("%d %d ",left,right);
            if(colors[left]==colors[right]){
                if(neededTime[left]>=neededTime[right]){
                    minTime+=neededTime[right];
                }
                else{
                    minTime+=neededTime[left];
                    left=right;
                }
            }
            else {
                left=right;
            }
            right++;
        }
        return minTime;
    }
};