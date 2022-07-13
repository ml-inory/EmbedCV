/*******************************************************************************
* 文 件 名 : solution_manager.h
* 创建日期 : 2022 - 07 - 11
* 作    者 : rzyang
* 功能描述 : 解决方案管理器，负责根据配置产生不同的解决方案，管理解决方案的生命
* 周期
* ******************************************************************************/
#pragma once

#include "config.h"
#include "err_code.h"
#include "solution.h"

#include <memory>
#include <vector>

class SolutionManager {
public:
	~SolutionManager() = default;

	/**
	 * 功能描述: 创建解决方案
	 *
	 * 输出参数：
	 * 输入参数：config		配置
	 * 返回参数：错误码，参考err_code.h
	 */
	static ERR_CODE create(const Config& config);

	/**
	 * 功能描述: 启动解决方案
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	static ERR_CODE start();

	/**
	 * 功能描述: 停止解决方案
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	static ERR_CODE stop();

	/**
	 * 功能描述: 销毁解决方案
	 *
	 * 输出参数：
	 * 输入参数：
	 * 返回参数：错误码，参考err_code.h
	 */
	static ERR_CODE destroy();

private:
	SolutionManager() = default;

	static std::vector<std::shared_ptr<Solution> > g_solutions;
};