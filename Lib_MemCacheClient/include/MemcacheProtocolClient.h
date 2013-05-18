#ifndef _MEMCACHE_PROTOCOL_CLIENT_
#define _MEMCACHE_PROTOCOL_CLIENT_

/* @type head file
* @brief 基于 memcached 协议的客户端封装，适用于 memcached 和 kestrel
*
* @history
*  V1.0.1 yeyzh "设置客户端失败重连时间为 1s"
*  V1.0  yeyzh "基于 MemCacheClient 初步实现跨平台 memcached 客户端封装" 
*/

#include <string>
#include <map>
#include <stdexcept>

#include <boost/thread.hpp>
#include <boost/noncopyable.hpp>

#include <MemCacheClient.h>


class MemcacheProtocolClient : private boost::noncopyable
{
public:
    /*! @brief Result code for requests to a server. 

        Success codes are greater or equal to 0. 
        Failure codes are less than 0. 
     */
    enum enum_Result { 
        // success: n >= 0
        OK        = 0,    //!< Success
        NOREPLY   = 1,    //!< Success assumed (no reply requested)
        NOTSTORED = 2,    //!< Success but item not stored (see memcached docs)
        NOTFOUND  = 3,    //!< Success but item not found (see memcached docs)

        // failure: n < 0
        NOSERVER  = -1    //!< Failure, connection error with server
    };

    /**
    * @brief 构造函数
    *
    * @param [in] _host Memcache 服务器地址
    * @param [in] _port Mecchahe 服务器监听端口
    *
    * @throw std::bad_alloc 内部 MemCacheClient 成员动态分配内存失败
    * @throw std::runtime_error 未知异常
    * @throw std::exception MemCacheClient 内部异常
    */
    MemcacheProtocolClient();

    virtual ~MemcacheProtocolClient();

    std::string &GetErrorMsg(int _errorCode)
    {
        return m_cErrorCode2Msg.find(_errorCode)->second;
    }

    // 设置重连时间，单位 ms
    void SetReconnectPeriod(size_t _ms)
    {
        m_cMemCacheClientPtr->SetRetryPeriod(_ms);
    }

    /**
    * @brief Set 操作
    *
    * @param [in] _key 需要 Set 操作的 Key-Value 对的 Key
    * @param [in] _data 包含 Value 的字符串 
    * @param [in] _size Value 字符串的长度
    *
    * @return 参见 enum_Result 定义
    *
    * @throw std::exception MemCacheClient 内部异常
    * @throw std::runtime_error 未知异常
    */
    int Set(const std::string &_key, const char *_data, size_t _size);

    // 基本同上
    int Set(const std::string &_key, const std::string &_value)
    {
        return Set(_key, _value.c_str(), _value.length());
    }

    /**
    * @brief 获取 _key 对应的 value_ 值
    * @return  参见 enum_Result 定义
    *
    * @throw std::exception MemCacheClient 内部抛出的异常
    * @throw std::runtime_error 未知异常
    *
    */
    int Get(const std::string &_key, std::string &value_);


    /**
    * @brief 添加 Memcache 服务器
    *
    * @return 添加成功：true，添加失败：false
    *
    * @throw std::invalid_argument 内部 MemCacheClient 成员无效
    * @throw std::exception MemCacheClient 内部抛出的异常
    * @throw std::runtime_error 未知异常
    *
    * 本函数只判断 _host 和 _port 的规范性，和服务端的可用性无关。
    */
    bool AddServer(const std::string &_host, const std::string &_port);


    /**
    * @brief 删除所有 Memcached 服务器连接
    *
    * @throw std::invalid_argument 内部 MemcacheClient 成员无效
    * @throw std::exception MemCacheClient 内部抛出的异常
    * @throw std::runtime_error 未知异常
    *
    */
    void RemoveAllServer();

protected:
    std::auto_ptr<MemCacheClient> m_cMemCacheClientPtr;
    std::map<int, std::string> m_cErrorCode2Msg;
    boost::mutex m_cMutex;
};


#endif // _MEMCACHE_PROTOCOL_CLIENT_


