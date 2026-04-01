// 2751. Robot Collisions
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int size=positions.size();
        // first temp store idx and then sort then acc to pos 
        // start iteration from the first pos idx and if its R or stack empty then push it
        // else we will check if the current Left robot has health more than 0
        // and if it competes with other right robots , acc to res update the healths of both 
        // if left robot is destroyed then stop else keep destroying right robots
        // then extract ans from left over robots healths
        vector<int>temp(size,0);
        for(int i=0;i<size;i++) temp[i]=i;
        sort(temp.begin(),temp.end(),[&](int &a,int &b){
            return positions[a]<positions[b];
        });
        stack<int>stack;
        for(int &idx:temp){
            if(stack.empty()||directions[idx]=='R') stack.push(idx);
            else if(!stack.empty()&&directions[idx]=='L'){
                while(!stack.empty()&&directions[stack.top()]=='R'&&healths[idx]>0){
                    if(healths[stack.top()]>healths[idx]){
                        healths[stack.top()]--;
                        healths[idx]=0;
                        break;
                    }
                    else if(healths[stack.top()]<healths[idx]){
                        healths[stack.top()]=0;
                        healths[idx]--;
                        stack.pop();
                    }
                    else {
                        healths[stack.top()]=0;
                        healths[idx]=0;
                        stack.pop();
                        break;
                    }
                }
                if(healths[idx]>0) stack.push(idx);
            }
        }
        vector<int>ans;
        for(int i=0;i<size;i++) {
            if(healths[i]>0) ans.push_back(healths[i]);
        }
        return ans;
    }
};