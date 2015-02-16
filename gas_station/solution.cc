class Solution {
public:
    // define: diff[1..n] s.t. diff[i] = gas[i] - cost[i]
    // observations: 1. if sum(diff) >= 0, there has to be a way to travel around the circuit
    // 2. if sum(diff[i..j]) < 0, then the route cannot start at [i..j]
    // http://blog.csdn.net/kenden23/article/details/14106137
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0;
        int cur_sum = 0;
        int all_sum = 0; 
        int n = gas.size();
        for (int i=0; i<n; ++i) {
            cur_sum += gas[i] - cost[i];
            all_sum += gas[i] - cost[i];
            if (cur_sum < 0) {
                start = i + 1;
                cur_sum = 0;
            }
        }
        if (all_sum < 0) { return -1; }
        else { return start; }    
    }
};
