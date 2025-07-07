// 1353. Maximum Number of Events That Can Be Attended
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int result=0,day=0,index=0,n=events.size();
        priority_queue<int,vector<int>,greater<int>>minheap;
        while(!minheap.empty()||index<n){
            if(minheap.empty()){
                day=events[index][0];
            }
            while(index<n&&events[index][0]<=day){
                minheap.push(events[index][1]);
                index++;
            }
            minheap.pop();
            result++;
            day++;
            while(!minheap.empty()&&minheap.top()<day){
                minheap.pop();
            }
        }
        return result;
    }
};