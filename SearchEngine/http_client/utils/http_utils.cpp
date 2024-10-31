#include "http_utils.h"

#include <iostream>
#include <regex>

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <openssl/ssl.h>

namespace httputils {

    namespace beast = boost::beast;
    namespace http = beast::http;
    namespace net = boost::asio;
    namespace ip = boost::asio::ip;
    namespace ssl = boost::asio::ssl;

    using tcp = boost::asio::ip::tcp;

    bool isText(const boost::beast::multi_buffer::const_buffers_type& b) {
        for (auto itr = b.begin(); itr != b.end(); itr++) {
            for (int i = 0; i < (*itr).size(); i++) {
                if (*((const char*)(*itr).data() + i) == 0) {
                    return false;
                }
            }
        }

        return true;
    }
