#include<iostream>
using namespace std;


//���࣬����ԭ��������
class Cpu {
public:
	virtual void calculator() = 0;
};

class VideoCard {
public:
	virtual void display() = 0;
};

class Memory {
public:
	virtual void storage() = 0;
};


//���࣬һ������
class Computer {
public:
	Computer(Cpu* cpu, VideoCard* videocard, Memory* memory) : m_cpu(cpu), m_videocard(videocard), m_memory(memory) {}

	~Computer() {
		if (m_cpu != NULL) delete m_cpu;
		if (m_videocard != NULL) delete m_videocard;
		if (m_memory != NULL) delete m_memory;
	}

	//���Թ���
	void work() {
		m_cpu->calculator();
		m_videocard->display();
		m_memory->storage();
	}

private:
	Cpu* m_cpu;
	VideoCard* m_videocard;
	Memory* m_memory;
};


//intel�������������
class IntelCpu : public Cpu {
public:
	void calculator() {
		cout << "intel cpu��ʼ����" << endl;
	}
};

class IntelVideoCard : public VideoCard {
public:
	void display() {
		cout << "intel�Կ���ʼ��ʾ" << endl;
	}
};

class IntelMemory : public Memory {
public:
	void storage() {
		cout << "intel�洢����" << endl;
	}
};

//����������ͬ��

int main() {
	Computer* computer = new Computer(new IntelCpu, new IntelVideoCard, new IntelMemory);
	computer->work();
	delete computer;

	return 0;
}
