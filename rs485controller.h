#ifndef RS485CONTROLLER_H
#define RS485CONTROLLER_H

#include <QStringList>
#include <windows.h>

class RS485Controller {
public:
    RS485Controller(const std::string& portName);
    ~RS485Controller();
    void sendCommands(const QStringList& commands);

private:
    HANDLE serialHandle;
    bool setupPort(const std::string& portName);
    void closePort();
};

#endif // RS485CONTROLLER_H
