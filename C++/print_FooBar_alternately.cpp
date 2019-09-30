#include <condition_variable>
#include <mutex>
class FooBar {
private:
	int n;
	sem_t _foo;
	sem_t _bar;
public:
	FooBar(int n) {
		this->n = n;
		sem_init(&_foo, 0, 1);
		sem_init(&_bar, 0, 0);
	}

	void foo(function<void()> printFoo) {

		for (int i = 0; i < n; i++) {
			sem_wait(&_foo);
			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			sem_post(&_bar);
		}
	}

	void bar(function<void()> printBar) {

		for (int i = 0; i < n; i++) {
			sem_wait(&_bar);
			// printBar() outputs "bar". Do not change or remove this line.
			printBar();
			sem_post(&_foo);
		}
	}
};