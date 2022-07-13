/*******************************************************************************
* 文 件 名 : processor.hpp
* 创建日期 : 2022 - 07 - 13
* 作    者 : rzyang
* 功能描述 : 线程模板基类
* ******************************************************************************/
#pragma once

#include "config.h"
#include "err_code.h"

template <typename T>
class Processor {
public:
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
	 * 功能描述: 运行
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE run() {
		return static_cast<T*>(this)->run_impl();
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