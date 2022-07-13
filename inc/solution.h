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
public:
	/**
	 * ��������: ��ʼ��
	 *
	 * ���������
	 * ���������config		����
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE init(const Config& config);

	/**
	 * ��������: ����
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE start();

	/**
	 * ��������: ֹͣ
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE stop();

	/**
	 * ��������: �ͷ�
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE release();

protected:
	ProcessManager	m_process_manager;
	QueueManager	m_queue_manager;
};