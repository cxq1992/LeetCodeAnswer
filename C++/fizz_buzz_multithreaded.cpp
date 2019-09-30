class FizzBuzz {
private:
	int n;
	int _i = 1;
	std::mutex _mutex;
public:
	FizzBuzz(int n) {
		this->n = n;
	}

	// printFizz() outputs "fizz".
	void fizz(function<void()> printFizz) {
		_mutex.lock();
		while (_i <= n)
		{
			if (_i % 3 == 0 && _i % 5 != 0)
			{
				printFizz();
				++_i;
			}
			_mutex.unlock();
		}

	}

	// printBuzz() outputs "buzz".
	void buzz(function<void()> printBuzz) {
		_mutex.lock();
		while (_i <= n)
		{
			if (_i % 3 != 0 && _i % 5 == 0)
			{
				printBuzz();
				++_i;
			}
			_mutex.unlock();
		}

	}

	// printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
		_mutex.lock();
		while (_i <= n)
		{
			if (_i % 3 == 0 && _i % 5 == 0)
			{
				printFizzBuzz();
				++_i;
			}
			_mutex.unlock();
		}

	}

	// printNumber(x) outputs "x", where x is an integer.
	void number(function<void(int)> printNumber) {
		_mutex.lock();
		while (_i <= n)
		{
			if (_i % 3 != 0 && _i % 5 != 0)
			{
				printNumber(_i);
				++_i;
			}
			_mutex.unlock();
		}

	}
};