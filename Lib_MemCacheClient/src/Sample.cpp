#include <iostream>
#include <string>

#ifdef WIN32
# include <winsock2.h>
# pragma comment(lib, "ws2_32.lib")
#endif

#include "MemcachedClient.h"

int main(int argc, char *argv[])
{
#ifdef WIN32
    WSADATA wsaData;
    int rc = WSAStartup(MAKEWORD(2,0), &wsaData);
    if (rc != 0) 
    {
        std::cout << "Failed to start winsock." << std::endl;
        return 1;
    }
#endif

    std::string sHost("127.0.0.1");
    std::string sPort("11211");

    MemcachedClient cMemcachedClient;
    cMemcachedClient.AddServer(sHost, sPort);

    // Get/Set example
    std::string sGetSetKey("Key");
    std::string sGetSetValue("Value");

    int iSetResult = cMemcachedClient.Set(sGetSetKey, sGetSetValue);
    if(MemcachedClient::OK == iSetResult)
    {
        std::cout << "Set " << sGetSetKey << "=>" << sGetSetValue << " success." << std::endl;
    }
    else
    {
        std::cout << "Set fail, ErrCode=" << iSetResult << ", ErrMsg=" << cMemcachedClient.GetErrorMsg(iSetResult) << "." << std::endl;
    }

    std::string sGetResult;
    int iGetResult = cMemcachedClient.Get(sGetSetKey, sGetResult);
    if(MemcachedClient::OK == iGetResult)
    {
        std::cout << "Get " << sGetSetKey << "=>" << sGetResult << " success." << std::endl;
    }
    else
    {
        std::cout << "Get fail, ErrCode=" << iGetResult << ", ErrMsg=" << cMemcachedClient.GetErrorMsg(iGetResult) << "." << std::endl;
    }

    // CasGet/CasSet example
    std::string sCasGetCasSetKey("Key");
    std::string sCasGetValue;
    boost::uint64_t uCasValue;

    int iCasGetResult = cMemcachedClient.CasGet(sCasGetCasSetKey, sCasGetValue, uCasValue);
    if (MemcachedClient::OK == iCasGetResult)
    {
        std::cout << "CasGet " << sCasGetCasSetKey << "=>" << sCasGetValue << " success." << std::endl;
    }
    else
    {
        std::cout << "CasGet fail, ErrCode=" << iCasGetResult << ", ErrMsg=" << cMemcachedClient.GetErrorMsg(iCasGetResult) << "." << std::endl;
    }

    //cMemcachedClient.Set(sGetSetKey, sGetSetValue);

    std::string sCasSetValue("CasSetValue");
    int iCasSetResult = cMemcachedClient.CasSet(sCasGetCasSetKey, sCasSetValue, uCasValue);
    if (MemcachedClient::OK == iCasSetResult)
    {
        std::cout << "CasSet " << sCasGetCasSetKey << "=>" << sCasSetValue << " success." << std::endl;
    }
    else
    {
        std::cout << "CasSet fail, ErrCode=" << iCasSetResult << ", ErrMsg=" << cMemcachedClient.GetErrorMsg(iCasSetResult) << "." << std::endl;
    }

#ifdef WIN32
    WSACleanup();
#endif

    return 0;
};