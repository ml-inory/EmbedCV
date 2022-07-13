/*******************************************************************************
* �� �� �� : processor.hpp
* �������� : 2022 - 07 - 13
* ��    �� : rzyang
* �������� : �߳�ģ�����
* ******************************************************************************/
#pragma once

#include "config.h"
#include "err_code.h"

template <typename T>
class Processor {
public:
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
	ERR_CODE run() {
		return static_cast<T*>(this)->run_impl();
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