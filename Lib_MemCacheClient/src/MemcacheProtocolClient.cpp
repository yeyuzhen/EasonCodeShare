#include "MemcacheProtocolClient.h"

MemcacheProtocolClient::MemcacheProtocolClient()
    try : m_cMemCacheClientPtr(new MemCacheClient)
{
    m_cMemCacheClientPtr->SetRetryPeriod(1 * 1000);  // 重连时间 1s

    m_cErrorCode2Msg.insert(std::pair<int, std::string>(OK, "OK"));
    m_cErrorCode2Msg.insert(std::pair<int, std::string>(NOREPLY, "NOREPLY"));
    m_cErrorCode2Msg.insert(std::pair<int, std::string>(NOTSTORED, "NOTSTORED"));
    m_cErrorCode2Msg.insert(std::pair<int, std::string>(NOTFOUND, "NOTFOUND"));
    m_cErrorCode2Msg.insert(std::pair<int, std::string>(NOSERVER, "NOSERVER"));
}
catch (std::exception &e)
{
    throw e;
}
catch(...)
{
    throw std::runtime_error("MemcacheProtocolClient::MemcacheProtocolClient() unknown exception.");
}

MemcacheProtocolClient::~MemcacheProtocolClient()
{
    try
    {
        m_cMemCacheClientPtr->ClearServers();
    }
    catch(...)
    {   // 防止析构的异常逃逸
    }   
}

int MemcacheProtocolClient::Set(const std::string &_key, const char *_data, size_t _size)
{
    try
    {
        boost::unique_lock<boost::mutex> guard(m_cMutex);

        MemCacheClient::MemRequest cSetReq;
        cSetReq.mKey = _key.c_str();
        cSetReq.mData.WriteBytes(_data, _size);

        m_cMemCacheClientPtr->Set(cSetReq);
        
        return cSetReq.mResult;
    }
    catch(std::exception &e)
    {
        throw e;
    }
    catch(...)
    {
        throw std::runtime_error("MemcacheProtocolClient::Set() unknown exception.");
    }

    return false;
}

int MemcacheProtocolClient::Get(const std::string &_key, std::string &value_)
{
    try
    {
        boost::unique_lock<boost::mutex> guard(m_cMutex);

        MemCacheClient::MemRequest cGetReq;
        cGetReq.mKey = _key.c_str();

        if(1 == m_cMemCacheClientPtr->Get(cGetReq))
        {
            value_.clear();
            value_.append(cGetReq.mData.GetReadBuffer(), cGetReq.mData.GetReadSize());
        }

        return cGetReq.mResult;
    }
    catch(std::exception &e)
    {
        throw e;
    }
    catch(...)
    {
        throw std::runtime_error("MemcacheProtocolClient::Get() unknown exception.");
    }
}

bool MemcacheProtocolClient::AddServer(const std::string &_host, const std::string &_port)
{
    if(m_cMemCacheClientPtr.get() == NULL)
    {
        throw std::invalid_argument("MemcacheProtocolClient::AddServer(),m_cMemCacheClientPtr is NULL.");
    }

    std::string sConnectString(_host);
    sConnectString.append(":");
    sConnectString.append(_port);

    try
    {
        boost::unique_lock<boost::mutex> guard(m_cMutex);

        if(m_cMemCacheClientPtr->AddServer(sConnectString.c_str()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(std::exception &e)
    {
        throw e;
    }
    catch(...)
    {
        throw std::runtime_error("MemcacheProtocolClient::AddServer() unknown exception.");
    }
}


void MemcacheProtocolClient::RemoveAllServer()
{
    if(m_cMemCacheClientPtr.get() == NULL)
    {
        throw std::invalid_argument("MemcacheProtocolClient::AddServer(),m_cMemCacheClientPtr is NULL.");
    }

    try
    {
        boost::unique_lock<boost::mutex> guard(m_cMutex);

        m_cMemCacheClientPtr->ClearServers();
    }
    catch(std::exception &e)
    {
        throw e;
    }
    catch(...)
    {
        throw std::runtime_error("MemcacheProtocolClient::RemoveAllServer() unknown exception.");
    }
}


