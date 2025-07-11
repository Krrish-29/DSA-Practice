//2402. Meeting Rooms III
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int size=meetings.size();
        priority_queue<int,vector<int>,greater<>> freeRooms;
        for(int i=0;i<n;i++){
            freeRooms.push(i);
        }
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<>>busyRooms;
        vector<int>count(n,0);
        for(int meeting=0;meeting<size;meeting++){
            while(!busyRooms.empty()&&busyRooms.top().first<=meetings[meeting][0]){
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }
            if(freeRooms.empty()){
                count[busyRooms.top().second]++;
                busyRooms.emplace(meetings[meeting][1]-meetings[meeting][0]+busyRooms.top().first,busyRooms.top().second);
                busyRooms.pop();
            }
            else{
                count[freeRooms.top()]++;
                busyRooms.emplace(meetings[meeting][1],freeRooms.top());
                freeRooms.pop();
            }
        }
        int index=0;
        for(int i=1;i<n;i++){
            if(count[i]>count[index]) index=i;
        }
        return index;
    }
};
