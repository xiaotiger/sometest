#include <mutex>
#include <deque>

template <typename T>
class SyncQueue {

private:
	std::deque<T> _queue;
	std::mutex _mutex;
};
