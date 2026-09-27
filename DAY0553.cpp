// 1807. Evaluate the Bracket Pairs of a String
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // preprocess the knowledge using a map
        // anytime we see a ( we make a bool true so that all elems in () and 
        // added another string and then check against the map when we get ) 
        // if found we replace the item in ()
        // else replace it with ? 
        unordered_map<string,string>knowledgeBase;
        for(auto &know:knowledge){
            knowledgeBase[know[0]] = know[1];
        }
        string ans;
        string query;
        bool evaluate=false;
        for(char &c:s){
            if(c=='(') evaluate=true;
            else if(c==')') {
                evaluate=false;
                if(knowledgeBase.count(query)) ans+=knowledgeBase[query];
                else ans+='?';
                query="";
            }
            else if(evaluate){
                query+=c;
            }
            else{
                ans+=c;
            }
        }
        return ans;
    }
};