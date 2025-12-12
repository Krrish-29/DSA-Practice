// 3433. Count Mentions Per User
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(),
            [](const vector<string>& a, const vector<string>& b) {
                if(a[1]!=b[1]) return stoi(a[1]) < stoi(b[1]);
                return (a[0]=="OFFLINE"?0:1)<(b[0]=="OFFLINE"?0:1);
            });

        vector<int>ping(numberOfUsers,0);
        int size=events.size();
        for(int i=0;i<numberOfUsers;i++){
            int time=0;            
            for(int j=0;j<size;j++){
                if(events[j][0]=="MESSAGE"){
                    if(events[j][2]=="ALL") {
                        ping[i]++;
                    }
                    else if(events[j][2]=="HERE"){
                        if(time<=stoi(events[j][1])) ping[i]++;
                    }
                    else{
                        string s=events[j][2];
                        int id = 0;
                        bool reading = false;
                        for (char c : s) {
                            if (isdigit(c)) {
                                id = id * 10 + (c - '0');
                                reading = true;
                            } else if (reading) {
                                if (id == i) ping[i]++;
                                id = 0;
                                reading = false;
                            }
                        }
                        if (reading && id == i) ping[i]++;
                    }
                }
                else if(events[j][0]=="OFFLINE"&&stoi(events[j][2])==i){
                    time=max(time,stoi(events[j][1])+60);
                }
            }
        }
        return ping;
    }
};