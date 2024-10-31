#pragma once

#include "../../utils/http_utils.h"
#include <regex>
#include <string>
#include <vector>

/**
 * @brief links-������.
 * @details ����� ���������� �������� ����� �������� ��� ������ � �� �
 * ��������� �� � ������� �� ����������.
 */
class LinksGetter {
public:
	/**
	 * @brief �����������.
	 */
	LinksGetter();

	/**
	 * @brief ���������� HTML-��������.
	 * HTML-�������� � ���� ������.
	 * @param html HTML-��������.
	 */
	void setHtml(const std::string html);

	/**
	 * @brief ���������� ������ �� ������� HTML-��������.
	 * @param link ������ �� HTML-��������.
	 */

	void setCurrentLink(const httputils::Link& link);

	/**
	 * @brief �������� ������.
	 * @return ������ � ������� HTML-��������.
	 */
	std::vector<httputils::Link> getLinks() const;

	/**
	 * @brief �������� URL.
	 * @return ������ URL ������� HTML-��������.
	 */
	std::string getURL();

private:
	//! HTML-��������.
	std::string html_;
	//! ������ HTML-��������.
	httputils::Link link_;
	//! ������.
	std::vector<httputils::Link> links_;
	//! HTML-���.
	std::regex htmlTag_;
	//! URL-�����.
	std::regex urlRegex_;

	/**
	 * @brief ���������� HTML-��������.
	 */
	void handleHtml();
};

