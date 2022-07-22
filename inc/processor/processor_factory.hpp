/*******************************************************************************
* �� �� �� : processor_factory.hpp
* �������� : 2022 - 07 - 22
* ��    �� : rzyang
* �������� : Processor����
* ******************************************************************************/
#pragma once

#include "object_factory.hpp"
#include "processor.hpp"
#include "manager/model_manager.h"

#include <string>

/// ��Ҫ�������ʹ�øú�ע��
#ifndef REGISTER_PROCESSOR
#define REGISTER_PROCESSOR(YourClass, ...) \
    static int __type##YourClass = ObjectFactory::regCreateObjFunc(#YourClass, (void*)&__createObjFunc<ProcessorImpl<YourClass>, ##__VA_ARGS__>);
#endif