class Solution1 {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int result = 0;
        for (Employee* &p : employees)
            if (p->id == id) {
                result += p->importance;
                for (int &i : p->subordinates)
                    result += getImportance(employees, i);
            }
        return result;
    }
};
