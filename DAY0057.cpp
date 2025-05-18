// 1931. Painting a Grid With Three Different Colors
class Solution {
public:
    void generate_color(vector<int>&states,int pos,int state,int prevcolor,int m){
        if(pos==m) {
            states.push_back(state);
            return ;
        }
        else{
            for(int color=0;color<3;color++){
                if(color!=prevcolor){
                    generate_color(states,pos+1,(state << 2) | color,color,m);
                }
            }
        }
    }
    void transition_graph(vector<int>&states,vector<vector<int>>&transitions,int m){
        generate_color(states,0,0,-1,m);
        int state_size=states.size();
        transitions.assign(state_size,vector<int>());
        for(int i=0;i<state_size;i++){
            for(int j=0;j<state_size;j++){
                bool valid=true;
                int s1=states[i],s2=states[j];
                for(int k=0;k<m;k++){
                    if((s1&3)==(s2&3)){
                        valid=false;
                        break;
                    }
                    s1>>=2;
                    s2>>=2;
                }
                if(valid) transitions[i].push_back(j);
            }
        }
    }
    int colorTheGrid(int m, int n) {
        vector<int>states;
        vector<vector<int>>transitions;
        transition_graph(states,transitions,m);
        int state_size=states.size();
        vector<int>prev_dp(state_size,1),curr_dp(state_size,0);
        for(int col=1;col<n;col++){
            for(int i=0;i<state_size;i++){
                for(int nextstate:transitions[i]){
                    curr_dp[nextstate]=(curr_dp[nextstate]+prev_dp[i])%1000000007;
                }
            }
            swap(curr_dp,prev_dp);
            fill(curr_dp.begin(),curr_dp.end(),0);
        }
        int result = 0;
        for(int i=0;i<state_size;i++){
            result=(result+prev_dp[i])%1000000007;
        }
        return result;
    }
};
/* Best Memory Approach
class Solution {
    const int M = 1e9+7;
    const int COLORS = 3;
    const int DIFFS = COLORS-1;

    bool validCol(int col, int cn) {
        int last = -1;
        for(int mul = 1; mul < cn; mul *= COLORS) {
            int color = (col/mul)%COLORS;
            if(color == last) return false;
            last = color;
        }
        return true;
    }   

    int colorDiff(int col, int diffs, int cn) {
        int ans = 0;
        for(int mul = 1, muld = 1; mul < cn; mul *= COLORS, muld *= DIFFS) {
            int color = (col/mul)%COLORS, diff = (diffs/muld)%DIFFS;
            int next_color = (color + diff + 1)%COLORS;
            ans += next_color*mul;
        }
        return ans;
    }
public:
    int colorTheGrid(int m, int n) {
        int cn = pow(COLORS, m), diffn = 1<<m, rn = n;
        vector<int> prev(cn), cur(cn);
        for(int j=0; j<cn; ++j) {
            prev[j] = validCol(j, cn) ? 1 : 0;
        }

        //rows loop
        for(int i=0; i<rn-1; ++i) {
            //all possible column combination base 3
            for(int j=0; j<cn; ++j) {
                if(!validCol(j, cn)) {
                    continue;
                }
                
                //all possible color diff base 2 to calculate valid previous column
                long ways = 0;
                for(int k=0; k<diffn; ++k) {
                    int prevj = colorDiff(j, k, cn);
                    ways = (ways + prev[prevj])%M;
                }
                cur[j] = ways;
            }
            swap(prev, cur);
        }

        long ans = 0;
        for(int i=0; i<cn; ++i) {
            ans = (ans + prev[i])%M;
        }
        return ans;
    }
};
*/