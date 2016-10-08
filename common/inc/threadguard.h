#pragma once

#include <thread>

class ThreadGuard
{
public:
	ThreadGuard() : t{} {}
	ThreadGuard(std::thread t_) : t(std::move(t_)) {}
	~ThreadGuard() {
		t.join();
	}

	ThreadGuard(const ThreadGuard& x) = delete;
	ThreadGuard& operator=(const ThreadGuard& x) = delete;

	friend void swap(ThreadGuard& first, ThreadGuard& second) {
		using std::swap;
		swap(first.t, second.t);
	}

	ThreadGuard(ThreadGuard&& x) : ThreadGuard{} {
		swap(*this, x);
	}

	ThreadGuard& operator=(ThreadGuard&& x) {
		swap(*this, x);
		return *this;
	}
		
private:
	std::thread t;
};
