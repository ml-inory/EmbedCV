#include "model_manager.h"
#include "logger.h"

/**
* 功能描述: 创建模型
*
* 输出参数：
* 输入参数：config		配置
* 返回参数：错误码，参考err_code.h
*/
ERR_CODE ModelManager::create(const Config& config) {
	LOG(INFO) << "Create model";
	return SUCCESS;
}

/**
 * 功能描述: 销毁模型
 *
 * 输出参数：
 * 输入参数：
 * 返回参数：错误码，参考err_code.h
 */
ERR_CODE ModelManager::destroy() {
	LOG(INFO) << "Destroy model";
	return SUCCESS;
}

/**
 * 功能描述: 获取模型
 *
 * 输出参数：model			模型
 * 输入参数：model_name		模型名称
 * 返回参数：错误码，参考err_code.h
 */
ERR_CODE ModelManager::get(Model& model, const std::string& model_name) {
	LOG(INFO) << "Get model: " << model_name;
	return SUCCESS;
}