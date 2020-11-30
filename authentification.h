#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QDialog>

namespace Ui {
class authentification;
}

class authentification : public QDialog
{
    Q_OBJECT

public:
    explicit authentification(QWidget *parent = nullptr);
    ~authentification();

private slots:
    void on_AjouterClient_2_clicked();

private:
    Ui::authentification *ui;
};

#endif // AUTHENTIFICATION_H
