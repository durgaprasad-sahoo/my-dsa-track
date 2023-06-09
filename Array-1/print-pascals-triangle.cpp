class Solution {
public:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.emplace_back(ans);
        for(int col=1; col<row; col++){
            ans = ans* (row-col);
            ans = ans/(col);
            ansRow.emplace_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> finalAns;
        for(int i=1; i<=numRows; i++){
            finalAns.emplace_back(generateRow(i));
        }
        return finalAns;
    }
};
