/*******************************************************************************
* 文 件 名 : object_factory.hpp
* 创建日期 : 2022 - 07 - 22
* 作    者 : rzyang
* 功能描述 : 对象反射工厂
* ******************************************************************************/
#pragma once

#include <map>
#include <string>
#include <memory>


/// 对象创建模版函数， 用到了 c++11 的可变参数
template<class YourClass, typename ...ArgType>
void* __createObjFunc(ArgType... arg)
{
    return new YourClass(arg...);
}

/// 需要反射的类使用该宏注册
#ifndef REGISTER_OBJECT
#define REGISTER_OBJECT(YourClass, ...) \
    static int __type##YourClass = ObjectFactory::regCreateObjFunc(#YourClass, (void*)&__createObjFunc<YourClass, ##__VA_ARGS__>);
#endif

/// 对象工厂，根据类名创建
class ObjectFactory
{
public:
    /// 根据类名创建 BaseClass 子类的对象
    template<class BaseClass, typename ...ArgType>
    static std::shared_ptr<BaseClass> create(const std::string& className, ArgType... arg)
    {
        typedef BaseClass* (*_CreateFactory)(ArgType...);

        auto& _funcMap = _GetStaticFuncMap();
        auto iFind = _funcMap.find(className);
        if (iFind == _funcMap.end()) {
            LOG(ERROR) << "Cannot find object for " << className;
            LOG(ERROR) << "Valid names include:";
            for (auto it = _funcMap.begin(); it != _funcMap.end(); ++it) {
                LOG(ERROR) << it->first;
            }
            return nullptr;
        }   
        else
            return std::shared_ptr< BaseClass>(reinterpret_cast<_CreateFactory>(_funcMap[className])(arg...));
    }

    /// 注册“创建类的对象的工厂函数”
    static int regCreateObjFunc(const std::string& className, void* func)
    {
        _GetStaticFuncMap()[className] = func;
        return 0;
    }

private:
    /// 获取 函数名==>函数指针 的映射。
    static std::map<std::string, void*>& _GetStaticFuncMap()
    {
        static std::map<std::string, void*> _classMap;
        return _classMap;
    }
};