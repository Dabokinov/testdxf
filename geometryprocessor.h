#ifndef GEOMETRYPROCESSOR_H
#define GEOMETRYPROCESSOR_H

#include <QObject>
#include <QPainterPath>
#include <QStringList>
#include <vector>

class GeometryProcessor : public QObject {
    Q_OBJECT

public:
    explicit GeometryProcessor(QObject* parent = nullptr);
    void processContours(const std::vector<QPainterPath>& contours);
    QStringList generateCommands();

private:
    QStringList commands;
    void analyzeGeometry(const QPainterPath& path);
};

#endif // GEOMETRYPROCESSOR_H
