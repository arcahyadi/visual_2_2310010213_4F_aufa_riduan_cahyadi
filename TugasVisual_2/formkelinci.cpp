#include "formkelinci.h"
#include "ui_formkelinci.h"

formKelinci::formKelinci(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::formKelinci)
{
    ui->setupUi(this);
}

formKelinci::~formKelinci()
{
    delete ui;
}
