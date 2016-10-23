//Rotate Image 
//先将数组沿行的中线对折 
//1 2 
//3 4翻转为
//
//3 4 
//1 2 
//再沿主对角线翻转 
//3 4 
//1 2翻转为
//
//3 1 
//4 2
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n=matrix.size();
        
        for(int i=0;i<n/2;++i)
            for(int j=0;j<n;++j)
                swap(matrix[i][j],matrix[n-1-i][j]);
        
        for(int i=0;i<n;++i)
            for(int j=0;j<i;++j)
                swap(matrix[i][j],matrix[j][i]);
    }
};
