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
#include "processor.hpp"

#include <string>
#include <map>

class QueueManager {
public:
	QueueManager() = default;

	~QueueManager() {
		destroy();
	}

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
	ERR_CODE get(std::shared_ptr<Queue>& queue, const std::string& queue_name);

	/**
	 * ��������: ������������������processor
	 *
	 * ���������
	 * ���������prev_processor		ǰһ��processor
	 *           next_processor     ��һ��processor
	 *           queue_name         Ҫ�����Ķ�������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE connect(std::shared_ptr<Processor>& prev_processor, std::shared_ptr<Processor>& next_processor, const std::string& queue_name);

private:
	std::map<std::string, std::shared_ptr<Queue> > m_queue_map;
};