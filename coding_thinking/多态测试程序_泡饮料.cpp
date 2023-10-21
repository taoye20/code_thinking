#include<iostream>
#include<vector>
using namespace std;

class AbstractDrinking {
public:
	virtual void Boil() = 0;
	virtual void Berw() = 0;
	virtual void Pourincup() = 0;
	virtual void Putotherthing() = 0;

	void makeDrink() {
		Boil();
		Berw();
		Pourincup();
		Putotherthing();
	}
};

class Coffee : public AbstractDrinking {
public:
	void Boil() {
		cout << "开水" << endl;
	}

	void Berw() {
		cout << "倒咖啡" << endl;
	}

	void Pourincup() {
		cout << "装杯" << endl;
	}

	void Putotherthing() {
		cout << "加奶" << endl;
	}
};

void doWork(AbstractDrinking* abs) {
	abs->makeDrink();
	delete abs;
}

int main() {
	doWork(new Coffee);
	return 0;
}