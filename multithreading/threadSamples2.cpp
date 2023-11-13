//
// Created by ogier on 2023/11/12.
// 一个简单的多线程示例，建议alt+7，看着点结构，无互斥锁
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

void QuagmireWrite(string &blackboard) {
	blackboard = +"my";
	this_thread::sleep_for(chrono::milliseconds(rand() % 3));
	blackboard += " name";
	this_thread::sleep_for(chrono::milliseconds(rand() % 3));
	blackboard += " is";
	this_thread::sleep_for(chrono::milliseconds(rand() % 3));
	blackboard += " Quagmire.\n";
}

void DemoResourceConflict() {
	//无互斥锁
	string blackboard;
	thread PeterThread(PeterWrite, ref(blackboard));
	thread QuagmireThread(QuagmireWrite, ref(blackboard));
	PeterThread.join();
	QuagmireThread.join();
	cout << blackboard << endl;
}
int main() {
	DemoResourceConflict();

	return 0;
}