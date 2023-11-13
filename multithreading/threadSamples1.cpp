//
// Created by ogier on 2023/11/12.
// 一个简单的多线程示例，建议alt+7，看着点结构,使用互斥锁并unique_lock
#include<iostream>
#include<string>
#include<thread>
#include<queue>
#include <mutex>
using namespace std;

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
int main() {
	TestNomalSafeLock();

	return 0;
}