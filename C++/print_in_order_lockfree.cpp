#include <memory>
#include <mutex>
#include <thread>
#include <unordered_map>
class Foo {
 public:
  Foo() {
    _th = std::make_shared<std::thread>([this]() {
      while (!(_first && _second && _third))
        ;
      size_t i = 0;
      _task[++i]();
      _task[++i]();
      _task[++i]();
  });
  }
  ~Foo() { _th->join();
  }

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    _task[1] = std::move(printFirst);
    _first = true;
  }

  void second(function<void()> printSecond) {
    // printSecond() outputs "second". Do not change or remove this line.
    _task[2] = std::move(printSecond);
    _second = true;
  }

  void third(function<void()> printThird) {
    // printThird() outputs "third". Do not change or remove this line.
    _task[3] = std::move(printThird);
    _third = true;
  }

 private:
  typedef std::function<void()> Handler;
  std::unordered_map<size_t, Handler> _task;
  std::shared_ptr<std::thread> _th;
  bool _first = false;
  bool _second = false;
  bool _third = false;
};