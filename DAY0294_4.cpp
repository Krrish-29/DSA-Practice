// 636. Exclusive Time of Functions
class Solution {
private:
    tuple<int,string,int> decode(string log){
        int i=0,size=log.size();
        int fId=0;
        string op;
        while(i<size&&log[i]!=':'){
            fId=fId*10+log[i]-'0';
            i++;
        }
        i++;
        while(i<size&&log[i]!=':'){
            op+=log[i];
            i++;
        }
        i++;
        return {fId,op,stoi(log.substr(i))};
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int,int>>stack;
        vector<int>exclusiveTime(n,0);
        int timestamp=0;
        for(string log:logs){
            auto [pid,op,time]=decode(log);
            if(!stack.empty()) {// if we have a pid processing already save its time and move to new
                if(op=="start") {// if a new pid is starting save old one with currTime - prevTime
                    exclusiveTime[stack.top().first]+=(time-timestamp);
                    stack.push({pid,time});
                }
                else {// if a pid is ending so add its currTime- prevTime +1
                    exclusiveTime[stack.top().first]+=(time-timestamp+1);
                    stack.pop();
                }
            }
            else stack.push({pid,time});
            // timestamp is changed based on start or end command 
            if(op=="start") timestamp=time;
            else timestamp=time+1;
        }
        return exclusiveTime;
    }
};