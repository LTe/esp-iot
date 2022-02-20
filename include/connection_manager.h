#ifndef _CONNECTION_MANAGER_H_
#define _CONNECTION_MANAGER_H_

#include <WiFiManager.h>

class ConnectionManager
{
    WiFiManager manager;

public:
    ConnectionManager();
    void setup();
    void connect(std::function<void()> callback);
};

#endif
