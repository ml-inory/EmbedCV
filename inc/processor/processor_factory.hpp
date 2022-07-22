/*******************************************************************************
* 文 件 名 : processor_factory.hpp
* 创建日期 : 2022 - 07 - 22
* 作    者 : rzyang
* 功能描述 : Processor工厂
* ******************************************************************************/
#pragma once

#include "object_factory.hpp"
#include "processor.hpp"
#include "manager/model_manager.h"

#include <string>

/// 需要反射的类使用该宏注册
#ifndef REGISTER_PROCESSOR
#define REGISTER_PROCESSOR(YourClass, ...) \
    static int __type##YourClass = ObjectFactory::regCreateObjFunc(#YourClass, (void*)&__createObjFunc<ProcessorImpl<YourClass>, ##__VA_ARGS__>);
#endif