#include "formraskelinci.h"
#include "ui_formraskelinci.h"

formRasKelinci::formRasKelinci(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::formRasKelinci)
{
    ui->setupUi(this);
}

formRasKelinci::~formRasKelinci()
{
    delete ui;
}
