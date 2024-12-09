#include "QtWidgetsApplication1.h"
#include "ui_QtWidgetsApplication1.h"
#include <QFileDialog>
#include <QMessageBox>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::QtWidgetsApplication1),
    dxfManager(new DXFManager(this)),
    rs485Controller(new RS485Controller("COM1")) {
    ui->setupUi(this);

    // Подключение меню действий
    connect(ui->actionOpenFile, &QAction::triggered, this, &QtWidgetsApplication1::onOpenFile);
    connect(ui->actionProcessDXF, &QAction::triggered, this, &QtWidgetsApplication1::onProcessDXF);
    connect(ui->actionSendCommands, &QAction::triggered, this, &QtWidgetsApplication1::onSendCommands);
}

QtWidgetsApplication1::~QtWidgetsApplication1() {
    delete ui;
    delete dxfManager;
    delete rs485Controller;
}

void QtWidgetsApplication1::onOpenFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open DXF File", "", "DXF Files (*.dxf)");
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No file selected.");
        return;
    }

    if (!dxfManager->loadFile(filePath)) {
        QMessageBox::critical(this, "Error", "Failed to load DXF file.");
    }
    else {
        QMessageBox::information(this, "Success", "DXF file loaded successfully.");
    }
}

void QtWidgetsApplication1::onProcessDXF() {
    auto contours = dxfManager->getContours();
    // Process contours here
    QMessageBox::information(this, "Info", "DXF processing completed.");
}

void QtWidgetsApplication1::onSendCommands() {
    QStringList commands = { "a100", "b50", "c30" };  // Example commands
    rs485Controller->sendCommands(commands);
    QMessageBox::information(this, "Info", "Commands sent successfully.");
}
