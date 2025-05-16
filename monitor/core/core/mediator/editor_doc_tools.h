#pragma once

#include "core/doc_data.h"
#include "core/templates/rb_set.h"

class String;
class IDocTools {
public:
	virtual ~IDocTools() = default;
	virtual HashMap<String, DocData::ClassDoc> &get_class_list() = 0;
};
