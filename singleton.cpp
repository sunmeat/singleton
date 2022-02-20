#include <iostream>
using namespace std;

// In software engineering, the singleton pattern is a software design pattern
// that restricts the instantiation of a class to one "single" instance.
// This is useful when exactly one object is needed to coordinate actions across the system.

// https://refactoring.guru/ru/design-patterns/singleton

// SINGLETON LOGGER EXAMPLE: https://git.io/vo9CN

class Singleton
{
	static Singleton* instance;
	int data;

// private:
	Singleton()
	{
		data = 50;
	}

public:
	static Singleton* GetInstance()
	{
		if (instance == nullptr)
			instance = new Singleton;
		return instance;
	}

	int GetData() const
	{
		return data;
	}

	void SetData(int value)
	{
		data = value;
	}
};

Singleton* Singleton::instance = nullptr;

int main()
{
	Singleton* s = Singleton::GetInstance();
	// Singleton object; // ERROR
	// Singleton* dynamic_object = new Singleton; // ERROR
	cout << s->GetData() << "\n";
	s->SetData(75);
	cout << s->GetData() << "\n";
}