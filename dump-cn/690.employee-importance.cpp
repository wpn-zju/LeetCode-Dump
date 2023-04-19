/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
	int getImportance(vector<Employee*>& employees, int id) {
		unordered_map<int, Employee*> dataMap;
		for (Employee* ee : employees)
			dataMap[ee->id] = ee;
		return dfsEmployee(dataMap, id);
	}

	int dfsEmployee(unordered_map<int, Employee*>& data, int id) {
		int result = data[id]->importance;
		for (int i : data[id]->subordinates)
			result += dfsEmployee(data, i);
		return result;
	}
};