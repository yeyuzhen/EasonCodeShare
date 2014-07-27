/**
 * @file SessionDB.h
 */

#ifndef SESSIONDB_H_
#define SESSIONDB_H_

#include <iostream>
#include <string>
#include <utility>
#include <boost/smart_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <boost/thread.hpp>

using namespace std;
using namespace boost;

class Session;

typedef shared_ptr<Session> SessionSharedPtr;
typedef weak_ptr<Session> SessionWeakPtr;
typedef unordered_map<string, SessionSharedPtr> SessionMap;

class SessionDB
{
public:
	bool Add(const string &_sessionId, SessionSharedPtr _session);

	bool Lookup(const string &_sessionId, SessionWeakPtr &session_);

	bool Remove(const string &_sessionId);

private:
	SessionMap m_cSessionMap;
	boost::mutex m_cSessionMapMutex;
};

class Global
{
public:
	static SessionDB m_cSessionDB;
};

#define SESSION_DB() Global::m_cSessionDB

#endif /* SESSIONDB_H_ */
