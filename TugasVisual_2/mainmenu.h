#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <formkelinci.h>
#include <formberita.h>
#include <formkamuspenyakit.h>
#include <formraskelinci.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainMenu;
}
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainMenu *ui;
    formKelinci *formkelinci;
    formRasKelinci *formraskelinci;
    formBerita *formberita;
    formKamusPenyakit *formkamuspenyakit;
};
#endif // MAINMENU_H
