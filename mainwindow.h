//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H
//
//#include <QMainWindow>
//#include "dxfmanager.h"
//#include "geometryprocessor.h"
//#include "rs485controller.h"
//
//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE
//
//class MainWindow : public QMainWindow {
//    Q_OBJECT
//
//public:
//    MainWindow(QWidget* parent = nullptr);
//    ~MainWindow();
//
//private slots:
//    void loadDXFFile();
//    void processGeometry();
//    void sendCommands();
//
//private:
//    Ui::MainWindow* ui;
//    DXFManager* dxfManager;
//    GeometryProcessor* geometryProcessor;
//    RS485Controller* rs485Controller;
//
//    void setupConnections();
//};
//
//#endif // MAINWINDOW_H
