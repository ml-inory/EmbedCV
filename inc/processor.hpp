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
#include "mpmc_queue.h"
#include "logger.h"
#include "processor/processor_factory.hpp"

#include <thread>
#include <atomic>
#include <chrono>
#include <memory>


class Processor {
public:
	Processor(): 
		m_input_queue(nullptr),
		m_output_queue(nullptr)
	{

	};

	/**
	 * ��������: ��ʼ��
	 *
	 * ���������
	 * ���������config				����
	 *			 model_manager		��Ϊnullptr
	 * ���ز����������룬�ο�err_code.h
	 */
	virtual ERR_CODE init(const Config& config, ModelManager* model_manager = nullptr) = 0;

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

	/**
	 * ��������: �����������
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	virtual ERR_CODE set_input_queue(std::shared_ptr<Queue>& q) {
		if (m_input_queue != nullptr) {
			LOG(ERROR) << "input_queue already set";
			return FAIL;
		}

		m_input_queue = q;
		return SUCCESS;
	}

	/**
	 * ��������: �����������
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	virtual ERR_CODE set_output_queue(std::shared_ptr<Queue>& q) {
		if (m_output_queue != nullptr) {
			LOG(ERROR) << "output_queue already set";
			return FAIL;
		}

		m_output_queue = q;
		return SUCCESS;
	}

protected:
	ModelManager* m_model_manager;
	std::shared_ptr<Queue> m_input_queue;
	std::shared_ptr<Queue> m_output_queue;
};

template <typename T>
class ProcessorImpl : public Processor {
public:
	explicit ProcessorImpl() :
		Processor(),
		m_running(false)
	{

	};

	/**
	 * ��������: ��ʼ��
	 *
	 * ���������
	 * ���������config		����
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE init(const Config& config, ModelManager* model_manager = nullptr) {
		m_model_manager = model_manager;
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
		if (m_running) {
			LOG(WARNING) << "thread already running";
			return FAIL;
		}

		LOG(INFO) << "Start processor";
		m_running = true;
		std::thread t([&] {
			this->run();
		});
		t.detach();
		return SUCCESS;
	}

	/**
	 * ��������: ֹͣ
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE stop() {
		LOG(INFO) << "Stop processor";
		m_running = false;
		return SUCCESS;
	}

	/**
	 * ��������: ֹͣ
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	void run() {
		while (m_running) {
			static_cast<T*>(this)->run_impl();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
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

protected:
	std::atomic_bool m_running;
};