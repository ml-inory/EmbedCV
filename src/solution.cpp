#include "solution.h"
#include "logger.h"


/**
* ��������: ��ʼ��
*
* ���������
* ���������config		����
* ���ز����������룬�ο�err_code.h
*/
ERR_CODE Solution::init(const Config& config) {
	// �����߳�
	ERR_CODE ret = m_process_manager.create(config);
	if (ret != SUCCESS) {
		LOG(ERROR) << "Create process failed!";
		return ret;
	}

	// ��������
	ret = m_queue_manager.create("dummy_queue");
	if (ret != SUCCESS) {
		LOG(ERROR) << "Create queue failed!";
		return ret;
	}

	return SUCCESS;
}

/**
* ��������: ����
*
* ���������
* ���������
* ���ز����������룬�ο�err_code.h
*/
ERR_CODE Solution::start() {
	LOG(INFO) << "Start solution";
	// �����߳�
	ERR_CODE ret = m_process_manager.start();
	if (ret != SUCCESS) {
		LOG(ERROR) << "Start process failed!";
		return ret;
	}
	
	return SUCCESS;
}

/**
* ��������: ֹͣ
*
* ���������
* ���������
* ���ز����������룬�ο�err_code.h
*/
ERR_CODE Solution::stop() {
	LOG(INFO) << "Stop solution";
	// ֹͣ�߳�
	ERR_CODE ret = m_process_manager.stop();
	if (ret != SUCCESS) {
		LOG(ERROR) << "Stop process failed!";
		return ret;
	}

	return SUCCESS;
}

/**
* ��������: �ͷ�
*
* ���������
* ���������
* ���ز����������룬�ο�err_code.h
*/
ERR_CODE Solution::release() {
	LOG(INFO) << "Release solution";
	// �����߳�
	ERR_CODE ret = m_process_manager.destroy();
	if (ret != SUCCESS) {
		LOG(ERROR) << "Destroy process failed!";
		return ret;
	}

	return SUCCESS;
}