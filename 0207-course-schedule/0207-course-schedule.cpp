class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Graph banao.
        // [a,b] ka matlab hai b pehle complete hoga,
        // tabhi a kar sakte hain.
        // Isliye edge b -> a banega.
        for (auto &p : prerequisites) {

            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course);

            // course ke ek aur prerequisite mil gaya,
            // isliye uska indegree badha do.
            indegree[course]++;
        }

        queue<int> q;

        // Jin courses ka koi prerequisite hi nahi hai,
        // wahi sabse pehle kiye ja sakte hain.
        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            // Ye course successfully complete ho gaya.
            count++;

            // Ab is course ke baad jitne courses unlock honge,
            // unka indegree kam kar do.
            for (auto nbr : adj[node]) {

                indegree[nbr]--;

                // Agar ab iske saare prerequisites complete ho gaye,
                // to ye bhi queue me aa sakta hai.
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        // Agar saare courses process ho gaye,
        // matlab kahin cycle nahi thi.
        // Agar kuch courses bach gaye,
        // to unke prerequisites kabhi khatam hi nahi hue.
        return count == numCourses;
    }
};
    