// 64. Minimum Path Sum
class Solution {
    public: //better approach
        int orangesRotting(vector<vector<int>>& grid) {
            int counter=2;bool rotten=true;
            while(rotten){
                rotten=false;
                for(int i=0;i<grid.size();i++){
                    for(int j=0;j<grid[0].size();j++){
                        if(grid[i][j]==counter){
                            rotten|=set_rotten(grid,i,j,counter+1);
                        }
                    }
                }
                if(rotten) counter++;
            }
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==1){
                        return -1;
                    }
                }
            }
            return counter>0?counter-2:counter;
        }
        bool set_rotten(vector<vector<int>>& grid,int i, int j,int counter){
            bool rotten=false;
            if(i-1>=0&&grid[i-1][j]==1) { grid[i-1][j]=counter;rotten=true;}
            if(j-1>=0&&grid[i][j-1]==1){grid[i][j-1]=counter;rotten=true;}
            if(i+1<=grid.size()-1&&grid[i+1][j]==1) {grid[i+1][j]=counter;rotten=true;}
            if(j+1<=grid[0].size()-1&&grid[i][j+1]==1) {grid[i][j+1]=counter;rotten=true;}
            return rotten;
        }
    };




// class Solution {
//     public: //typical approach
//         typedef struct node{
//             int i;int j;int time;
//             struct node*next;
//         }Node;
//         typedef struct queue{
//             Node*head,*tail;
//         }Queue;
//         Queue* init_queue(){
//             Queue*list=(Queue*)malloc(sizeof(Queue));
//             list->head=NULL;
//             list->tail=NULL;
//             return list;
//         }
//         void enqueue(Queue*queue,int i,int j,int time){
//             Node*newNode=(Node*)malloc(sizeof(Node));
//             newNode->i=i;
//             newNode->j=j;
//             newNode->time=time;
//             newNode->next=NULL;
//             if(queue->tail==NULL){
//                 queue->head=newNode;
//             }
//             else{
//                 queue->tail->next=newNode;
//             }
//             queue->tail=newNode;        
//         }
//         Node* dequeue(Queue*queue){
//             if(queue->head==NULL) return NULL;
//             Node*temp=queue->head;
//             queue->head=queue->head->next;
//             if(queue->head==NULL) queue->tail=NULL;
//             return temp;
//         }
//         Node* front(Queue*queue){
//             return queue->head;
//         }
//         bool isEmpty(Queue*queue){
//             return queue->head==NULL;
//         }
//         int orangesRotting(vector<vector<int>>& grid) {
//             if(grid.size()==0) return -1;
//             int fresh_orange=0;
//             Queue*queue=init_queue();
//             for(int i=0;i<grid.size();i++){
//                 for(int j=0;j<grid[0].size();j++){
//                     if(grid[i][j]==2) enqueue(queue,i,j,0);
//                     if(grid[i][j]==1) fresh_orange++;
//                 }
//             }
//             int maxtime=0;
//             while(!isEmpty(queue)){
//                 Node*orange=dequeue(queue);
//                 int i=orange->i;
//                 int j=orange->j;
//                 int time=orange->time;
//                 free(orange);
//                 maxtime=max(maxtime,time);
//                 if(i-1>=0&&grid[i-1][j]==1) {grid[i-1][j]=2;enqueue(queue,i-1,j,time+1);fresh_orange--;}
//                 if(j-1>=0&&grid[i][j-1]==1){grid[i][j-1]=2;enqueue(queue,i,j-1,time+1);fresh_orange--;}
//                 if(i+1<=grid.size()-1&&grid[i+1][j]==1) {grid[i+1][j]=2;enqueue(queue,i+1,j,time+1);fresh_orange--;}
//                 if(j+1<=grid[0].size()-1&&grid[i][j+1]==1) {grid[i][j+1]=2;enqueue(queue,i,j+1,time+1);fresh_orange--;}
//             }
//             while (!isEmpty(queue)) { //memory optimization
//                 Node* leftover = dequeue(queue);
//                 free(leftover);
//             }
//             free(queue);
//             return fresh_orange>0?-1:maxtime;
//         }
//     };