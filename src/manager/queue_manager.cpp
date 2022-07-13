#include "queue_manager.h"
#include "logger.h"


/**
* 功能描述: 创建队列
*
* 输出参数：
* 输入参数：queue_name		队列名称
* 返回参数：错误码，参考err_code.h
*/
ERR_CODE QueueManager::create(const std::string& queue_name) {
	LOG(INFO) << "Create queue: " << queue_name;
	return SUCCESS;
}

/**
 * 功能描述: 销毁队列
 *
 * 输出参数：
 * 输入参数：
 * 返回参数：错误码，参考err_code.h
 */
ERR_CODE QueueManager::destroy() {
	LOG(INFO) << "Destroy queues";
	return SUCCESS;
}

/**
 * 功能描述: 获取队列
 *
 * 输出参数：queue			队列
 * 输入参数：queue_name		队列名称
 * 返回参数：错误码，参考err_code.h
 */
ERR_CODE get(QueueManager::QueueType& queue, const std::string& queue_name) {
	LOG(INFO) << "Get queue: " << queue_name;
	return SUCCESS;
}