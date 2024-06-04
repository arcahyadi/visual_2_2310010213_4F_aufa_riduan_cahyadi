#include "formberita.h"
#include "ui_formberita.h"

formBerita::formBerita(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::formBerita)
{
    ui->setupUi(this);

    QSqlDatabase Koneksi = QSqlDatabase::addDatabase("QODBC");
    Koneksi.setDatabaseName("visual_2");
    Koneksi.setUserName("root");
    Koneksi.setPassword("");

    if (Koneksi.open()){
        qDebug()<<"Database terkoneksi";
    }else{
        qDebug()<<Koneksi.lastError().text();
    }
}

formBerita::~formBerita()
{
    delete ui;
}




void formBerita::on_pushButton_clicked()
{
    QSqlQuery sql(Koneksi);
    sql.prepare("INSERT INTO berita (berita_id,nama_berita,isi_berita,jenis_berita)"
                "VALUES(:berita_id,:nama_berita,:isi_berita,:jenis_berita)");
    sql.bindValue(":berita_id",ui->iDberitaLineEdit->text().toInt());
    sql.bindValue(":nama_berita",ui->namaBeritaLineEdit->text());
    sql.bindValue(":isi_berita",ui->isiBeritaLineEdit->text());
    sql.bindValue(":jenis_berita",ui->jenisBeritaLineEdit->text());

    if (!sql.exec()) {
        qDebug() << "Error executing query:" << sql.lastError().text();
    } else {
        qDebug() << "Insertion successful!";
    }

}

