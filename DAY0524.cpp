// 3720. Lexicographically Smallest Permutation Greater Than Target
class Solution {
private:
    string lexi;
    bool backTrack(vector<int>& freq,string &target,int idx,string curr,bool exactMatch){
        if(target.size()==idx) {
            if(curr!=target){
                lexi=curr;
                return true;
            } 
            return false;
        }
        if(exactMatch){
            char c = target[idx];
            for(int i=c-'a';i<26;i++){
                if(freq[i]!=0){
                    freq[i]--;
                    curr+=(char)('a'+i);
                    // i == c-'a' makes sure if the target char is matched or not 
                    if(backTrack(freq,target,idx+1,curr,i==(c-'a'))) return true;
                    curr.pop_back();
                    freq[c-'a']++;
                }
            }
        }
        else{
            for(int i=0;i<26;i++){
                if(freq[i]!=0) curr+=string(freq[i],'a'+i);
            }
            if(backTrack(freq,target,target.size(),curr,exactMatch)) return true;
        }
        return false;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        // backtracking question because of the structure of problem where we need to try every combination 
        // at every position , also since it needs to be lexi smallest but just bigger than target
        // we can use backtracking unless it would be normal recursion 
        // first get a freq map since we need to rearrange the chars of s 
        // then in backtracking , our mission is to get just the string to be a little bigger/larger than the target
        // so try to make it equal first , by taking the exact chars in target
        // if not possible then only take the first bigger char , due to this the string is already bigger than target
        // now to make it smallest among all string greater than target we need to use all chars 
        // from smallest to largest in ascending order
        // for knowing when to match exact char or when to arrange char in ascending use a bool 
        // to improve make the backtracking boolean and when the ans is found return true else false 
        vector<int>freq(26,0);
        for(char &c:s){
            freq[c-'a']++;
        }
        backTrack(freq,target,0,"",true);
        return lexi==target?"":lexi;
    }
};