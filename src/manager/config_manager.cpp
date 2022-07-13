#include "config_manager.h"
#include "logger.h"

#include <fstream>

using namespace std;

/**
* ��������: ����������
*
* ���������config
* ���������config_string		Json�ַ���
* ���ز����������룬�ο�err_code.h
*/
ERR_CODE parse_config(Config& config, const std::string& config_string) {
	// TODO
	return SUCCESS;
}

/**
* ��������: �ӱ��ػ�ȡ����
*
* ���������config
* ���������config_path		�����ļ�·��
* ���ز����������룬�ο�err_code.h
*/
ERR_CODE ConfigManager::get_config_from_local(Config& config, const std::string& config_path) {
	// �������ļ�
	ifstream ifs(config_path);
	if (!ifs.is_open()) {
		LOG(ERROR) << "Open config " << config_path << " failed!";
		return FAIL;
	}

	// ��ȡ�ļ�����
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));

	// ��������
	return parse_config(config, content);
}