/*******************************************************************************
* �� �� �� : config_manager.h
* �������� : 2022 - 07 - 11
* ��    �� : rzyang
* �������� : ���ù�����������ӱ����ļ����ƶ˻�ȡ���ã���ʱ���ƶ�ͬ�������ļ�
* ******************************************************************************/
#pragma once

#include <string>

#include "err_code.h"
#include "config.h"


class ConfigManager {
public:
	~ConfigManager() = default;

	static ERR_CODE get_config_from_local(Config& config, const std::string& config_path);

	static ERR_CODE get_config_from_cloud(Config& config);

	static ERR_CODE start_fetch_thread();

private:
	ConfigManager() = default;

	/**
	 * ��������: ����������
	 *
	 * ���������config
	 * ���������config_string		Json�ַ���
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE parse_config(Config& config, const std::string& config_string);
};