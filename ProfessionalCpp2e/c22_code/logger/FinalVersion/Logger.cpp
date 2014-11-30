#include "Logger.h"
#include <fstream>
#include <iostream>

using namespace std;

Logger::Logger() : mThreadStarted(false), mExit(false)
{
	// Start background thread.
	mThread = thread{&Logger::processEntries, this};
	// Wait until background thread starts its processing loop.
	unique_lock<mutex> lock(mMutexStarted);
	mCondVarStarted.wait(lock, [&](){return mThreadStarted == true;});
}

Logger::~Logger()
{
	// Gracefully shut down the thread by setting mExit
	// to true and notifying the thread.
	mExit = true;
	// Notify condition variable to wake up thread.
	mCondVar.notify_all();
	// Wait until thread is shut down.
	mThread.join();
}

void Logger::log(const std::string& entry)
{
	// Lock mutex and add entry to the queue.
	unique_lock<mutex> lock(mMutex);
	mQueue.push(entry);

	// Notify condition variable to wake up thread.
	mCondVar.notify_all();
}

void Logger::processEntries()
{
	// Open log file.
	ofstream ofs("log.txt");
	if (ofs.fail()) {
		cerr << "Failed to open logfile." << endl;
		return;
	}

	// Start processing loop.
	unique_lock<mutex> lock(mMutex);

	// Notify listeners that thread is starting processing loop.
	mThreadStarted = true;
	mCondVarStarted.notify_all();

	while (true) {
		// Wait for a notification.
		mCondVar.wait(lock);

		// Condition variable is notified, so something is in the queue
		// and/or we need to shut down this thread.
		lock.unlock();
		while (true) {
			lock.lock();
			if (mQueue.empty()) {
				break;
			} else {
				ofs << mQueue.front() << endl;
				mQueue.pop();
			}
			lock.unlock();
		}
		if (mExit)
			break;
	}
}
