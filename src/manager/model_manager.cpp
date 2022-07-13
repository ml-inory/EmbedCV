#include "model_manager.h"
#include "logger.h"

/**
* ��������: ����ģ��
*
* ���������
* ���������config		����
* ���ز����������룬�ο�err_code.h
*/
ERR_CODE ModelManager::create(const Config& config) {
	LOG(INFO) << "Create model";
	return SUCCESS;
}

/**
 * ��������: ����ģ��
 *
 * ���������
 * ���������
 * ���ز����������룬�ο�err_code.h
 */
ERR_CODE ModelManager::destroy() {
	LOG(INFO) << "Destroy model";
	return SUCCESS;
}

/**
 * ��������: ��ȡģ��
 *
 * ���������model			ģ��
 * ���������model_name		ģ������
 * ���ز����������룬�ο�err_code.h
 */
ERR_CODE ModelManager::get(Model& model, const std::string& model_name) {
	LOG(INFO) << "Get model: " << model_name;
	return SUCCESS;
}