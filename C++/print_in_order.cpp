#include <mutex>
class Foo {
 public:
  Foo() {}

  void first(function<void()> printFirst) {
    std::lock_guard<std::mutex> auto_lock{_first_mutex};
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    _frist = true;
  }

  void second(function<void()> printSecond) {
    do {
      std::lock_guard<std::mutex> auto_lock{_first_mutex};
      if (_first) {
        break;
      }
    } while (true);
    // printSecond() outputs "second". Do not change or remove this line.
    std::lock_guard<std::mutex> auto_lock{_second_mutex};
    printSecond();
    _second = true;
  }

  void third(function<void()> printThird) {
    do {
      std::lock_guard<std::mutex> auto_lock{_second_mutex};
	  if (_second)
	  {
        break;
	  }
    } while (true);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  bool _first = false;
  std::mutex _first_mutex;
  bool _second = false;
  std::mutex _second_mutex;
};