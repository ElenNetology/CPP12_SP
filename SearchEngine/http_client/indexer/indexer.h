#pragma once

#include "html_parser/html_parser.h"
#include "links_getter/links_getter.h"
#include "sql_database/sql_database.h"
#include <string>

/**
 * @brief ����������.
 * @details ���������� ������� HTML-���� �� ��������, � ����� ������� ��� �����
 * ����������, �������� �����, ���������, �������� ������ ������ �����. �����
 * ���������� ����������� ����� �� �������� � ��������� ���������� � ���� ������
 * ��� ����, ����� ����� ����� �� ���� ������.
 */
class Indexer {
public:
	/**
	 * @brief �����������.
	 * @param sqlDataConnection ������ ��� ���������� � SQL ��.
	 */
	Indexer(const SqlDataConnection& sqlDataConnection);

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
	 * @brief �������� ������������ HTML-��������.
	 * @return ������������ HTML-�������� � ���� ������.
	 */
	std::string getHandledHtml() const;

	/**
	 * @brief ������� ������� "documents", "words", "documents_words".
	 */
	void dropTables();

private:
	//! SQL ���� ������.
	SqlDatabase sqlDatabase_;
	//! HTML-������.
	HtmlParser htmlParser_;
	//! links-������.
	LinksGetter linksGetter_;

	/**
	 * @brief ���������� HTML-��������.
	 */
	void handleHtml();
};

