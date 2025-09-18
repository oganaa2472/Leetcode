class TaskManager {
public:
    unordered_map<int, pair<int, int>> taskData;
    map<int, set<int>, greater<>> priorityTasks;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
       taskData[taskId] = {userId, priority};
       priorityTasks[priority].insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskData[taskId];
        priorityTasks[oldPriority].erase(taskId);
        if (priorityTasks[oldPriority].empty()) {
            priorityTasks.erase(oldPriority);
        }

        taskData[taskId] = {userId, newPriority};
        priorityTasks[newPriority].insert(taskId);
    }
    
    void rmv(int taskId) {
        auto [userId, priority] = taskData[taskId];
        priorityTasks[priority].erase(taskId);
        if (priorityTasks[priority].empty()) {
            priorityTasks.erase(priority);
        }
        taskData.erase(taskId);
    }
    
    int execTop() {
        if (priorityTasks.empty()) {
            return -1;
        }

        auto highestPriorityIt = priorityTasks.begin();
        int priority = highestPriorityIt->first;
        auto& tasks = highestPriorityIt->second;

        int taskId = *tasks.rbegin();
        int userId = taskData[taskId].first;

        
        tasks.erase(taskId);
        if (tasks.empty()) {
            priorityTasks.erase(priority);
        }
        taskData.erase(taskId);

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