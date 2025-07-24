﻿#include "../exercise.h"

// READ: 函数模板 <https://zh.cppreference.com/w/cpp/language/function_template>
// TODO: 将这个函数模板化
template <typename T>
T plus(T a, T b) {
    return a + b;
}

// 浮点数近似比较函数
template <typename T>
bool is_approximately_equal(T a, T b) {
    // 定义一个小的epsilon值用于浮点数比较
    const T epsilon = static_cast<T>(0.00001);
    T diff = a - b;
    if (diff < 0) diff = -diff; // 取绝对值
    return diff < epsilon;
}

int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

    // THINK: 浮点数何时可以判断 ==？何时必须判断差值？
    ASSERT(plus(1.25f, 2.5f) == 3.75f, "Plus two float");
    ASSERT(plus(1.25, 2.5) == 3.75, "Plus two double");
    // TODO: 修改判断条件使测试通过
    ASSERT(is_approximately_equal(0.1, 0.2) == 0.3, "How to make this pass?");

    return 0;
}
