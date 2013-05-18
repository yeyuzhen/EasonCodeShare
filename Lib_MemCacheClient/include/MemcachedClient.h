#ifndef _MEMCACHED_CLIENT_
#define _MEMCACHED_CLIENT_

#include <boost/cstdint.hpp>

#include "MemcacheProtocolClient.h"


class MemcachedClient : public MemcacheProtocolClient
{
public:
    MemcachedClient(){}

    ~MemcachedClient(){};

    /**
    * @brief 获取 _key 对应的 value_ 值
    *
    * @param [in] _key 需要 Get 操作的 Key-Value 对的 Key
    * @param [out] Value 的内容
    * @param [out] CAS 值
    *
    * @return  参见 enum_Result 定义
    *
    * @throw std::exception MemCacheClient 内部抛出的异常
    * @throw std::runtime_error 未知异常
    *
    */
    int CasGet(const std::string &_key, std::string &value_, boost::uint64_t &cas_);

    /**
    * @brief CasSet 操作
    *
    * @param [in] _key 需要 Set 操作的 Key-Value 对的 Key
    * @param [in] _data 包含 Value 的字符串 
    * @param [in] _size Value 字符串的长度
    * @param [in] _cas CAS 值
    *
    * @return Set 操作成功：true；操作失败：false
    *
    * @throw std::exception MemCacheClient 内部异常
    * @throw std::runtime_error 未知异常
    */
    bool CasSet(const std::string &_key, const char *_data, size_t _size, boost::uint64_t _cas);

    // 同上
    bool CasSet(const std::string &_key, const std::string &_value, boost::uint64_t _cas)
    {
        return CasSet(_key, _value.c_str(), _value.length(), _cas);
    }
};


#endif  // _MEMCACHED_CLIENT_



