#ifndef SCENE_NODE_H
#define SCENE_NODE_H

#include "core/object/object.h"

class NodePath;
class INode : public Object {
	GDCLASS(INode, Object);

public:
	virtual ~INode() = default;
	virtual bool is_inside_tree() const = 0;
	virtual NodePath get_path() const = 0;

public:
	static constexpr const char *SubClassName = "Node";
};

#endif
