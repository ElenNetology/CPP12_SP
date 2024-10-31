#pragma once

#include <map>
#include <pqxx/pqxx>
#include <string>

/**
 * @brief ������ ��� ���������� � SQL ����� ������ (��).
 */
struct SqlDataConnection {
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
 * @brief SQL ��.
 * @details ��� �������� ���������� � ����������� ���� ����� �������������� ���
 * ������� � ����������� � ������ � � �������������  ����� ���� ������
 * �������-��-������ � ������� ������������� �������. � ��� �� �������������
 * ������� ����� �������� ������� ������������� ���� � ���������.
 */
class SqlDatabase {
public:
	/**
	 * @brief �����������.
	 * @details ������ ������ ���������� pqxx::connection � ��������� ������ ���
	 * ����������� � �� PostgreSQL.
	 * @param sqlDataConnection ������ ��� ���������� � SQL ����� ������ (��).
	 */
	SqlDatabase(const SqlDataConnection& sqlDataConnection);

	/**
	 * @brief ����������.
	 * @details ��������� ���������� �� �� � ��������� ��� ������
	 * SqlDatabase.
	 */
	~SqlDatabase();

	/**
	 * @brief ���������� URL ������ ��������.
	 * @param URL URL ���������.
	 */
	void setURL(const std::string URL);

	/**
	 * @brief ���������� ����� ����� �� ���������.
	 * @param word �����.
	 */
	void setWord(const std::string word);

	/**
	 * @brief �������� id URL ���������, id ����� � ���������� ���� � ��������� �
	 * ������� ������.
	 */
	void addIds();

	/**
	 * @brief ������� ������� "documents", "words", "documents_words".
	 */
	void dropTables();

private:
	//! ������ ��� ���������� � SQL ��.
	SqlDataConnection sqlDataConnection_;
	//! ���������� � �� SQL.
	std::unique_ptr<pqxx::connection> c_;
	//! URL ������ ���������.
	std::string URL_;
	//! ������� ���������� � ����.
	std::map<std::string, std::vector<std::string>> documentsWords_;
	//! ������� ���� � �� ���������� � ���������.
	std::map<std::string, int> wordsCounts_;

	/**
	 * @brief ������� ������� "documents", "words", "documents_words".
	 */
	void createTables();

	/**
	 * @brief ������� ������� "documents".
	 */
	void createTableDocuments();

	/**
	 * @brief ������� ������� "words".
	 */
	void createTableWords();

	/**
	 * @brief ������� ������� "documents_words".
	 */
	void createTableDocumentsWords();

	/**
	 * @brief ���������� ���������� ����.
	 */
	void findWordsCounts();
};
