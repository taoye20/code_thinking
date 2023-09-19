#include<iostream>
#include<vector>
using namespace std;

//���ַ���������Ѱ��target
class Solution {
public:
	//�ݹ�Ķ��ַ�
	int no = -1;
	int* no_num = &no;
	int* search(int* begin, int* end, int target) {  //ʹ�ú�������
		if (begin > end) return no_num;
		int* middle = begin + (end - begin) / 2;
		if (*middle == target) return middle;
		else if (*middle > target) return search(begin, middle - 1, target);
		else return search(middle + 1, end, target);
	}

	//���ַ����������м�ȡһ��ֵ�۲��С����������滻�м�����ұ��滻�м�
	int search(int* a, int target, int n){
		int left = 0;
		int right = n - 1;
		int* result;
		while (left <= right) {  
			int middle = left + (right - left) / 2;
			if (target < a[middle]) {
				right = middle - 1;  //ע����ı�ǩ��Խ���м�ģ����Կ��Ǽ������ֻʣ������ʱ��������Ϊʲôһ����д������
			}
			else if (target > a[middle]) {
				left = middle + 1;
			}
			else {
				return middle;
			}
		}
		return -1;
	}
}solution;

int main() {
	int a[] = { -1, 0, 6, 9, 10, 15};
	int target = 2;
	int n = sizeof(a) / sizeof(a[0]);
	//int result = solution.search(a, target, n);
	int* result = solution.search(a, a+sizeof(a)/sizeof(a[0])-1, target);
	cout << "�ҵ���" << * result << endl;
	return 0;
}