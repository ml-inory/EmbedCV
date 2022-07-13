/*******************************************************************************
* �� �� �� : solution.h
* �������� : 2022 - 07 - 13
* ��    �� : rzyang
* �������� : �������
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