#pragma once

#include "core/error/error_macros.h"
#include "core/string/ustring.h"
#include <functional>


// 对回调的判断进行模板化
class Callback {
public:
	template <typename CallbackType, typename... Args>
	static auto invoke(const CallbackType &callback, const char *callback_name, Args &&...args)
		-> decltype(callback(std::forward<Args>(args)...)) {
		if (callback) {
			return callback(std::forward<Args>(args)...);
		}
		else {
			ERR_PRINT(vformat("Callback '%s' not set!", callback_name));
			if constexpr (!std::is_same_v<decltype(callback(std::forward<Args>(args)...)), void>) {
				return {};
			}
		}
	}
};

// Callback::invoke(m_generate_doc_callback, "generate_doc", p_use_cache);

// 等价于 👇

//if (m_generate_doc_callback) {
//	m_generate_doc_callback(p_use_cache);
//} else {
//	ERR_PRINT("Doc generator callback not set!");
//}

// 通用的回调注册宏（推荐）
#define REGISTER_CALLBACK(CLASS, METHOD) \
	I##CLASS::set_callback_##METHOD(CLASS::METHOD)

// 支持1个参数
#define DEFINE_CALLBACK_1(callback_name, T1)                                       \
public:                                                                            \
	using callback_name##Callback = std::function<void(T1)>;                       \
	static void callback_name(T1 p_1) {                                            \
		Callback::invoke(m_##callback_name##_callback, #callback_name, p_1);       \
	}                                                                              \
	static void set_callback_##callback_name(callback_name##Callback p_callback) { \
		m_##callback_name##_callback = p_callback;                                 \
	}                                                                              \
                                                                                   \
private:                                                                           \
	inline static callback_name##Callback m_##callback_name##_callback = nullptr;

// 支持2个参数
#define DEFINE_CALLBACK_2(callback_name, T1, T2)                                         \
public:                                                                                  \
	using callback_name##Callback = std::function<void(T1, T2)>;                         \
	static void callback_name(T1 p_1, T2 p_2) {                                          \
		return Callback::invoke(m_##callback_name##_callback, #callback_name, p_1, p_2); \
	}                                                                                    \
	static void set_callback_##callback_name(callback_name##Callback p_callback) {       \
		m_##callback_name##_callback = p_callback;                                       \
	}                                                                                    \
                                                                                         \
private:                                                                                 \
	inline static callback_name##Callback m_##callback_name##_callback = nullptr;

// 支持3个参数
#define DEFINE_CALLBACK_3(callback_name, T1, T2, T3)                                   \
public:                                                                                \
	using callback_name##Callback = std::function<void(T1, T2, T3)>;                   \
	static void callback_name(T1 p_1, T2 p_2, T3 p_3) {                                \
		Callback::invoke(m_##callback_name##_callback, #callback_name, p_1, p_2, p_3); \
	}                                                                                  \
	static void set_callback_##callback_name(callback_name##Callback p_callback) {     \
		m_##callback_name##_callback = p_callback;                                     \
	}                                                                                  \
                                                                                       \
private:                                                                               \
	inline static callback_name##Callback m_##callback_name##_callback = nullptr;

// 支持4个参数
#define DEFINE_CALLBACK_4(callback_name, T1, T2, T3, T4)                                    \
public:                                                                                     \
	using callback_name##Callback = std::function<void(T1, T2, T3, T4)>;                    \
	static void callback_name(T1 p_1, T2 p_2, T3 p_3, T4 p_4) {                             \
		Callback::invoke(m_##callback_name##_callback, #callback_name, p_1, p_2, p_3, p_4); \
	}                                                                                       \
	static void set_callback_##callback_name(callback_name##Callback p_callback) {          \
		m_##callback_name##_callback = p_callback;                                          \
	}                                                                                       \
                                                                                            \
private:                                                                                    \
	inline static callback_name##Callback m_##callback_name##_callback = nullptr;
