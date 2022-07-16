/*******************************************************************************
* 文 件 名 : model_manager.h
* 创建日期 : 2022 - 07 - 11
* 作    者 : rzyang
* 功能描述 : 模型管理器，负责根据配置产生不同的模型，并管理模型的生命周期，为
* 解决方案所用
* ******************************************************************************/
#pragma once

#include "err_code.h"
#include "model.h"
#include "config.h"

#include <string>
#include <map>
#include <memory>

class ModelManager {
public:
	ModelManager() = default;
	~ModelManager() {
		destroy();
	}

	/**
	 * 功能描述: 创建模型
	 *
	 * 输出参数：
	 * 输入参数：config		配置
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE create(const Config& config);

	/**
	 * 功能描述: 销毁模型
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE destroy();

	/**
	 * 功能描述: 获取模型
	 *
	 * 输出参数：model			模型
	 * 输入参数：model_name		模型名称
	 * 返回参数：错误码，参考err_code.h
	 */
	ERR_CODE get(Model& model, const std::string& model_name);

private:
	std::map<std::string, std::shared_ptr<Model> > m_model_map;
};