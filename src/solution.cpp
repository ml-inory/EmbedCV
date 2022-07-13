#include "solution.h"
#include "logger.h"


/**
* 功能描述: 初始化
*
* 输出参数：
* 输入参数：config		配置
* 返回参数：错误码，参考err_code.h
*/
ERR_CODE Solution::init(const Config& config) {
	// 创建线程
	ERR_CODE ret = m_process_manager.create(config);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Create process failed!";
		return ret;
	}

	// 创建队列
	ret = m_queue_manager.create("dummy_queue");
	if (ret != SUCCESS) {
		LOG(ERROR) << "Create queue failed!";
		return ret;
	}

	return SUCCESS;
}

/**
* 功能描述: 启动
*
* 输出参数：
* 输入参数：
* 返回参数：错误码，参考err_code.h
*/
ERR_CODE Solution::start() {
	LOG(INFO) << "Start solution";
	// 启动线程
	ERR_CODE ret = m_process_manager.start();
	if (ret != SUCCESS) {
		LOG(ERROR) << "Start process failed!";
		return ret;
	}
	
	return SUCCESS;
}

/**
* 功能描述: 停止
*
* 输出参数：
* 输入参数：
* 返回参数：错误码，参考err_code.h
*/
ERR_CODE Solution::stop() {
	LOG(INFO) << "Stop solution";
	// 停止线程
	ERR_CODE ret = m_process_manager.stop();
	if (ret != SUCCESS) {
		LOG(ERROR) << "Stop process failed!";
		return ret;
	}

	return SUCCESS;
}

/**
* 功能描述: 释放
*
* 输出参数：
* 输入参数：
* 返回参数：错误码，参考err_code.h
*/
ERR_CODE Solution::release() {
	LOG(INFO) << "Release solution";
	// 销毁线程
	ERR_CODE ret = m_process_manager.destroy();
	if (ret != SUCCESS) {
		LOG(ERROR) << "Destroy process failed!";
		return ret;
	}

	return SUCCESS;
}