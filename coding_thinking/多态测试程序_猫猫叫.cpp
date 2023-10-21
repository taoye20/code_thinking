#include<iostream>
#include<vector>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "动物构造函数" << endl;
    }

    virtual ~Animal() {   //父类析构函数使用virtual，可以实现子类的析构函数调用，你看看不加试试
        cout << "动物析构函数" << endl;
    }

    virtual void speak() {   
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string name) {
        cout << "猫构造函数" << endl;
        m_Name = new string(name);  //在子类中开辟堆区
    }

    ~Cat() {
        cout << "猫析构函数" << endl;
        if (m_Name != NULL) {    //使用子类析构函数释放内存
            delete m_Name;
        }
    }

    void speak() {
        cout<< *m_Name << "猫在说话喵喵喵" << endl;
    }

    string* m_Name;
};

int main() {
    Animal* cat = new Cat("Tom");
    cat->speak();
    delete cat;     //这里delete的是父类指针，不会调用子类的析构函数，子类有创建堆区，即便在子类中写了析构函数delete堆区也没有用，导致内存泄漏，怎么办看上面
    return 0;
}