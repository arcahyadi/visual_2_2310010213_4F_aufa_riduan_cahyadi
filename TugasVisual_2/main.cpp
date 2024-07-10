#include "mainmenu.h"

#include <QApplication>
#include <formberita.h>
#include <formkamuspenyakit.h>
#include <formkelinci.h>
#include <formraskelinci.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.show();
    return a.exec();
}
