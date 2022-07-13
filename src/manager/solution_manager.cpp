#include "solution_manager.h"
#include "logger.h"

std::vector<std::shared_ptr<Solution> > SolutionManager::g_solutions;

ERR_CODE SolutionManager::create(const Config& config) {
	LOG(INFO) << "Create solutions";
	std::shared_ptr<Solution> solution = std::make_shared<Solution>();
	// 初始化解决方案
	ERR_CODE ret = solution->init(config);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Init solution failed!";
		return ret;
	}

	g_solutions.push_back(solution);
	return SUCCESS;
}

ERR_CODE SolutionManager::start() {
	LOG(INFO) << "Start solutions";
	for (auto& solution : g_solutions) {
		ERR_CODE ret = solution->start();
		if (ret != SUCCESS) {
			LOG(ERROR) << "Start solution failed!";
			return ret;
		}
	}
	return SUCCESS;
}

ERR_CODE SolutionManager::stop() {
	LOG(INFO) << "Stop solutions";
	for (auto& solution : g_solutions) {
		ERR_CODE ret = solution->stop();
		if (ret != SUCCESS) {
			LOG(ERROR) << "Stop solution failed!";
			return ret;
		}
	}
	return SUCCESS;
}

ERR_CODE SolutionManager::destroy() {
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