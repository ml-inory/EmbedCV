/*******************************************************************************
* �� �� �� : rtsp_input_processor.hpp
* �������� : 2022 - 07 - 13
* ��    �� : rzyang
* �������� : RTSP���
* ******************************************************************************/
#pragma once

#include "processor.hpp"

class RTSPOutputProcessor final : public ProcessorImpl<RTSPOutputProcessor> {
public:
	/**
	 * ��������: ��ʼ��
	 *
	 * ���������
	 * ���������config		����
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE init_impl(const Config& config) {
		LOG(INFO) << "Init RTSPOutputProcessor";
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
		LOG(INFO) << "Start RTSPOutputProcessor";
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
		LOG(INFO) << "Stop RTSPOutputProcessor";
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
		LOG(INFO) << "Release RTSPOutputProcessor";
		return SUCCESS;
	}
};