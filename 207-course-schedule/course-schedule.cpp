class Solution {
public:
    
    int isCycle(vector<vector<int>>& AdjList, int i, vector<int>& visited, vector<int>& recStack) {
        if (recStack[i]) return true;
        if (visited[i]) return false;

        recStack[i] = 1;
        visited[i] = 1;

        for (auto x : AdjList[i]) {
            if (isCycle(AdjList, x, visited, recStack)) {
                return true;
            }
        }

        recStack[i] = 0;
        return false;
    }

    vector<vector<int>> constructed(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> res(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            res[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return res;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> AdjList = constructed(numCourses, prerequisites);
        vector<int> visited(numCourses, 0);
        vector<int> recStack(numCourses,0);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && isCycle(AdjList, i, visited, recStack)) {
                return false;
            }
        }
        return true;
    }
};