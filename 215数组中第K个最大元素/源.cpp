#include<iostream>
#include<vector>
using namespace std;
int pos(vector<int>& nums, int low, int high)
{
	int i = low;
	int j = high;
	int key = nums[i];
	if (low < high) {
		while (i < j) {
			while (i < j && nums[j] >= key) {
				j--;
			}
			if (i < j) {
				nums[i] = nums[j];
			}
			while (i < j && nums[i] <= key) {
				i++;
			}
			if (i < j) {
				nums[j] = nums[i];
			}
		}
		nums[i] = key;
	}
	return i;
}
int findKthLargest(vector<int>& nums, int k) {
	int n = nums.size();
	int low = 0;
	int high = n - 1;
	/* sort(nums.begin(),nums.end());
	 return nums[n-k];*/
	int p = pos(nums, low, high);
	while (p != n - k)
	{
		if (p < n - k)	
			low = p + 1;
		else
			high = p - 1;
		p = pos(nums, low, high);
	}
	return nums[n - k];
}
int main()
{
	vector<int> nums = { 3,2,1,5,6,4 };
	cout << findKthLargest(nums, 2)<<endl;
	system("pause");
	return 0;
}