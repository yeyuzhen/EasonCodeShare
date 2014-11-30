#ifndef LOGGER_H
#define LOGGER_H

#include <queue>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

class Logger
{
public:
	// Starts a background thread writing log entries to a file.
	Logger();
	// Gracefully shut down background thread.
	virtual ~Logger();
	// Add log entry to the queue.
	void log(const std::string& entry);

protected:
	void processEntries();
	bool mThreadStarted;
	bool mExit;
	// Mutex and condition variable to protect access to the queue.
	std::mutex mMutex;
	std::condition_variable mCondVar;
	std::queue<std::string> mQueue;
	// The background thread.
	std::thread mThread;

	// Mutex and condition variable to detect when the thread
	// starts executing its loop.
	std::mutex mMutexStarted;
	std::condition_variable mCondVarStarted;

private:
	// Prevent copy construction and assignment.
	Logger(const Logger& src);
	Logger& operator=(const Logger& rhs);
};

#endif
