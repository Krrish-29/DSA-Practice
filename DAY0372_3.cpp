// 3885. Design Event Manager
class EventManager {
private:
    unordered_map<int,int>id;// id pri
    map<int,set<int>>map;// pri eventids 
public:
    EventManager(vector<vector<int>>& events) {
        for(auto &event:events){
            id[event[0]]=event[1];
            map[event[1]].insert(event[0]);
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(id.count(eventId)){
            int prevPri=id[eventId];
            map[prevPri].erase(eventId);
            if(map[prevPri].empty()){
                map.erase(prevPri);
            }
        }
        id[eventId]=newPriority;
        map[newPriority].insert(eventId);
    }
    
    int pollHighest() {
        if(map.begin()==map.end()) return -1;
        auto priority=prev(map.end())->first;
        int event=*map[priority].begin();
        map[priority].erase(event);
        if(map[priority].empty()){
            map.erase(priority);
        }
        id.erase(event);
        return event;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */