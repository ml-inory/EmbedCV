/*******************************************************************************
* �� �� �� : solution_manager.h
* �������� : 2022 - 07 - 11
* ��    �� : rzyang
* �������� : �������������������������ò�����ͬ�Ľ������������������������
* ����
* ******************************************************************************/
#pragma once

#include "config.h"
#include "err_code.h"
#include "solution.h"

#include <memory>
#include <vector>

class SolutionManager {
public:
	~SolutionManager() = default;

	/**
	 * ��������: �����������
	 *
	 * ���������
	 * ���������config		����
	 * ���ز����������룬�ο�err_code.h
	 */
	static ERR_CODE create(const Config& config);

	/**
	 * ��������: �����������
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	static ERR_CODE start();

	/**
	 * ��������: ֹͣ�������
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	static ERR_CODE stop();

	/**
	 * ��������: ���ٽ������
	 *
	 * ���������
	 * ���������
	 * ���ز����������룬�ο�err_code.h
	 */
	static ERR_CODE destroy();

private:
	SolutionManager() = default;

	static std::vector<std::shared_ptr<Solution> > g_solutions;
};