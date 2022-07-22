/*******************************************************************************
* �� �� �� : rtsp_input_processor.hpp
* �������� : 2022 - 07 - 13
* ��    �� : rzyang
* �������� : ����դ��
* ******************************************************************************/
#pragma once

#include "processor.hpp"

class DigitalFenceProcessor final : public ProcessorImpl<DigitalFenceProcessor> {
public:
	/**
	 * ��������: ��ʼ��
	 *
	 * ���������
	 * ���������config		����
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE init_impl(const Config& config) {
		LOG(INFO) << "Init DigitalFenceProcessor";
		return SUCCESS;
	}

	/**
	 * ��������: ����
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	void run_impl() {
		LOG(INFO) << "Run DigitalFenceProcessor";
	}

	/**
	 * ��������: �ͷ�
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE release_impl() {
		LOG(INFO) << "Release DigitalFenceProcessor";
		return SUCCESS;
	}
};

REGISTER_PROCESSOR(DigitalFenceProcessor);