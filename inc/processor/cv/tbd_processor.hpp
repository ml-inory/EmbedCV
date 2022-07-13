/*******************************************************************************
* 文 件 名 : rtsp_input_processor.hpp
* 创建日期 : 2022 - 07 - 13
* 作    者 : rzyang
* 功能描述 : Tracking by Detection
* ******************************************************************************/
#pragma once

#include "processor.hpp"

class TBDProcessor final : public ProcessorImpl<TBDProcessor> {
public:
	/**
	 * 功能描述: 初始化
	 *
	 * 输出参数：
	 * 输入参数：config		配置
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE init_impl(const Config& config) {
		LOG(INFO) << "Init TBDProcessor";
		return SUCCESS;
	}

	/**
	 * 功能描述: 启动
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE start_impl() {
		LOG(INFO) << "Start TBDProcessor";
		return SUCCESS;
	}

	/**
	 * 功能描述: 停止
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE stop_impl() {
		LOG(INFO) << "Stop TBDProcessor";
		return SUCCESS;
	}

	/**
	 * 功能描述: 释放
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE release_impl() {
		LOG(INFO) << "Release TBDProcessor";
		return SUCCESS;
	}
};