/**
 * @file Session.h
 */

#ifndef SESSION_H_
#define SESSION_H_

#include <iostream>
#include <string>

using namespace std;

class Session
{
public:
	Session(const string &_sessionId)
		: m_sSessionId(_sessionId) {}

	void doSomething()
	{
		cout << "My session id : " << m_sSessionId << endl;
	}

private:
	Session();

	string m_sSessionId;
};


#endif /* SESSION_H_ */
