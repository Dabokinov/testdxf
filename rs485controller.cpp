#include "RS485Controller.h"
#include <iostream>

RS485Controller::RS485Controller(const std::string& portName) : serialHandle(INVALID_HANDLE_VALUE) {
    setupPort(portName);
}

RS485Controller::~RS485Controller() {
    closePort();
}

bool RS485Controller::setupPort(const std::string& portName) {
    serialHandle = CreateFileA(
        portName.c_str(),
        GENERIC_READ | GENERIC_WRITE,
        0,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    if (serialHandle == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to open COM port!" << std::endl;
        return false;
    }

    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(serialHandle, &dcbSerialParams)) {
        std::cerr << "Error: Unable to configure COM port!" << std::endl;
        return false;
    }

    return true;
}

void RS485Controller::closePort() {
    if (serialHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(serialHandle);
        serialHandle = INVALID_HANDLE_VALUE;
    }
}

void RS485Controller::sendCommands(const QStringList& commands) {
    if (serialHandle == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Port not opened!" << std::endl;
        return;
    }

    for (const auto& cmd : commands) {
        QByteArray data = cmd.toUtf8();
        DWORD bytesWritten;
        WriteFile(serialHandle, data.data(), data.size(), &bytesWritten, nullptr);
    }
}
