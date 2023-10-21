#include<iostream>
using namespace std;


//基类，三种原件纯虚类
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


//基类，一个电脑
class Computer {
public:
	Computer(Cpu* cpu, VideoCard* videocard, Memory* memory) : m_cpu(cpu), m_videocard(videocard), m_memory(memory) {}

	~Computer() {
		if (m_cpu != NULL) delete m_cpu;
		if (m_videocard != NULL) delete m_videocard;
		if (m_memory != NULL) delete m_memory;
	}

	//电脑工作
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


//intel电脑配件，子类
class IntelCpu : public Cpu {
public:
	void calculator() {
		cout << "intel cpu开始计算" << endl;
	}
};

class IntelVideoCard : public VideoCard {
public:
	void display() {
		cout << "intel显卡开始显示" << endl;
	}
};

class IntelMemory : public Memory {
public:
	void storage() {
		cout << "intel存储运行" << endl;
	}
};

//联想电脑配件同理

int main() {
	Computer* computer = new Computer(new IntelCpu, new IntelVideoCard, new IntelMemory);
	computer->work();
	delete computer;

	return 0;
}
