#pragma once

#include <regex>
#include <string>

/**
 * @brief HTML-������.
 * @details �������� ��������� �� HTML-�����, �� ������ ����������, ���������,
 * ��������� ����� � �. �. �������� ������ �����, ���������� ���������; �����
 * ����������� � ������ �������. ��� �������� ������������� ��� ����� ������
 * ��� ��� ������� 32 ��������;
 */
class HtmlParser {
public:
	/**
	 * @brief �����������.
	 */
	HtmlParser();

	/**
	 * @brief ���������� HTML-��������.
	 * HTML-�������� � ���� ������.
	 * @param html HTML-��������.
	 */
	void setHtml(const std::string html);

	/**
	 * @brief �������� ������������ HTML-��������.
	 * @return ������������ HTML-�������� � ���� ������.
	 */
	std::string getHandledHtml() const;

private:
	//! HTML-��������.
	std::string html_;
	//! ������������ HTML-��������.
	std::string htmlHandled_;
	//! HTML-����.
	std::regex htmlTags_;
	//! ����� ����������, ���������, ��������� ����� � �.�.
	std::regex nonAlnum_;
	//! ����� ������ 3 ��������.
	std::regex pattern_;

	/**
	 * @brief ���������� HTML-��������.
	 */
	void handleHtml();
};

