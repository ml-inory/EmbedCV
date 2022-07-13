#include <stdio.h>

#include "logger.h"
#include "config_manager.h"
#include "solution_manager.h"

int main(int argc, char** argv) {
	init_logger(argv);
	LOG(INFO) << "Hello, World";

	// ��ȡ����
	Config config;
	ERR_CODE ret = ConfigManager::get_config_from_local(config, "config.json");
	if (ret != SUCCESS) {
		LOG(ERROR) << "get config from local failed!";
		return -1;
	}

	// �����������
	ret = SolutionManager::create(config);
	if (ret != SUCCESS) {
		LOG(ERROR) << "create solution failed!";
		return -1;
	}

	// �����������
	ret = SolutionManager::start();
	if (ret != SUCCESS) {
		LOG(ERROR) << "start solution failed!";
		return -1;
	}

	// ֹͣ�������
	ret = SolutionManager::stop();
	if (ret != SUCCESS) {
		LOG(ERROR) << "stop solution failed!";
		return -1;
	}

	// ���ٽ������
	ret = SolutionManager::destroy();
	if (ret != SUCCESS) {
		LOG(ERROR) << "destroy solution failed!";
		return -1;
	}
	return 0;
}