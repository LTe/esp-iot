#include <connection_manager.h>

#define IP_ADDRESS IPAddress(192, 168, 1, 1)
#define MASK IPAddress(255, 255, 255, 0)

ConnectionManager::ConnectionManager()
{
}

void ConnectionManager::setup()
{
    manager.setDebugOutput(true);
    manager.setConfigPortalTimeout(180);
    manager.setAPStaticIPConfig(IP_ADDRESS, IP_ADDRESS, MASK);
}

void ConnectionManager::connect(std::function<void()> callback)
{
    manager.setAPCallback([callback](WiFiManager *manager)
                          { callback(); });
    manager.autoConnect("ESP-Configure");
}
