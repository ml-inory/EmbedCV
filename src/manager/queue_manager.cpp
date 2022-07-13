#include "queue_manager.h"
#include "logger.h"


/**
* ��������: ��������
*
* ���������
* ���������queue_name		��������
* ���ز����������룬�ο�err_code.h
*/
ERR_CODE QueueManager::create(const std::string& queue_name) {
	LOG(INFO) << "Create queue: " << queue_name;
	return SUCCESS;
}

/**
 * ��������: ���ٶ���
 *
 * ���������
 * ���������
 * ���ز����������룬�ο�err_code.h
 */
ERR_CODE QueueManager::destroy() {
	LOG(INFO) << "Destroy queues";
	return SUCCESS;
}

/**
 * ��������: ��ȡ����
 *
 * ���������queue			����
 * ���������queue_name		��������
 * ���ز����������룬�ο�err_code.h
 */
ERR_CODE get(QueueManager::QueueType& queue, const std::string& queue_name) {
	LOG(INFO) << "Get queue: " << queue_name;
	return SUCCESS;
}