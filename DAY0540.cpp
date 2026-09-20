// 4045. Count Robot Groups
class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        // starting form the base positions first merge all the robots that can be merged  
        // and store their rightmost(robot) speed
        // then what we can seen is that if a robot at index x is slowest among all robots then all robots 
        // from 0 to x will merge into it and due to it being the slowest it will not merge with any other 
        // robots after x , this can be repeatedly done for find the next slowest robot in range x+1 to size
        // and any slow robots found in 0 to x will be skipped and untill next robot can be found.
        // using priority queue and count the groups  

        // compress the positions 
        int size=speed.size();
        vector<int>newSpeed;
        int currSpeed=speed[0];
        for(int i=1;i<size;i++){
            if(position[i]-position[i-1]>distance){
                newSpeed.push_back(currSpeed);
            }
            currSpeed = speed[i];
        }
        newSpeed.push_back(currSpeed);

        size=newSpeed.size();
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // for(int i=0;i<size;i++){
        //     pq.push({newSpeed[i],i});
        // }
        // int smallestIdx=-1;
        // int count=0;
        // while(!pq.empty()){
        //     while(!pq.empty() && pq.top().second<smallestIdx){
        //         pq.pop();
        //     }
        //     if(pq.empty()) break;
        //     auto ele = pq.top();pq.pop();
        //     smallestIdx = ele.second;
        //     count++;
        // }
        // return count;
        
        // this priority queue can be rethinked as any time we find the robot starting from right to left that is faster than its prev then they can not every merge ,increasing the groups
        int count=1,prev=newSpeed[size-1];
        for(int i=size-2;i>=0;i--){
            if(prev>=newSpeed[i]) {
                count++;
                prev=newSpeed[i];
            }
        }
        return count;
    }
};