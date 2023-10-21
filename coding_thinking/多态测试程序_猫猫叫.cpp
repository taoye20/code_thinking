#include<iostream>
#include<vector>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "���ﹹ�캯��" << endl;
    }

    virtual ~Animal() {   //������������ʹ��virtual������ʵ������������������ã��㿴����������
        cout << "������������" << endl;
    }

    virtual void speak() {   
        cout << "������˵��" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string name) {
        cout << "è���캯��" << endl;
        m_Name = new string(name);  //�������п��ٶ���
    }

    ~Cat() {
        cout << "è��������" << endl;
        if (m_Name != NULL) {    //ʹ���������������ͷ��ڴ�
            delete m_Name;
        }
    }

    void speak() {
        cout<< *m_Name << "è��˵��������" << endl;
    }

    string* m_Name;
};

int main() {
    Animal* cat = new Cat("Tom");
    cat->speak();
    delete cat;     //����delete���Ǹ���ָ�룬���������������������������д���������������������д����������delete����Ҳû���ã������ڴ�й©����ô�쿴����
    return 0;
}