/*******************************************************************************
* �� �� �� : process_manager.h
* �������� : 2022 - 07 - 11
* ��    �� : rzyang
* �������� : �̹߳�����������������ò�����ͬ���͵��̣߳������̵߳��������ڣ�Ϊ
* �����������
* ******************************************************************************/
#pragma once

#include "model_manager.h"
#include "processor.hpp"
#include "err_code.h"

#include <vector>
#include <memory>

class ProcessManager {
public:
	/**
	 * ��������: �����߳�
	 *
	 * ���������
	 * ���������config		����
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE create(const Config& config);

	/**
	 * ��������: �����߳�
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE start();

	/**
	 * ��������: ֹͣ�߳�
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE stop();

	/**
	 * ��������: �����߳�
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE destroy();

private:
	ModelManager m_model_manager;
	std::vector<std::shared_ptr<Processor> > m_processors;
};