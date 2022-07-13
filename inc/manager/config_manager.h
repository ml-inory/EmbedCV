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

	/**
	 * ��������: �ӱ��ػ�ȡ����
	 *
	 * ���������config
	 * ���������config_path		�����ļ�·��
	 * ���ز����������룬�ο�err_code.h
	 */
	static ERR_CODE get_config_from_local(Config& config, const std::string& config_path);

	/**
	 * ��������: ���ƶ˻�ȡ����
	 *
	 * ���������config
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	// static ERR_CODE get_config_from_cloud(Config& config);

	/**
	 * ��������: ����һ����ʱ���ƶ˻�ȡ���õ��߳�
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	// static ERR_CODE start_fetch_thread();

private:
	ConfigManager() = default;
};