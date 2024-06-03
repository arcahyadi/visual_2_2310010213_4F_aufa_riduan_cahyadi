#ifndef FORMKELINCI_H
#define FORMKELINCI_H

#include <QMainWindow>

namespace Ui {
class formKelinci;
}

class formKelinci : public QMainWindow
{
    Q_OBJECT

public:
    explicit formKelinci(QWidget *parent = nullptr);
    ~formKelinci();

private:
    Ui::formKelinci *ui;
};

#endif // FORMKELINCI_H
