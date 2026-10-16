// 433. Minimum Genetic Mutation
class Solution {
private:
    vector<char> genes = {'A','C','G','T'};
    int minMoves = INT_MAX;
    void dfs(string& currGene,string& endGene,int moves,unordered_set<string>& geneBank,unordered_set<string>& seen){
        if(currGene == endGene) {
            minMoves = min(minMoves,moves);
            return ;
        }
        if(seen.count(currGene)) return ;
        seen.insert(currGene);
        string newGene;
        for(int i=0;i<8;i++){
            newGene = currGene;
            for(char &gene:genes){
                newGene[i] = gene;
                if(geneBank.count(newGene) && !seen.count(newGene)) dfs(newGene,endGene,moves+1,geneBank,seen);
            }
        }
        // seen.erase(currGene);
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // approach is to start from the given gene and try to modify one elem at a time with others and check if the 
        // gene made exists in bank if yes then add it and move forward , if not then try other A C G T at other positions as well
        // keep the seen ones in a set as well to not re iterate over them 
        // in bfs the first find for the endGene will be the shortest 
        // in dfs explore all paths, we need not to remove the seen but its clear and better to remove the curr seen gene 
        // as we might encounter it in other better paths as well
        unordered_set<string>geneBank(bank.begin(),bank.end());
        unordered_set<string>seen;
        if(!geneBank.count(endGene)) return -1; // endGene is not in geneBank therefore it cannot be created

        //dfs
        // dfs(startGene,endGene,0,geneBank,seen);
        // return minMoves == INT_MAX? -1 : minMoves;


        //bfs
        queue<pair<string,int>>mutation; // gene , moves
        mutation.push({startGene,0});
        seen.insert(startGene);
        while(!mutation.empty()){
            auto [currGene,moves] = mutation.front();mutation.pop();
            if(currGene == endGene) return moves;
            string newGene;
            for(int i=0;i<8;i++){
                newGene = currGene;
                for(char &gene:genes){
                    newGene[i] = gene;
                    if(geneBank.count(newGene) && !seen.count(newGene)) {
                        seen.insert(newGene);
                        mutation.push({newGene,moves+1});
                    }
                }
            }
        }   
        return -1;
    }
};