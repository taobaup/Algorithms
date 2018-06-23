1)
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
    	if(array.empty())
    		return false;

    	const int row = array.size();
    	const int column = array[0].size();

    	int i = 0;
    	int j = column - 1;
    	while(i <= row - 1 && j >= 0)
    	{
    		if(target == array[i][j])
    			return true;
    		else if(target < array[i][j])
    			--j;
    		else
    			++i;
    	}

    	return false;
    }
};




2)
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
        	return false;

        const int row = array.size();
        const int column = array[0].size();

        int i = row - 1;
        int j = 0;
        while(i >= 0 && j <= column - 1)
        {
        	if(target == array[i][j])
        		return true;
        	else if(target < array[i][j])
        		--i;
        	else 
        		++j;
        }

        return false;
    }
};
