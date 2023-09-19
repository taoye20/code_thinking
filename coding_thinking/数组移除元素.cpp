#include<iostream>
#include<vector>
using namespace std;

//数组删除中间指定的元素
class Solution {
public:
	//传统方法，删除一个，后面全部向前移动一位，时间复杂度为O(n*n)
	int rm1(vector<int>& nums, int val) {
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			if (nums[i] == val) {
				for (int j = i + 1; j < size; j++) {
					nums[j - 1] = nums[j];  
				}
				i--;
				size--;
			}
		}
		return size;
	}

	//双指针法，自己写的逻辑不够清晰
	int rm2(vector<int>& nums, int val) {
		int size = nums.size();
		int slow = 0;
		for (int fast = 0; fast < size; fast++) {
			nums[slow] = nums[fast];
			if (nums[slow] != val) slow++;  //如果慢指针发现相同的就原地等待赋值
		}
		return slow;
	}

	//双指针法，别人的写法，slow可以看成在原数组上重新写一遍新的数组，fast负责跳过与val相同的数传递给slow
	int rm3(vector<int>& nums, int val) {
		int slow = 0;
		for (int fast = 0; fast < nums.size(); fast++) {
			if (nums[fast] != val) {
				nums[slow++] = nums[fast];  //先传值后加指针
			}
		}
		return slow;
	}

	//26双指针法删除数组中的重复项
	int removeDuplicates(vector<int>& nums) {
		int j = 1; 
		if (nums.size() == 1) return 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i-1] != nums[i]) {  //注意这里的-1和前面设置j初始为1，是为了不会超出数组范围
				nums[j++] = nums[i];
			}
		}
		return j;
	}
}solution;

//调用并打印
int main() {
	vector<int> nums = { 1, 6, 3, 2, 2, 9, 5 };
	int size = solution.rm3(nums, 2);
	for (int i = 0; i < size; i++) {
		cout << nums[i] << endl;
	}
	return 0;
}