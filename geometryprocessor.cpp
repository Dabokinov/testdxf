#include "geometryprocessor.h"

GeometryProcessor::GeometryProcessor(QObject* parent) : QObject(parent) {}

void GeometryProcessor::processContours(const std::vector<QPainterPath>& contours) {
    commands.clear();
    for (const auto& path : contours) {
        analyzeGeometry(path);
    }
}

QStringList GeometryProcessor::generateCommands() {
    return commands;
}

void GeometryProcessor::analyzeGeometry(const QPainterPath& path) {
    // јнализ геометрии: углы, длины и т.д.
    commands.append("a100");
    commands.append("b50");
}
