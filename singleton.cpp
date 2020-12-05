/*
	The Singleton pattern ensures that a class has only one instance and provides a global point of access 
	to that instance. It is named after the singleton set, which is defined to be a set containing one element. 
	This is useful when exactly one object is needed to coordinate actions across the system.

	Check list

		Define a private static attribute in the "single instance" class.
		Define a public static accessor function in the class.
		Do "lazy initialization" (creation on first use) in the accessor function.
		Define all constructors to be protected or private.
		Clients may only use the accessor function to manipulate the Singleton.
*/
#include <stdexcept>
#include <iostream>
#include <memory>
using namespace std;

class Singleton {
private:
	Singleton(const std : string value) : value_(value) {}
	static Singleton* singleton_;
	std::string value_;

public:
	// Singleton should not be cloneable
	Singleton(Singleton& other) = delete;
	// Singleton should not be assignable
	void operator=(const Singleton&) = delete;

	static Singleton* GetInstance(const std::string& value);

	std::string GetValue() const { return value_; }
};

Singleton* Singleton::singleton_ = nullptr;

Singleton* Singleton::GetInstance(const std::string& value) {
	if (singleton_ == nullptr) {
		singleton_ = new Singleton(value);
	}
	return singleton_;
}

void ThreadFoo() {
	// Following code emulates slow initialization.
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton* singleton = Singleton::GetInstance("FOO");
	std::cout << singleton->value() << "\n";
}

void ThreadBar() {
	// Following code emulates slow initialization.
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton* singleton = Singleton::GetInstance("BAR");
	std::cout << singleton->value() << "\n";
}

int main() {
	std::cout << "If you see the same value, then singleton was reused (yay!\n" <<
		"If you see different values, then 2 singletons were created (booo!!)\n\n" <<
		"RESULT:\n";
	std::thread t1(ThreadFoo);
	std::thread t2(ThreadBar);
	t1.join();
	t2.join();

	return 0;
}