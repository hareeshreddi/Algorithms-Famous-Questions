class Solution {
public:
    void reverse(vector<vector<int>>& matrix)
    {
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size()/2;j++)
                swap(matrix[i][j],matrix[i][matrix.size()-j-1]);
    }
    void transpose(vector<vector<int>>& matrix)
    {
        for(int i=0;i<matrix.size();i++)
            for(int j=i+1;j<matrix[0].size();j++)
                swap(matrix[i][j],matrix[j][i]);
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
};