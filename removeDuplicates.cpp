//Remove Duplicates from Sorted Array
//若数组为空，则返回值为0
//若数组非空，从1~size-1遍历数组，依次与新数组的最后一个元素比较即可
class Solution {
		public:
				int removeDuplicates(vector<int>& nums) {
						const int size=nums.size();
						if(size==0)
								return 0;

						int index=0;
						for(int i=1;i<size;++i)
						{
								if(nums[i]!=nums[index])
								{
										++index;
										nums[index]=nums[i];
								}
						}

						return index+1;
				}
};
