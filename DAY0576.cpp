// 3081. Replace Question Marks in String to Minimize Its Value
class Solution {
private:
    struct compare{
        bool operator()(const pair<char,int>& a,const pair<char,int>& b) const{
            if (a.second == b.second) return a.first > b.first;
            return a.second > b.second; 
        }
    };
public:
    string minimizeStringValue(string s) {
        // the approach to solve in steps first try to minimize cost then smallest string possible 
        // to minimize the cost function we have to make sure that we try use the alphabets with least freq 
        // since the using a char at middle or last does nto affect the cost , the freq affects the cost 
        // so start with the freq mapping of chars in s and also count ? for later use
        // then using priority queue (or map/heap) arrange them in a manner such that the char with least freq comes in front
        // and any time we use the front char pop it and increment its freq since using it again would cost = freq + 1
        // and push it back into queue for using it again later on, this approach minimize the cost
        // to get the smallest string, we have to use chars also in a sorted manner, at a particluar freq many chars 
        // can be available but we sort them to get the best char possible, now it is possible that for a particluar 
        // postion of ? we have 'z' as a best option and later on for another ? we have 'a' as a best option 
        // the arrangement does not affect the cost but it affects the smallest string
        // so rather than directly replacing ? on the fly we store them , sort at end and place back to get smallest string
        // and for each ? we get the smallest char with smallest freq and store it, increment its freq push it back 
        // one more improvement is that we can use a simple loop to find the minChar rather than priority queue since the freq array is small 
        // O(26k) but since the pq has O (k log n) which is < O(26k), k for questions, the overhead cost for pq is more and array is easy to cache
        // also a important thing priority queue comparator works opposite to normal comparators
        vector<int>freq(26,0);
        int questions=0;
        for(char &c:s){
            if(c == '?') questions++;
            else freq[c-'a']++;
        }
        // priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
        // for(int i=0;i<26;i++){
        //     pq.push({'a'+i,freq[i]});
        // }
        string ans;

        int minIdx;
        while(questions>0){
            // auto [c,f] = pq.top(); pq.pop();
            // f++;
            // ans+=c;
            // pq.push({c,f});
            // questions--;

            minIdx=0;
            for(int i=0;i<26;i++){
                if(freq[i] < freq[minIdx]) minIdx = i;
            }
            ans+=char('a'+minIdx);
            freq[minIdx]++;
            questions--;
        }
        sort(ans.begin(),ans.end());
        int idx=0;
        for(char &c:s){
            if(c == '?') c = ans[idx++];
        }
        return s;
    }
};