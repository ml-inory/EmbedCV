/**
 * *****************************************************************************
 * 				版权所有 (C), 帷幄匠心科技（杭州）有限公司
 * 				Copyright 2022 Whale, All Rights Reserved.
 * ******************************************************************************
 * 文 件 名: whale_any.hpp
 * 创建日期: 2022-05-30
 * 作    者: rongzhaoyang (rongzhaoyang@whale.im)
 * 功能描述: 类型擦除
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
 * 功能描述: 类型擦除，可通过as<T>()恢复
 *
 * 例子:
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