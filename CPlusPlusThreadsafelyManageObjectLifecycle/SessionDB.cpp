/**
 * @file SessionDB.cpp
 */

#include "Session.h"
#include "SessionDB.h"

bool SessionDB::Add(const string &_sessionId, SessionSharedPtr _session)
{
	boost::mutex::scoped_lock cLock(m_cSessionMapMutex);

	try
	{
		pair<SessionMap::iterator, bool> cInsertResult
			= m_cSessionMap.insert(make_pair(_sessionId, _session));
		if(cInsertResult.second)
		{
			return true;
		}
	}
	catch(...)
	{
		cout << "SessionDB::Add, catch unknown exception." << endl;
	}

	return false;
}

bool SessionDB::Lookup(const string &_sessionId, SessionWeakPtr &session_)
{
	boost::mutex::scoped_lock cLock(m_cSessionMapMutex);

	try
	{
		SessionMap::iterator iter = m_cSessionMap.find(_sessionId);
		if(iter != m_cSessionMap.end())
		{
			session_ = static_cast<SessionWeakPtr>(iter->second);
			return true;
		}
	}
	catch(...)
	{
		cout << "SessionDB::Lookup, catch unknown exception." << endl;
	}

	return false;
}

bool SessionDB::Remove(const string &_sessionId)
{
	boost::mutex::scoped_lock cLock(m_cSessionMapMutex);

	try
	{
		if(m_cSessionMap.erase(_sessionId))
		{
			return true;
		}
	}
	catch(...)
	{
		cout << "SessionDB::Remove, catch unknown exception."  << endl;
	}

	return false;
}

SessionDB Global::m_cSessionDB;
