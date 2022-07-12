/*******************************************************************************
* �� �� �� : config_manager.h
* �������� : 2022 - 07 - 11
* ��    �� : rzyang
* �������� : ���ù�����������ӱ����ļ����ƶ˻�ȡ���ã���ʱ���ƶ�ͬ�������ļ�
* ******************************************************************************/
#pragma once

#include <string>

#include "err_code.h"

class ConfigManager {
	/**
	 * ��������: ����������
	 *
	 * ���������config
	 * ���������config_string		Json�ַ���
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE parse_config(Config& config, const std::string& config_string);
};