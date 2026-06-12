// 3408. Design Task Manager
class TaskManager {
private:
    set<pair<int,int>>set;// priority, taskId
    unordered_map<int,pair<int,int>>map;// taskId -> priority, userId
public:
    TaskManager(vector<vector<int>>& tasks) {
        int taskId,priority,userId;
        for(auto &task:tasks){
            userId=task[0];taskId=task[1];priority=task[2];
            set.insert({priority,taskId});
            map[taskId]=make_pair(priority,userId);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        set.insert({priority,taskId});
        map[taskId]=make_pair(priority,userId);
    }
    
    void edit(int taskId, int newPriority) {
        auto [priority,userId]=map[taskId];
        set.erase({priority,taskId});
        set.insert({newPriority,taskId});
        map[taskId]=make_pair(newPriority,userId);
    }
    
    void rmv(int taskId) {
        auto [priority,userId]=map[taskId];
        set.erase({priority,taskId});
        map.erase(taskId);
    }
    
    int execTop() {
        if(set.empty()) return -1;
        auto it=prev(set.end());
        int taskId=(*it).second;
        int userId=map[taskId].second;
        set.erase(*it);
        map.erase(taskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */