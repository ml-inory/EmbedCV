/*******************************************************************************
* 文 件 名 : solution.h
* 创建日期 : 2022 - 07 - 13
* 作    者 : rzyang
* 功能描述 : 解决方案
* ******************************************************************************/
#pragma once

#include "manager/model_manager.h"
#include "manager/process_manager.h"
#include "manager/queue_manager.h"

class Solution {
protected:
	ModelManager	m_model_manager;
	ProcessManager	m_process_manager;
	QueueManager	m_queue_manager;
};