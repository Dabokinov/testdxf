#ifndef QTWIDGETSAPPLICATION1_H
#define QTWIDGETSAPPLICATION1_H

#include <QMainWindow>
#include "DXFManager.h"
#include "RS485Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtWidgetsApplication1; }
QT_END_NAMESPACE

class QtWidgetsApplication1 : public QMainWindow {
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget* parent = nullptr);
    ~QtWidgetsApplication1();

private slots:
    void onOpenFile();
    void onProcessDXF();
    void onSendCommands();

private:
    Ui::QtWidgetsApplication1* ui;
    DXFManager* dxfManager;
    RS485Controller* rs485Controller;
};

#endif // QTWIDGETSAPPLICATION1_H
