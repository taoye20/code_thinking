#include<iostream>
using namespace std;

int main() {
	//��������ķ�ʽ
	int a[][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	
	//�����С�ж�
	int n = sizeof(a) / sizeof(a[0]);  //�������
	int k = sizeof(a[0]) / sizeof(a[0][0]);  //�������
	cout << n << endl;
	cout << k << endl;

	//�����ַ�����Կ���Ϊ˳�����У��Ҽ��Ϊ4�ֽ�
	cout << "��ַ��0��0����" << (int)&a[0][0] << "/t" << "��ַ��0��1����" << (int)&a[0][1] << "/t" << "��ַ��0��2����" << (int)&a[0][2] << endl;
	cout << "��ַ��1��0����" << (int)&a[1][0] << "/t" << "��ַ��1��1����" << (int)&a[1][1] << "/t" << "��ַ��1��2����" << (int)&a[1][2] << endl;
	return 0;
}