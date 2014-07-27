/**
 * @file main.cpp
 */

#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include "Session.h"
#include "SessionDB.h"

using namespace std;
using namespace boost;

void WorkFunction(string _sessionId)
{
	SessionWeakPtr wpSession;
	SESSION_DB().Lookup(_sessionId, wpSession);

	// 提升在前，移除在后
	SessionSharedPtr spSession = wpSession.lock();  // 线程安全的提升操作

	sleep(3);
	if(spSession)  // 此处，Session 早已从 SESSION_DB 移除
	{
		spSession->doSomething();
	}
	else
	{
		cout << "WorkFunction, Session removed." << endl;
	}
}

void TimerFunction(string _sessionId)
{
	sleep(1);
	SESSION_DB().Remove(_sessionId);
}

int main(int argc, char *argv[])
{
	string sSessionId("0");
	SessionSharedPtr spSession(new Session(sSessionId));
	SESSION_DB().Add(sSessionId, spSession);
	spSession.reset();

	thread workThread(bind(&WorkFunction, sSessionId));
	thread timerThread(bind(&TimerFunction, sSessionId));

	workThread.join();
	timerThread.join();

	return (0);
}
