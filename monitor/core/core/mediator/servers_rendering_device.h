
#ifndef SERVERS_RENDERING_DEVICE_H
#define SERVERS_RENDERING_DEVICE_H

#include "core/mediator/service_locator.h"

class IRenderingDevice {
public:
	virtual ~IRenderingDevice() = default;
	virtual void _set_max_fps(int fps) = 0;
};

#endif
