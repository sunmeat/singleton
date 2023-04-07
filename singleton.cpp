#include <iostream>
using namespace std;

// In software engineering, the Application pattern is a software design pattern
// that restricts the instantiation of a class to one "single" instance.
// This is useful when exactly one object is needed to coordinate actions across the system.

// https://refactoring.guru/ru/design-patterns/Singleton

// Another Singleton LOGGER EXAMPLE: https://git.io/vo9CN

class Application {
	static Application* instance;
	int window_width;
	int window_height;
	string localization;

	// private:
	Application() {
		window_width = 800;
		window_height = 600;
		localization = "uk";
	}

public:
	static Application* getInstance() {
		if (instance == nullptr)
			instance = new Application;
		return instance;
	}

	int getWidth() const {
		return window_width;
	}

	int getHeight() const {
		return window_height;
	}

	void setWidth(int width) {
		window_width = width;
	}

	void setHeight(int height) {
		window_height = height;
	}
};

Application* Application::instance = nullptr;

int main() {
	Application* app = Application::getInstance();
	// Application object; // ERROR
	// Application* dynamic_object = new Application; // ERROR
	cout << app->getWidth() << "\n"; // 800
	app->setWidth(1024); 
	cout << app->getWidth() << "\n"; // 1024
}
