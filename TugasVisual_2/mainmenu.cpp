#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    formberita = new formBerita;
    formkamuspenyakit = new formKamusPenyakit;
    formkelinci = new formKelinci;
    formraskelinci = new formRasKelinci;
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_clicked()
{
    formkelinci->show();
}

void MainMenu::on_pushButton_2_clicked()
{
    formraskelinci->show();
}

void MainMenu::on_pushButton_3_clicked()
{
    formberita->show();
}

void MainMenu::on_pushButton_4_clicked()
{
    formkamuspenyakit->show();
}
