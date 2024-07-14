class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int total_gas = 0;
        for(int i = 0;i<gas.size();i++)
        {
            total_gas += gas[i];
            if(total_gas >= cost[i])
            {
                total_gas -= cost[i];
            }
            else
            {
                if(i == gas.size() - 1) return -1;
                start = i+1;
                total_gas = 0;
            }
        }
        for(int i = 0;i<start;i++)
        {
            total_gas += gas[i];
            if(total_gas >= cost[i])
            {
                total_gas -= cost[i];
            }
            else
            {
                return -1;
            }
        }
        return start;
    }
};