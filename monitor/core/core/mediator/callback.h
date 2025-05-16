#pragma once

#include <functional>
#include "core/error/error_macros.h"
#include "core/string/ustring.h"

// 对回调的判断进行模板化
class Callback {
public:
	template <typename CallbackType, typename... Args>
	static auto invoke(const CallbackType &callback, const char *callback_name, Args &&...args)
			-> decltype(callback(std::forward<Args>(args)...)) {
		if (callback) {
			return callback(std::forward<Args>(args)...);
		} else {
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
