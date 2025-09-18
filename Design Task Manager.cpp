
struct HighComp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first) return a.first > b.first; // higher priority first
        return a.second > b.second;                      // if tie, higher taskId first
    }
};
class TaskManager {
public:
    unordered_map<int, set<pair<int,int>>> user_task_priority; 
    unordered_map<int,int> task_user;     
    unordered_map<int,int> task_priority;  
    unordered_map<int, set<pair<int,int>>> task_user_priority; 

    set<pair<int,int>, HighComp> highest; // (priority, taskId) custom order

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &task: tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            user_task_priority[userId].insert({taskId,priority});
            task_user[taskId] = userId;
            task_priority[taskId] = priority;
            task_user_priority[taskId].insert({userId,priority});
            highest.insert({priority,taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        user_task_priority[userId].insert({taskId,priority});
        task_user[taskId] = userId;
        task_priority[taskId] = priority;
        task_user_priority[taskId].insert({userId,priority});
        highest.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int user = task_user[taskId];
        int oldPriority = task_priority[taskId];

        user_task_priority[user].erase({taskId,oldPriority});
        user_task_priority[user].insert({taskId,newPriority});

        task_priority[taskId] = newPriority;

        task_user_priority[taskId].erase({user,oldPriority});
        task_user_priority[taskId].insert({user,newPriority});

        highest.erase({oldPriority,taskId});
        highest.insert({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        int user = task_user[taskId];
        int oldPriority = task_priority[taskId];

        user_task_priority[user].erase({taskId,oldPriority});
        task_user.erase(taskId);
        task_priority.erase(taskId);
        task_user_priority.erase(taskId);
        highest.erase({oldPriority,taskId});
    }
    
    int execTop() {
        if (highest.empty()) return -1;

        // top element due to custom comparator
        auto it = highest.begin();
        int priority = it->first;
        int taskId = it->second;
        int userId = task_user[taskId];

        // remove everywhere
        user_task_priority[userId].erase({taskId,priority});
        task_user.erase(taskId);
        task_priority.erase(taskId);
        task_user_priority.erase(taskId);
        highest.erase(it);

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
