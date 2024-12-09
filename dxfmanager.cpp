#include "DXFManager.h"
#include <QFile>
#include <QTextStream>

DXFManager::DXFManager(QObject* parent) : QObject(parent) {}

bool DXFManager::loadFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    parseDXF(content);
    return true;
}

std::vector<QPainterPath> DXFManager::getContours() const {
    return contours;
}

void DXFManager::parseDXF(const QString& fileContent) {
    contours.clear();
    QPainterPath path;
    path.moveTo(0, 0); // Example start
    path.lineTo(100, 0); // Example line
    path.addEllipse(QPointF(50, 50), 20, 20); // Example circle
    contours.push_back(path);
}
