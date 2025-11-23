class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> currAst;
        currAst.push(asteroids[0]);
        for (int i = 1; i < asteroids.size(); i++)
        {
            if (asteroids[i] < 0)
            {
                while (!currAst.empty() && abs(asteroids[i]) > currAst.top() && currAst.top() > 0)
                {
                    currAst.pop();
                }
                if (currAst.empty() || currAst.top() < 0 || abs(currAst.top()) < abs(asteroids[i]) )
                {
                    currAst.push(asteroids[i]);
                }
                if (!currAst.empty() && asteroids[i] == -currAst.top())
                {
                    currAst.pop();
                }
            }
            else
            {
                currAst.push(asteroids[i]);
            }
        }

        while (!currAst.empty())
        {
            ans.push_back(currAst.top());
            currAst.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};