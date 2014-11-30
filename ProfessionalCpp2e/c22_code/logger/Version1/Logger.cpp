#include "Logger.h"
#include <fstream>
#include <iostream>

using namespace std;

Logger::Logger()
{
	// Start background thread.
	mThread = thread{&Logger::processEntries, this};
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
	while (true) {
		// Wait for a notification.
		mCondVar.wait(lock);

		// Condition variable is notified, so something is in the queue.
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
	}
}
