<<<<<<< HEAD
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
           unordered_map<int,vector<int>> m;
           for(auto i : adjacentPairs)
           {
                m[i[0]].push_back(i[1]);
                m[i[1]].push_back(i[0]);
           }
           int start = 0;
           for(auto i : m)
           {
                if(i.second.size() == 1)
                {
                    start = i.first;
                    break;
                }
           }
           vector<int> v;
            unordered_map<int,int> m1;
           while(v.size() != adjacentPairs.size() + 1)
           {
             m1[start] = 1;
             v.push_back(start);
                for(auto i: m[start])
                {
                    if(m1.find(i) == m1.end())
                    {
                        start = i;
                        break;
                    }
                }
           }
           return v;
    }
=======
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
           unordered_map<int,vector<int>> m;
           for(auto i : adjacentPairs)
           {
                m[i[0]].push_back(i[1]);
                m[i[1]].push_back(i[0]);
           }
           int start = 0;
           for(auto i : m)
           {
                if(i.second.size() == 1)
                {
                    start = i.first;
                    break;
                }
           }
           vector<int> v;
            unordered_map<int,int> m1;
           while(v.size() != adjacentPairs.size() + 1)
           {
             m1[start] = 1;
             v.push_back(start);
                for(auto i: m[start])
                {
                    if(m1.find(i) == m1.end())
                    {
                        start = i;
                        break;
                    }
                }
           }
           return v;
    }
>>>>>>> 581a1ccad92424387d9a31defcfe6c6fe94ef5b6
};