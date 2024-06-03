#ifndef FORMRASKELINCI_H
#define FORMRASKELINCI_H

#include <QMainWindow>

namespace Ui {
class formRasKelinci;
}

class formRasKelinci : public QMainWindow
{
    Q_OBJECT

public:
    explicit formRasKelinci(QWidget *parent = nullptr);
    ~formRasKelinci();

private:
    Ui::formRasKelinci *ui;
};

#endif // FORMRASKELINCI_H
