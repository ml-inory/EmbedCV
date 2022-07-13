#include "config_manager.h"
#include "logger.h"

#include <fstream>

using namespace std;

/**
* 功能描述: 解析出配置
*
* 输出参数：config
* 输入参数：config_string		Json字符串
* 返回参数：错误码，参考err_code.h
*/
ERR_CODE parse_config(Config& config, const std::string& config_string) {
	// TODO
	return SUCCESS;
}

/**
* 功能描述: 从本地获取配置
*
* 输出参数：config
* 输入参数：config_path		配置文件路径
* 返回参数：错误码，参考err_code.h
*/
ERR_CODE ConfigManager::get_config_from_local(Config& config, const std::string& config_path) {
	// 打开配置文件
	ifstream ifs(config_path);
	if (!ifs.is_open()) {
		LOG(ERROR) << "Open config " << config_path << " failed!";
		return FAIL;
	}

	// 读取文件内容
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));

	// 解析内容
	return parse_config(config, content);
}