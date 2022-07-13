/*******************************************************************************
* �� �� �� : processor.hpp
* �������� : 2022 - 07 - 13
* ��    �� : rzyang
* �������� : �߳�ģ����࣬ʹ����CRTP���������麯���������s
* ******************************************************************************/
#pragma once

#include "config.h"
#include "err_code.h"
#include "manager/model_manager.h"

class Processor {
public:
	explicit Processor(ModelManager* model_manager): 
		m_model_manager(model_manager)
	{

	};

	/**
	 * ��������: ��ʼ��
	 *
	 * ���������
	 * ���������config		����
	 * ���ز����������룬�ο�err_code.h
	 */
	virtual ERR_CODE init(const Config& config) = 0;

	/**
	 * ��������: ����
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	virtual ERR_CODE start() = 0;

	/**
	 * ��������: ֹͣ
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	virtual ERR_CODE stop() = 0;

	/**
	 * ��������: �ͷ�
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	virtual ERR_CODE release() = 0;

protected:
	ModelManager* m_model_manager;
};

template <typename T>
class ProcessorImpl : public Processor {
public:
	explicit ProcessorImpl(ModelManager* model_manager) :
		Processor(model_manager)
	{

	};

	/**
	 * ��������: ��ʼ��
	 *
	 * ���������
	 * ���������config		����
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE init(const Config& config) {
		return static_cast<T*>(this)->init_impl(config);
	}

	/**
	 * ��������: ����
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE start() {
		return static_cast<T*>(this)->start_impl();
	}

	/**
	 * ��������: ֹͣ
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE stop() {
		return static_cast<T*>(this)->stop_impl();
	}

	/**
	 * ��������: �ͷ�
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE release() {
		return static_cast<T*>(this)->release_impl();
	}
};