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

class Processor {
public:
	explicit Processor(ModelManager* model_manager): 
		m_model_manager(model_manager)
	{

	};

	/**
	 * 功能描述: 初始化
	 *
	 * 输出参数：
	 * 输入参数：config		配置
	 * 返回参数：错误码，参考err_code.h
	 */
	virtual ERR_CODE init(const Config& config) = 0;

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

protected:
	ModelManager* m_model_manager;
};

template <typename T>
class ProcessorImpl : public Processor {
public:
	explicit ProcessorImpl(ModelManager* model_manager) :
		Processor(model_manager)
	{

	};

	/**
	 * 功能描述: 初始化
	 *
	 * 输出参数：
	 * 输入参数：config		配置
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE init(const Config& config) {
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
		return static_cast<T*>(this)->start_impl();
	}

	/**
	 * 功能描述: 停止
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE stop() {
		return static_cast<T*>(this)->stop_impl();
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
};