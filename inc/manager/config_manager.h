/*******************************************************************************
* �� �� �� : config_manager.h
* �������� : 2022 - 07 - 11
* ��    �� : rzyang
* �������� : ���ù�����������ӱ����ļ����ƶ˻�ȡ���ã���ʱ���ƶ�ͬ�������ļ�
* ******************************************************************************/
#pragma once

#include <string>

#include "err_code.h"

enum CONFIG_GET_METHOD_E {
	CONFIG_GET_METHOD_LOCAL = 0X01,
	CONFIG_GET_METHOD_CLOUD = 0X02
};

class ConfigManager {
public:
	~ConfigManager() = default;

	static ERR_CODE get_config(Config& config, CONFIG_GET_METHOD_E method, bool force_cloud = true);

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