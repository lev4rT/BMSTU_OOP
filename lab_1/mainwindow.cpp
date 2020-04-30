#include <QPainter>
#include <QFileDialog>
#include <QDebug>
#include <QGraphicsScene>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task_manager.h"
#include "scene.h"
#include "meta.h"

static metadata_t meta;
static QGraphicsScene *null_scene = nullptr;
static screen_t screen = {0, 0, 0};
static scene_t scene = {null_scene, screen};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene.canvas = new QGraphicsScene(0, 0, 200, 200, ui->graphicsView);
    scene.screen.distance = 50;
    meta.option = INIT;
    task_manager(meta, scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "",
                                                      tr("text (*.TXT)"));
    meta.option = LOAD;
    char *name = new char[fileName.size() + 1];
    std::string stdString = fileName.toStdString();
    std::copy(stdString.begin(), stdString.end(), name);
    name[fileName.size()] = '\0';
    meta.filename = name;
    task_manager(meta, scene);

    meta.option = DRAW;
    task_manager(meta, scene);
    ui->graphicsView->setScene(scene.canvas);
}

void MainWindow::on_pushButton_clicked()
{
    meta.parameters_move.dx = ui->inputMovX->text().toInt();
    meta.parameters_move.dy = ui->inputMovY->text().toInt();
    meta.parameters_move.dz = ui->inputMovZ->text().toInt();

    meta.option = MOVE;
    task_manager(meta, scene);

    meta.option = DRAW;
    task_manager(meta, scene);
    ui->graphicsView->setScene(scene.canvas);
}

void MainWindow::on_pushButton_4_clicked()
{
    meta.parameters_scale.Mx = ui->inputMx->text().toInt();
    meta.parameters_scale.My = ui->inputMy->text().toInt();
    meta.parameters_scale.Mz = ui->inputMz->text().toInt();

    meta.parameters_scale.kx = ui->inputKx->text().toInt();
    meta.parameters_scale.ky = ui->inputKy->text().toInt();
    meta.parameters_scale.kz = ui->inputKz->text().toInt();

    meta.option = SCALE;
    task_manager(meta, scene);

    meta.option = DRAW;
    task_manager(meta, scene);
    ui->graphicsView->setScene(scene.canvas);
}

void MainWindow::on_buttonExecXY_clicked()
{
    meta.parameters_rotate.x = ui->inputRotateX->text().toDouble();
    meta.parameters_rotate.y = ui->inputRotateY->text().toDouble();
    meta.parameters_rotate.z = 0;
    meta.parameters_rotate.angle = ui->inputRotateAngle->text().toDouble();
    meta.parameters_rotate.plane = XY;

    meta.option = ROTATE;
    task_manager(meta, scene);

    meta.option = DRAW;
    task_manager(meta, scene);
    ui->graphicsView->setScene(scene.canvas);
}

void MainWindow::on_buttonExecXZ_clicked()
{
    meta.parameters_rotate.x = ui->inputRotateX->text().toDouble();
    meta.parameters_rotate.y = 0;
    meta.parameters_rotate.z = ui->inputRotateZ->text().toDouble();
    meta.parameters_rotate.angle = ui->inputRotateAngle->text().toDouble();
    meta.parameters_rotate.plane = XZ;

    meta.option = ROTATE;
    task_manager(meta, scene);

    meta.option = DRAW;
    task_manager(meta, scene);
    ui->graphicsView->setScene(scene.canvas);
}

void MainWindow::on_buttonExecYZ_clicked()
{
    meta.parameters_rotate.x = 0;
    meta.parameters_rotate.y = ui->inputRotateY->text().toDouble();
    meta.parameters_rotate.z = ui->inputRotateZ->text().toDouble();
    meta.parameters_rotate.angle = ui->inputRotateAngle->text().toDouble();
    meta.parameters_rotate.plane = YZ;

    meta.option = ROTATE;
    task_manager(meta, scene);

    meta.option = DRAW;
    task_manager(meta, scene);
    ui->graphicsView->setScene(scene.canvas);
}

void MainWindow::on_pushButton_3_clicked()
{
    meta.option = DELETE;
    task_manager(meta, scene);
    ui->graphicsView->setScene(scene.canvas);
}
