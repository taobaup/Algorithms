//Set Matrix Zeroes 
//遍历数组，记录0元素所在的行和列 
//遍历数组，将0元素所在的行和列都置为0即可
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m=matrix.size();
        const int n=matrix.front().size();
        
        vector<bool> row(m,false);
        vector<bool> col(n,false);
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]==0)
                    row[i]=col[j]=true;
            }
        }
        
        for(int i=0;i<m;++i)
        {
            if(row[i])
            {
                for(int j=0;j<n;++j)
                    matrix[i][j]=0;
            }
        }
        
        for(int j=0;j<n;++j)
        {
            if(col[j])
            {
                for(int i=0;i<m;++i)
                    matrix[i][j]=0;
            }
        }
    }
};
