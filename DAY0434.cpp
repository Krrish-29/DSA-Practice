// 212. Word Search II
class Solution {
private:
    struct Node{
        string str;
        bool end;
        vector<Node*>child;
        Node():str(""),end(false),child(26,NULL){}
    };
    vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
    vector<string>ans;
    int m,n;
    void find(vector<vector<char>>& board,int i,int j,Node* root){
        if(board[i][j]=='#'||root->child[board[i][j]-'a']==NULL) return ;
        Node* next=root->child[board[i][j]-'a'];
        if(next->end){
            ans.push_back(next->str);
            next->end=false;// to remove dupes
        }
        char t=board[i][j];
        board[i][j]='#';
        for(auto &dir:dirs){
            int newX=dir[0]+i,newY=dir[1]+j;
            if(newX>=0&&newX<m&&newY>=0&&newY<n) find(board,newX,newY,next);
        }
        board[i][j]=t;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // create a node struct for storing the ending of words, word attached to the seq, and vector of 26 len for next letter 
        // add all the words in trie , if we had already seen a elem in the trie we move to next 
        // else create a new node struct at that point
        // after all char of a string are ended mark end and stored the string related to that word in it
        // for inference we find the matching elem and if we are at the end of the seq and find that end is true we consider that string and mark it false to remove dupes 
        // using dirs we try to navigate 
        // we try to move to the next trie node everytime
        Node* root = new Node();
        for(auto &str:words){
            Node* temp=root;
            for(char &c:str){
                if(temp->child[c-'a']==NULL){
                    temp->child[c-'a']=new Node();
                }
                temp=temp->child[c-'a'];
            }
            temp->end=true;
            temp->str=str;
        }
        m=board.size();n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                find(board,i,j,root);
            }
        }
        return ans;
    }
};