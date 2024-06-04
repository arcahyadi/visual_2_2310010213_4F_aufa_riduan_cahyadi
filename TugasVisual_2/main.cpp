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
    qDebug()<<"driver " <<QSqlDatabase::drivers();

    // QSqlDatabase konekDB = QSqlDatabase::addDatabase("QODBC");
    // konekDB.setDatabaseName("visual_2");
    // konekDB.setUserName("root");
    // konekDB.setPassword("");

    // if (konekDB.open()){
    //         qDebug()<<"Database terkoneksi";
    // }else{
    //         qDebug()<<konekDB.lastError().text();
    //     }

    return a.exec();
}
