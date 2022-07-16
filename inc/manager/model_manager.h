/*******************************************************************************
* �� �� �� : model_manager.h
* �������� : 2022 - 07 - 11
* ��    �� : rzyang
* �������� : ģ�͹�����������������ò�����ͬ��ģ�ͣ�������ģ�͵��������ڣ�Ϊ
* �����������
* ******************************************************************************/
#pragma once

#include "err_code.h"
#include "model.h"
#include "config.h"

#include <string>
#include <map>
#include <memory>

class ModelManager {
public:
	ModelManager() = default;
	~ModelManager() {
		destroy();
	}

	/**
	 * ��������: ����ģ��
	 *
	 * ���������
	 * ���������config		����
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE create(const Config& config);

	/**
	 * ��������: ����ģ��
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE destroy();

	/**
	 * ��������: ��ȡģ��
	 *
	 * ���������model			ģ��
	 * ���������model_name		ģ������
	 * ���ز����������룬�ο�err_code.h
	 */
	ERR_CODE get(Model& model, const std::string& model_name);

private:
	std::map<std::string, std::shared_ptr<Model> > m_model_map;
};