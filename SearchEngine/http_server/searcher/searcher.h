#pragma once

#include <pqxx/pqxx>
#include <string>
#include <vector>

/**
 * @brief ������ ��� ���������� � SQL ����� ������ (��).
 */
struct SearcherConnection {
	//! ��������� ����.
	std::string host;
	//! ���� �����������.
	std::string port;
	//! �������� ��.
	std::string dbname;
	//! ��� ������������.
	std::string user;
	//! ������ ��� ����������� � ��.
	std::string password;
};

/**
 * @brief ���������.
 * @details ��������� ����� �� ���� ������, ��������� ��������� � ���������� ���
 * ������������.
 */
class Searcher {
public:
	/**
	 * @brief �����������.
	 * @details ������ ������ ���������� pqxx::connection � ��������� ������ ���
	 * ����������� � �� PostgreSQL.
	 * @param searcherConnection ������ ��� ���������� � SQL ����� ������ (��).
	 */
	Searcher(const SearcherConnection& searcherConnection);

	/**
	 * @brief ����������.
	 * @details ��������� ���������� �� �� � ��������� ��� ������
	 * Searcher.
	 */
	~Searcher();

	/**
	 * @brief ���������� �������� ��� ������.
	 * @param value �������� ������.
	 */
	void setSearchValue(const std::string value);

	/**
	 * @brief ���������� ��������� ���������.
	 * @return URL ����������.
	 */
	std::vector<std::string> getSearchResult() const;

	/**
	 * @brief ��������� ������������� ������.
	 * @return true - ����������, false - �� ����������.
	 */
	bool isTablesExist() const;

private:
	//! ������ ��� ���������� � SQL ��.
	SearcherConnection searcherConnection_;
	//! ���������� � �� SQL.
	std::unique_ptr<pqxx::connection> c_;
	//! �������� ��� ������.
	std::string value_;
	//! ��������� ������.
	std::vector<std::string> searchResult_;
	//! ���������� �� ������� � ��.
	bool isTablesExist_;

	//! ������������ ���������� ���������� ������.
	const int searchResultCountMax_ = 10;

	/**
	 * @brief ����� ���������� ������.
	 */
	void findSearchResults();

	/**
	 * @brief ��������� ������������� ������.
	 */
	void checkTablesExistance();
};
