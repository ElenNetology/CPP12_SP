#pragma once

#include "searcher/searcher.h"
#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

namespace httpsrvr {

    /**
     * @brief HTTP-����������.
     * @details ��������� �������, ������������ ��
     * � ���������� ������.
     */
    class HttpConnection : public std::enable_shared_from_this<HttpConnection> {
    public:
        /**
         * @brief �����������.
         * @param socket TCP-�����.
         * @param searcherConnection ������ ��� ����������� � ��.
         */
        HttpConnection(tcp::socket socket,
            const SearcherConnection& searcherConnection);

        /**
         * @brief ������ HTTP-����������.
         */
        void start();

    private:
        //! ��������� �����.
        tcp::socket socket_;
        //! ������ ��� ���������� � SQL ��.
        SearcherConnection searcherConnection_;
        //! ������ ��� ������ ������.
        beast::flat_buffer buffer_{ 8192 };
        //! HTTP-������.
        http::request<http::dynamic_body> request_;
        //! HTTP-�����.
        http::response<http::dynamic_body> response_;
        //! ������ ��� �������� ������.
        net::steady_timer deadline_{ socket_.get_executor(), std::chrono::seconds(60) };

        /**
         * @brief ������ �������.
         * @details ������ ������� �� ������ � ������ � �����.
         */
        void readRequest();
        /**
         * @brief ��������� �������.
         */
        void handleRequest();
        /**
         * @brief �������� ������� GET.
         */
        void createResponseGet();
        /**
         * @brief �������� ������� POST.
         */
        void createResponsePost();
        /**
         * @brief ������ ������.
         */
        void writeResponse();
        /**
         * @brief �������� ������������� �������� ������.
         */
        void checkDeadline();
    };

} // namespace httpsrvr
