/*******************************************************************************
* 文 件 名 : solution.h
* 创建日期 : 2022 - 07 - 13
* 作    者 : rzyang
* 功能描述 : 解决方案
* ******************************************************************************/
#pragma once

#include "manager/model_manager.h"
#include "manager/process_manager.h"
#include "manager/queue_manager.h"

class Solution {
public:
	/**
	 * 功能描述: 初始化
	 *
	 * 输出参数：
	 * 输入参数：config		配置
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE init(const Config& config);

	/**
	 * 功能描述: 启动
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE start();

	/**
	 * 功能描述: 停止
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE stop();

	/**
	 * 功能描述: 释放
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE release();

protected:
	ProcessManager	m_process_manager;
	QueueManager	m_queue_manager;
};