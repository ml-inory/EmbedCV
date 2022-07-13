/*******************************************************************************
* �� �� �� : queue_manager.h
* �������� : 2022 - 07 - 11
* ��    �� : rzyang
* �������� : ���й�������������̲߳������У����ò�ͬ�̵߳������������У�
* ������е���������
* ******************************************************************************/
#pragma once

#include "err_code.h"
#include "whale_any.h"
#include "mpmc_queue.h"

#include <string>
#include <map>

class QueueManager {
public:
	QueueManager() = default;
	~QueueManager() = default;

	// ��������
	typedef moodycamel::ConcurrentQueue<WhaleAny>   QueueType;

	/**
	 * ��������: ��������
	 *
	 * ���������
	 * ���������queue_name		��������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE create(const std::string& queue_name);

	/**
	 * ��������: ���ٶ���
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE destroy();

	/**
	 * ��������: ��ȡ����
	 *
	 * ���������queue			����
	 * ���������queue_name		��������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE get(QueueType& queue, const std::string& queue_name);

private:
	std::map<std::string, std::shared_ptr<QueueType> > m_queue_map;
};