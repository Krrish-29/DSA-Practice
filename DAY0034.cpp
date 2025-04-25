// 781. Rabbits in Forest
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            // unordered_map<int,int>hashmap;
            // int rabbits=0;
            // for(int i=0;i<answers.size();i++){
            //     if(answers[i]==0){rabbits+=1;continue;}
            //     hashmap[answers[i]]++;
            //     if(hashmap[answers[i]]>answers[i]+1) hashmap[answers[i]]=1;
            //     if(hashmap[answers[i]]==1)rabbits+=(answers[i]+1);
            // }
            // return rabbits;
            int rabbits=0;
            sort(answers.begin(),answers.end());
            for(int i=0;i<answers.size();i++){
                if(answers[i]==0) {
                    rabbits++;
                }
                else{
                    rabbits+=answers[i]+1;
                    int x=answers[i];
                    while(i+1<answers.size()&&answers[i]==answers[i+1]&&--x>=0){
                        i++;
                    }
                }
            }
            return rabbits;
        }
    };