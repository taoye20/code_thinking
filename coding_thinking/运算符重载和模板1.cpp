#include<iostream>
using namespace std;

template<typename T>
class Person {
public:
    Person(string name, T age) : m_name(name), m_age(age) {}

    bool operator < (const Person& person) const {   //注意要有const好习惯
        return this->m_age < person.m_age;
    }

    string getName() const {
        return m_name;
    }

    T getAge() const {
        return m_age;
    }
private:
    string m_name;
    T m_age;
};

template<class class_type>
inline
const class_type& Min(const class_type& A, const class_type& B) {
    return A < B ? A : B;
}

int main() {
    Person<int> p1("xx", 24);
    Person<int> p2("ty", 23);
    cout << (p1 < p2) << endl;
    cout << Min(p1, p2).getName() << endl;
    return 0;
}