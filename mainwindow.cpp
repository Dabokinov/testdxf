#include "mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "QtWidgetsApplication1.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
    dxfManager(new DXFManager(this)),
    geometryProcessor(new GeometryProcessor(this)),
    rs485Controller(new RS485Controller(this)) {
    ui->setupUi(this);
    setupConnections();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::setupConnections() {
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadDXFFile);
    connect(ui->processButton, &QPushButton::clicked, this, &MainWindow::processGeometry);
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::sendCommands);
}

void MainWindow::loadDXFFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open DXF File", "", "DXF Files (*.dxf)");
    if (!filePath.isEmpty()) {
        if (!dxfManager->loadFile(filePath)) {
            QMessageBox::warning(this, "Error", "Failed to load DXF file.");
        }
    }
}


void MainWindow::processGeometry() {
    auto contours = dxfManager->getContours();
    geometryProcessor->processContours(contours);
}

void MainWindow::sendCommands() {
    auto commands = geometryProcessor->generateCommands();
    rs485Controller->sendCommands(commands);
}

