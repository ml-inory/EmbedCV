/*******************************************************************************
* �� �� �� : object_factory.hpp
* �������� : 2022 - 07 - 22
* ��    �� : rzyang
* �������� : �����乤��
* ******************************************************************************/
#pragma once

#include <map>
#include <string>
#include <memory>


/// ���󴴽�ģ�溯���� �õ��� c++11 �Ŀɱ����
template<class YourClass, typename ...ArgType>
void* __createObjFunc(ArgType... arg)
{
    return new YourClass(arg...);
}

/// ��Ҫ�������ʹ�øú�ע��
#ifndef REGISTER_OBJECT
#define REGISTER_OBJECT(YourClass, ...) \
    static int __type##YourClass = ObjectFactory::regCreateObjFunc(#YourClass, (void*)&__createObjFunc<YourClass, ##__VA_ARGS__>);
#endif

/// ���󹤳���������������
class ObjectFactory
{
public:
    /// ������������ BaseClass ����Ķ���
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

    /// ע�ᡰ������Ķ���Ĺ���������
    static int regCreateObjFunc(const std::string& className, void* func)
    {
        _GetStaticFuncMap()[className] = func;
        return 0;
    }

private:
    /// ��ȡ ������==>����ָ�� ��ӳ�䡣
    static std::map<std::string, void*>& _GetStaticFuncMap()
    {
        static std::map<std::string, void*> _classMap;
        return _classMap;
    }
};