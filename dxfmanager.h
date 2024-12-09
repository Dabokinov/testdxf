#ifndef DXFMANAGER_H
#define DXFMANAGER_H

#include <QObject>
#include <QPainterPath>
#include <QString>
#include <vector>

class DXFManager : public QObject {
    Q_OBJECT

public:
    explicit DXFManager(QObject* parent = nullptr);
    bool loadFile(const QString& filePath);
    std::vector<QPainterPath> getContours() const;

private:
    std::vector<QPainterPath> contours;
    void parseDXF(const QString& fileContent);
};

#endif // DXFMANAGER_H
