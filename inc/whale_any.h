/**
 * *****************************************************************************
 * 				��Ȩ���� (C), �ᢽ��ĿƼ������ݣ����޹�˾
 * 				Copyright 2022 Whale, All Rights Reserved.
 * ******************************************************************************
 * �� �� ��: whale_any.hpp
 * ��������: 2022-05-30
 * ��    ��: rongzhaoyang (rongzhaoyang@whale.im)
 * ��������: ���Ͳ���
 * ******************************************************************************
 */
#pragma once

#include <utility>
#include <memory>

class WhaleAnyBase {
public:
    virtual ~WhaleAnyBase() {}
};

template <typename T>
class WhaleAnyImpl : public WhaleAnyBase {
public:
    explicit WhaleAnyImpl(T t) :
        value(std::move(t))
    {

    }

public:
    T value;
};

/**
 * ��������: ���Ͳ�������ͨ��as<T>()�ָ�
 *
 * ����:
 *
 * int foo = 1;
 * float bar = 2.0f;
 *
 * WhaleAny any_foo = foo;
 * WhaleAny any_bar = bar;
 *
 * int real_foo = any_foo.as<int>();
 * float real_bar = any_foo.as<float>();
 *
 */
class WhaleAny {
public:
    template <typename T>
    WhaleAny(T t) :
        m_base_ptr(new WhaleAnyImpl<T>(std::forward<T>(t)))
    {

    }

    template <typename T>
    T as() {
        return static_cast<WhaleAnyImpl<T>*>(m_base_ptr.get())->value;
    }

private:
    std::unique_ptr<WhaleAnyBase> m_base_ptr;
};