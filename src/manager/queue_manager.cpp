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
	if (m_queue_map.find(queue_name) != m_queue_map.end()) {
		LOG(ERROR) << queue_name << " already created!";
		return FAIL;
	}

	std::shared_ptr<Queue> q(new Queue);
	m_queue_map.insert({ queue_name, q });

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
	m_queue_map.clear();

	return SUCCESS;
}

/**
 * 功能描述: 获取队列
 *
 * 输出参数：queue			队列
 * 输入参数：queue_name		队列名称
 * 返回参数：错误码，参考err_code.h
 */
ERR_CODE QueueManager::get(std::shared_ptr<Queue>& queue, const std::string& queue_name) {
	LOG(INFO) << "Get queue: " << queue_name;
	auto it = m_queue_map.find(queue_name);
	if (it == m_queue_map.end()) {
		LOG(ERROR) << queue_name << " is not created!";
		return FAIL;
	}

	queue = it->second;
	return SUCCESS;
}

/**
* 功能描述: 创建队列以连接两个processor
*
* 输出参数：
* 输入参数：prev_processor		前一个processor
*           next_processor     后一个processor
*           queue_name         要创建的队列名称
* 返回参数：错误码，参考err_code.h
*/
ERR_CODE QueueManager::connect(std::shared_ptr<Processor>& prev_processor, std::shared_ptr<Processor>& next_processor, const std::string& queue_name) {
	ERR_CODE ret = create(queue_name);
	if (ret != SUCCESS) {
		return ret;
	}

	std::shared_ptr<Queue> q;
	ret = get(q, queue_name);
	if (ret != SUCCESS) {
		return ret;
	}

	ret = prev_processor->set_output_queue(q);
	if (ret != SUCCESS) {
		return ret;
	}

	ret = next_processor->set_input_queue(q);
	if (ret != SUCCESS) {
		return ret;
	}

	return SUCCESS;
}