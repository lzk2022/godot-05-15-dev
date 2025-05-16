#pragma once

#include <functional>
// #include "core/error/error_macros.h"
#include "core/mediator/callback.h"

class IDocTools; // 前向声明

class EditorHelpCallback {
public:
	using GenerateDocCallback = std::function<void(bool)>;
	using GetDocDataCallback = std::function<IDocTools *()>;

	static void set_callback_generate_doc(GenerateDocCallback p_callback) {
		m_generate_doc_callback = std::move(p_callback);
	}

	static void generate_doc(bool p_use_cache = true) {
		Callback::invoke(m_generate_doc_callback, "generate_doc", p_use_cache);
	}

	static void set_callback_get_doc_data(GetDocDataCallback p_callback) {
		m_get_doc_data_callback = std::move(p_callback);
	}

	static IDocTools *get_doc_data() {
		return Callback::invoke(m_get_doc_data_callback, "get_doc_data");
	}

private:
	inline static GenerateDocCallback m_generate_doc_callback = nullptr;
	inline static GetDocDataCallback m_get_doc_data_callback = nullptr;
};
