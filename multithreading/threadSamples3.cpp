//
// Created by ogier on 2023/11/12.
//多线程示例，建议alt+7，设计保险箱保护多线程对象
#include<iostream>
#include<string>
#include<thread>
#include<queue>
#include <mutex>
using namespace std;

template<typename T>
class  MutexSafe {
 private:
	//互斥锁
	mutex _mutex;
	//被保护的对象
	T *_resource;
	T *operator->() {}
	T &operator&() {}
 public:
	//使用列表初始化
	MutexSafe(T *resource) : _resource(resource) {}
	~MutexSafe() { delete _resource; }
	void lock() {
		_mutex.lock();
	}
	void unlock() {
		_mutex.unlock();
	}
	bool try_lock() {
		return _mutex.try_lock();
	}
	mutex &Mutex() {
		return _mutex;
	}
	template<class SafeT>
	//Acquire函数仅仅返回_resource的引用，必传入锁才能使用对象
	T &Acquire(unique_lock<SafeT> &lock) {
		return *_resource;
	}
};

void PeterWrite(string &blackboard) {
	blackboard += "my";
	this_thread::sleep_for(chrono::milliseconds(rand() % 3));
	blackboard += " name";
	this_thread::sleep_for(chrono::milliseconds(rand() % 3));
	blackboard += " is";
	this_thread::sleep_for(chrono::milliseconds(rand() % 3));
	blackboard += " Peter.\n";
}
void PeterWriteWithMutex(mutex &amutex, string &blackboard) {
	unique_lock<mutex> lock(amutex);
	PeterWrite(blackboard);
}
void QuagmireWrite(string &blackboard) {
	blackboard = +"my";
	this_thread::sleep_for(chrono::milliseconds(rand() % 3));
	blackboard += " name";
	this_thread::sleep_for(chrono::milliseconds(rand() % 3));
	blackboard += " is";
	this_thread::sleep_for(chrono::milliseconds(rand() % 3));
	blackboard += " Quagmire.\n";
}
void QuagmireWriteWithMutex(mutex &amutex, string &blackboard) {
	unique_lock<mutex> lock(amutex);
	QuagmireWrite(blackboard);
}
void TestNomalSafeLock() {
	//启用互斥锁
	string blackboard;
	mutex amutex;
	thread PeterThread(PeterWriteWithMutex, ref(amutex), ref(blackboard));
	thread QuagmireThread(QuagmireWriteWithMutex, ref(amutex), ref(blackboard));
	PeterThread.join();
	QuagmireThread.join();
	cout << blackboard << endl;
}

typedef MutexSafe<string> Safe;
void SafePeterWrite(Safe &safe) {
	unique_lock<Safe> lock(safe);
	string &blackboard = safe.Acquire(lock);
	PeterWrite(blackboard);
}
void SafeQuagmireWrite(Safe &safe) {
	unique_lock<Safe> lock(safe);
	string &blackboard = safe.Acquire(lock);
	QuagmireWrite(blackboard);
}
void TestSafeSmartLock() {
	Safe safe(new string());
	thread PeterThread(SafePeterWrite, ref(safe));
	thread QuagmireThread(SafeQuagmireWrite, ref(safe));
	PeterThread.join();
	QuagmireThread.join();
	unique_lock<Safe> lock(safe);
	string &blackboard = safe.Acquire(lock);
	cout << blackboard << endl;
}

int main() {
	TestSafeSmartLock();
	return 0;
}