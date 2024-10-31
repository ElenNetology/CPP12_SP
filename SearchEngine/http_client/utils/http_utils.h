#pragma once

#include <string>
#include <vector>

namespace httputils {

    //! ��� ���������.
    enum ProtocolType {
        //! HTTP-��������.
        HTTP,
        //! HTTPS-��������.
        HTTPS
    };

    //! �������� ������.
    struct Link {
        ProtocolType protocol;
        std::string hostName;
        std::string query;
        Link();
        Link(ProtocolType protocol_, std::string hostName_, std::string query_) {
            protocol = protocol_;
            hostName = hostName_;
            query = query_;
        }

        bool operator==(const Link& l) const {
            return protocol == l.protocol && hostName == l.hostName && query == l.query;
        }
    };

    /**
     * @brief �������� ���������� HTML-��������.
     * @param link �������� ������.
     * @return ���������� HTML-��������.
     */
    std::string getHtmlContent(const Link& link);

    /**
     * @brief ���������� ��� ���������.
     * @param ptococol �������� ������ � ���� ������.
     * @return �������� ������.
     */
    httputils::ProtocolType setProtocolType(const std::string protocol);

    /**
     * @brief �������� �������� HTML-��������.
     * @param ptococolType ��� ��������� ������.
     * @return �������� ������� HTML-��������.
     */
    std::string getProtocol(const httputils::ProtocolType& protocolType);

} // namespace httputils