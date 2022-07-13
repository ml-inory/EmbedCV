#include "solution_manager.h"
#include "logger.h"

std::vector<std::shared_ptr<Solution> > SolutionManager::g_solutions;

ERR_CODE SolutionManager::create(const Config& config) {
	LOG(INFO) << "Create solutions";
	return SUCCESS;
}

ERR_CODE SolutionManager::start() {
	LOG(INFO) << "Start solutions";
	return SUCCESS;
}

ERR_CODE SolutionManager::stop() {
	LOG(INFO) << "Stop solutions";
	return SUCCESS;
}

ERR_CODE SolutionManager::destroy() {
	LOG(INFO) << "Destroy solutions";
	return SUCSESS;
}