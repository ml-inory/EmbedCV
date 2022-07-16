/*******************************************************************************
* 文 件 名 : queue_manager.h
* 创建日期 : 2022 - 07 - 11
* 作    者 : rzyang
* 功能描述 : 队列管理器，负责给线程产生队列，设置不同线程的输入和输出队列，
* 管理队列的生命周期
* ******************************************************************************/
#pragma once

#include "err_code.h"
#include "whale_any.h"
#include "mpmc_queue.h"
#include "processor.hpp"

#include <string>
#include <map>

class QueueManager {
public:
	QueueManager() = default;

	~QueueManager() {
		destroy();
	}

	/**
	 * 功能描述: 创建队列
	 *
	 * 输出参数：
	 * 输入参数：queue_name		队列名称
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE create(const std::string& queue_name);

	/**
	 * 功能描述: 销毁队列
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE destroy();

	/**
	 * 功能描述: 获取队列
	 *
	 * 输出参数：queue			队列
	 * 输入参数：queue_name		队列名称
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE get(std::shared_ptr<Queue>& queue, const std::string& queue_name);

	/**
	 * 功能描述: 创建队列以连接两个processor
	 *
	 * 输出参数：
	 * 输入参数：prev_processor		前一个processor
	 *           next_processor     后一个processor
	 *           queue_name         要创建的队列名称
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE connect(std::shared_ptr<Processor>& prev_processor, std::shared_ptr<Processor>& next_processor, const std::string& queue_name);

private:
	std::map<std::string, std::shared_ptr<Queue> > m_queue_map;
};