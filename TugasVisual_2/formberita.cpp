#include "formberita.h"
#include "ui_formberita.h"

formBerita::formBerita(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::formBerita)
{
    ui->setupUi(this);
}

formBerita::~formBerita()
{
    delete ui;
}
