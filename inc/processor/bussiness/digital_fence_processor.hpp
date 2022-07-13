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
	ERR_CODE start_impl() {
		LOG(INFO) << "Start DigitalFenceProcessor";
		return SUCCESS;
	}

	/**
	 * ��������: ֹͣ
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE stop_impl() {
		LOG(INFO) << "Stop DigitalFenceProcessor";
		return SUCCESS;
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