/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
 int dfs(int id, unordered_map<int, Employee*>& empMap) {
    Employee* employee = empMap[id];
    int totalImportance = employee->importance;
    for (int subid : employee->subordinates) {
        totalImportance += dfs(subid, empMap);
    }
    return totalImportance;
 }
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> empMap;
        // Fill the map with the employee data
        for (Employee* emp : employees) {
            empMap[emp->id] = emp;
        }
        return dfs(id, empMap);
    }
};