#include "process_manager.h"
#include "object_factory.hpp"
#include "logger.h"

#include "rtsp_input_processor.hpp"
#include "tbd_processor.hpp"
#include "digital_fence_processor.hpp"
#include "rtsp_output_processor.hpp"

/**
* 功能描述: 创建线程
*
* 输出参数：
* 输入参数：config		配置
* 返回参数：错误码，参考err_code.h
*/
ERR_CODE ProcessManager::create(const Config& config) {
	// 创建模型
	ERR_CODE ret = m_model_manager.create(config);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Create model failed!";
		return ret;
	}

	// 检查配置
	if (!config.isMember("input")) {
		LOG(ERROR) << "Config must contain \"input\"";
		return FAIL;
	}

	if (!config.isMember("cv")) {
		LOG(ERROR) << "Config must contain \"cv\"";
		return FAIL;
	}

	if (!config.isMember("bussiness")) {
		LOG(ERROR) << "Config must contain \"bussiness\"";
		return FAIL;
	}

	if (!config.isMember("display")) {
		LOG(ERROR) << "Config must contain \"display\"";
		return FAIL;
	}
 
	// 创建线程
	const std::string appendix("Processor");

	std::string input_type = config["input"]["type"].asString();
	if (input_type == "RTSP")	input_type += "Input" + appendix;
	std::shared_ptr<Processor> input_processor = ObjectFactory::create<Processor>(input_type);

	std::string cv_type = config["cv"]["type"].asString() + appendix;
	std::shared_ptr<Processor> cv_processor = ObjectFactory::create<Processor>(cv_type);

	std::string bus_type = config["bussiness"]["type"].asString() + appendix;
	std::shared_ptr<Processor> digit_fence_processor = ObjectFactory::create<Processor>(bus_type);

	std::string display_type = config["display"]["type"].asString();
	if (display_type == "RTSP")	display_type += "Output" + appendix;
	std::shared_ptr<Processor> display_processor = ObjectFactory::create<Processor>(display_type);

	// 初始化线程
	ret = input_processor->init(config, &m_model_manager);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Init rtsp_input_processor failed!";
		return ret;
	}

	ret = cv_processor->init(config, &m_model_manager);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Init tbd_processor failed!";
		return ret;
	}

	ret = digit_fence_processor->init(config, &m_model_manager);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Init digit_fence_processor failed!";
		return ret;
	}

	ret = display_processor->init(config, &m_model_manager);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Init display_processor failed!";
		return ret;
	}

	// 用队列连接线程
	std::string queue0("QUEUE0");
	std::string queue1("QUEUE1");
	std::string queue2("QUEUE2");
	ret = m_queue_manager.connect(input_processor, cv_processor, queue0);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Connect input_processor and cv_processor failed!";
		return ret;
	}

	ret = m_queue_manager.connect(cv_processor, digit_fence_processor, queue1);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Connect cv_processor and digit_fence_processor failed!";
		return ret;
	}

	ret = m_queue_manager.connect(digit_fence_processor, display_processor, queue2);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Connect digit_fence_processor and display_processor failed!";
		return ret;
	}

	m_processors.push_back(input_processor);
	m_processors.push_back(cv_processor);
	m_processors.push_back(digit_fence_processor);
	m_processors.push_back(display_processor);

	return SUCCESS;
}

/**
 * 功能描述: 启动线程
 *
 * 输出参数：
 * 输入参数：
 * 返回参数：错误码，参考err_code.h
 */
ERR_CODE ProcessManager::start() {
	LOG(INFO) << "Start processors";
	for (auto& p : m_processors) {
		ERR_CODE ret = p->start();
		if (ret != SUCCESS) {
			LOG(ERROR) << "Start process failed!";
			return ret;
		}
	}

	return SUCCESS;
}

/**
 * 功能描述: 停止线程
 *
 * 输出参数：
 * 输入参数：
 * 返回参数：错误码，参考err_code.h
 */
ERR_CODE ProcessManager::stop() {
	LOG(INFO) << "Stop processors";
	for (auto& p : m_processors) {
		ERR_CODE ret = p->stop();
		if (ret != SUCCESS) {
			LOG(ERROR) << "Stop process failed!";
			return ret;
		}
	}

	return SUCCESS;
}

/**
 * 功能描述: 销毁线程
 *
 * 输出参数：
 * 输入参数：
 * 返回参数：错误码，参考err_code.h
 */
ERR_CODE ProcessManager::destroy() {
	LOG(INFO) << "Destroy processors";
	for (auto it = m_processors.begin(); it != m_processors.end(); ) {
		ERR_CODE ret = (*it)->release();
		if (ret != SUCCESS) {
			LOG(ERROR) << "Destroy processor failed!";
			return ret;
		}

		it = m_processors.erase(it);
	}
	return SUCCESS;
}