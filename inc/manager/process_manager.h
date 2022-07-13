/*******************************************************************************
* 文 件 名 : process_manager.h
* 创建日期 : 2022 - 07 - 11
* 作    者 : rzyang
* 功能描述 : 线程管理器，负责根据配置产生不同类型的线程，管理线程的生命周期，为
* 解决方案所用
* ******************************************************************************/
#pragma once

#include "model_manager.h"
#include "processor.hpp"
#include "err_code.h"

#include <vector>
#include <memory>

class ProcessManager {
public:
	/**
	 * 功能描述: 创建线程
	 *
	 * 输出参数：
	 * 输入参数：config		配置
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE create(const Config& config);

	/**
	 * 功能描述: 启动线程
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE start();

	/**
	 * 功能描述: 停止线程
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE stop();

	/**
	 * 功能描述: 销毁线程
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE destroy();

private:
	ModelManager m_model_manager;
	std::vector<std::shared_ptr<Processor> > m_processors;
};