/*******************************************************************************
* 文 件 名 : processor.hpp
* 创建日期 : 2022 - 07 - 13
* 作    者 : rzyang
* 功能描述 : 线程模板基类，使用了CRTP技术减少虚函数调用损耗s
* ******************************************************************************/
#pragma once

#include "config.h"
#include "err_code.h"
#include "manager/model_manager.h"
#include "mpmc_queue.h"
#include "logger.h"
#include "processor/processor_factory.hpp"

#include <thread>
#include <atomic>
#include <chrono>
#include <memory>


class Processor {
public:
	Processor(): 
		m_input_queue(nullptr),
		m_output_queue(nullptr)
	{

	};

	/**
	 * 功能描述: 初始化
	 *
	 * 输出参数：
	 * 输入参数：config				配置
	 *			 model_manager		可为nullptr
	 * 返回参数：错误码，参考err_code.h
	 */
	virtual ERR_CODE init(const Config& config, ModelManager* model_manager = nullptr) = 0;

	/**
	 * 功能描述: 启动
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	virtual ERR_CODE start() = 0;

	/**
	 * 功能描述: 停止
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	virtual ERR_CODE stop() = 0;

	/**
	 * 功能描述: 释放
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	virtual ERR_CODE release() = 0;

	/**
	 * 功能描述: 设置输入队列
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	virtual ERR_CODE set_input_queue(std::shared_ptr<Queue>& q) {
		if (m_input_queue != nullptr) {
			LOG(ERROR) << "input_queue already set";
			return FAIL;
		}

		m_input_queue = q;
		return SUCCESS;
	}

	/**
	 * 功能描述: 设置输出队列
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	virtual ERR_CODE set_output_queue(std::shared_ptr<Queue>& q) {
		if (m_output_queue != nullptr) {
			LOG(ERROR) << "output_queue already set";
			return FAIL;
		}

		m_output_queue = q;
		return SUCCESS;
	}

protected:
	ModelManager* m_model_manager;
	std::shared_ptr<Queue> m_input_queue;
	std::shared_ptr<Queue> m_output_queue;
};

template <typename T>
class ProcessorImpl : public Processor {
public:
	explicit ProcessorImpl() :
		Processor(),
		m_running(false)
	{

	};

	/**
	 * 功能描述: 初始化
	 *
	 * 输出参数：
	 * 输入参数：config		配置
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE init(const Config& config, ModelManager* model_manager = nullptr) {
		m_model_manager = model_manager;
		return static_cast<T*>(this)->init_impl(config);
	}

	/**
	 * 功能描述: 启动
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE start() {
		if (m_running) {
			LOG(WARNING) << "thread already running";
			return FAIL;
		}

		LOG(INFO) << "Start processor";
		m_running = true;
		std::thread t([&] {
			this->run();
		});
		t.detach();
		return SUCCESS;
	}

	/**
	 * 功能描述: 停止
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE stop() {
		LOG(INFO) << "Stop processor";
		m_running = false;
		return SUCCESS;
	}

	/**
	 * 功能描述: 停止
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	void run() {
		while (m_running) {
			static_cast<T*>(this)->run_impl();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}

	/**
	 * 功能描述: 释放
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE release() {
		return static_cast<T*>(this)->release_impl();
	}

protected:
	std::atomic_bool m_running;
};