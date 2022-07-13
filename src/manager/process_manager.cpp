#include "process_manager.h"
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
	 
	// 创建线程
	std::shared_ptr<Processor> input_processor(new ProcessorImpl<RTSPInputProcessor>(&m_model_manager));
	std::shared_ptr<Processor> cv_processor(new ProcessorImpl<TBDProcessor>(&m_model_manager));
	std::shared_ptr<Processor> digit_fence_processor(new ProcessorImpl<DigitalFenceProcessor>(&m_model_manager));
	std::shared_ptr<Processor> display_processor(new ProcessorImpl<RTSPOutputProcessor>(&m_model_manager));

	// 初始化线程
	ret = input_processor->init(config);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Init rtsp_input_processor failed!";
		return ret;
	}

	ret = cv_processor->init(config);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Init tbd_processor failed!";
		return ret;
	}

	ret = digit_fence_processor->init(config);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Init digit_fence_processor failed!";
		return ret;
	}

	ret = display_processor->init(config);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Init display_processor failed!";
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