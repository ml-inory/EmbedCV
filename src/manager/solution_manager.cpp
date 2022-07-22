#include "solution_manager.h"
#include "logger.h"

std::vector<std::shared_ptr<Solution> > SolutionManager::g_solutions;
bool SolutionManager::g_has_start = false;

ERR_CODE SolutionManager::create(const Config& config) {
	LOG(INFO) << "Create solutions";

	// 解析json
	if (!config.isMember("solutions")) {
		LOG(ERROR) << "Config must contain \"solutions\"";
		return FAIL;
	}

	Config solution_configs = config["solutions"];
	for (Json::Value::ArrayIndex i = 0; i < solution_configs.size(); ++i) {
		// 检查配置类型
		if (!solution_configs[i].isObject()) {
			LOG(ERROR) << "solutions[" << i << "] must be Object";
			return FAIL;
		}

		std::shared_ptr<Solution> solution = std::make_shared<Solution>();
		// 初始化解决方案
		ERR_CODE ret = solution->init(solution_configs[i]);
		if (ret != SUCCESS) {
			LOG(ERROR) << "Init solution failed!";
			return ret;
		}

		g_solutions.push_back(solution);
	}
	
	return SUCCESS;
}

ERR_CODE SolutionManager::start() {
	if (g_has_start) {
		return SUCCESS;
	}

	LOG(INFO) << "Start solutions";
	for (auto& solution : g_solutions) {
		ERR_CODE ret = solution->start();
		if (ret != SUCCESS) {
			LOG(ERROR) << "Start solution failed!";
			return ret;
		}
	}

	g_has_start = true;
	return SUCCESS;
}

ERR_CODE SolutionManager::stop() {
	if (!g_has_start) {
		return SUCCESS;
	}

	LOG(INFO) << "Stop solutions";
	for (auto& solution : g_solutions) {
		ERR_CODE ret = solution->stop();
		if (ret != SUCCESS) {
			LOG(ERROR) << "Stop solution failed!";
			return ret;
		}
	}

	g_has_start = false;
	return SUCCESS;
}

ERR_CODE SolutionManager::destroy() {
	if (g_has_start) {
		ERR_CODE ret = stop();
		if (ret != SUCCESS) {
			return ret;
		}
	}

	LOG(INFO) << "Destroy solutions";
	for (auto it = g_solutions.begin(); it != g_solutions.end(); ) {
		ERR_CODE ret = (*it)->release();
		if (ret != SUCCESS) {
			LOG(ERROR) << "Destroy solution failed!";
			return ret;
		}

		it = g_solutions.erase(it);
	}

	return SUCCESS;
}