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

	static ERR_CODE get_config_from_local(Config& config, const std::string& config_path);

	static ERR_CODE get_config_from_cloud(Config& config);

	static ERR_CODE start_fetch_thread();

private:
	ConfigManager() = default;

	/**
	 * 功能描述: 解析出配置
	 *
	 * 输出参数：config
	 * 输入参数：config_string		Json字符串
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE parse_config(Config& config, const std::string& config_string);
};