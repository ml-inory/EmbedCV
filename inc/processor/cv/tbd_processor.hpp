/*******************************************************************************
* �� �� �� : rtsp_input_processor.hpp
* �������� : 2022 - 07 - 13
* ��    �� : rzyang
* �������� : Tracking by Detection
* ******************************************************************************/
#pragma once

#include "processor.hpp"

class TBDProcessor final : public ProcessorImpl<TBDProcessor> {
public:
	/**
	 * ��������: ��ʼ��
	 *
	 * ���������
	 * ���������config		����
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE init_impl(const Config& config) {
		LOG(INFO) << "Init TBDProcessor";
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
		LOG(INFO) << "Start TBDProcessor";
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
		LOG(INFO) << "Stop TBDProcessor";
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
		LOG(INFO) << "Release TBDProcessor";
		return SUCCESS;
	}
};