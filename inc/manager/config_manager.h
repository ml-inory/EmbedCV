/*******************************************************************************
* 文 件 名 : config_manager.h
* 创建日期 : 2022 - 07 - 11
* 作    者 : rzyang
* 功能描述 : 配置管理器，负责从本地文件或云端获取配置，定时向云端同步配置文件
* ******************************************************************************/
#pragma once

#include <string>

#include "err_code.h"
#include "config.h"


class ConfigManager {
public:
	~ConfigManager() = default;

	/**
	 * 功能描述: 从本地获取配置
	 *
	 * 输出参数：config
	 * 输入参数：config_path		配置文件路径
	 * 返回参数：错误码，参考err_code.h
	 */
	static ERR_CODE get_config_from_local(Config& config, const std::string& config_path);

	/**
	 * 功能描述: 从云端获取配置
	 *
	 * 输出参数：config
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	// static ERR_CODE get_config_from_cloud(Config& config);

	/**
	 * 功能描述: 开启一个定时从云端获取配置的线程
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	// static ERR_CODE start_fetch_thread();

private:
	ConfigManager() = default;
};