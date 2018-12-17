#ifndef _BLACKLIST_IP_
#define _BLACKLIST_IP_

#include <curl/curl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

namespace blacklist
{
    static std::vector<std::string> ip_list;
    const std::vector<std::string> get_ip_list();
    void read_blacklist_from_url(const bool testnet);
    std::string get_host(std::string ip);
    std::vector<std::string> split_string(const std::string& str, const std::string& delimiter);
    size_t curl_write_callback(void *contents, size_t size, size_t nmemb, void *userp);
};

#endif