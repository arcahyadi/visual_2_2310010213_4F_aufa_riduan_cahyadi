#include "formkamuspenyakit.h"
#include "ui_formkamuspenyakit.h"

formKamusPenyakit::formKamusPenyakit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::formKamusPenyakit)
{
    ui->setupUi(this);
}

formKamusPenyakit::~formKamusPenyakit()
{
    delete ui;
}
