#include "MemcachedClient.h"

int MemcachedClient::CasGet(const std::string &_key, std::string &value_, boost::uint64_t &cas_)
{
    try
    {
        boost::unique_lock<boost::mutex> guard(m_cMutex);
        
        MemCacheClient::MemRequest cGetReq;
        cGetReq.mKey = _key.c_str();

        if(1 == m_cMemCacheClientPtr->Gets(cGetReq))
        {
            value_.clear();
            value_.append(cGetReq.mData.GetReadBuffer(), cGetReq.mData.GetReadSize());
            cas_ = cGetReq.mCas;
        }

        return cGetReq.mResult;
    }
    catch(std::exception &e)
    {
        throw e;
    }
    catch(...)
    {
        throw std::runtime_error("MemcacheClient::CasGet() unknown exception.");
    }
}


int MemcachedClient::CasSet(const std::string &_key, const char *_data, size_t _size, boost::uint64_t _cas)
{
    try
    {
        boost::unique_lock<boost::mutex> guard(m_cMutex);
        
        MemCacheClient::MemRequest cSetReq;
        cSetReq.mKey = _key.c_str();
        cSetReq.mData.WriteBytes(_data, _size);
        cSetReq.mCas = _cas;

        m_cMemCacheClientPtr->CheckSet(cSetReq);
        
        return cSetReq.mResult;
    }
    catch(std::exception &e)
    {
        throw e;
    }
    catch(...)
    {
        throw std::runtime_error("MemcacheClient::CasSet() unknown exception.");
    }

    return false;
}


