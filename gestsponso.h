#ifndef GESTSPONSO_H
#define GESTSPONSO_H

#include <QDialog>
#include "promotion.h"
namespace Ui {
class gestsponso;
}

class gestsponso : public QDialog
{
    Q_OBJECT

public:
    explicit gestsponso(QWidget *parent = nullptr);
    ~gestsponso();

private slots:
    void on_pushButton_clicked();

    void on_btn_rechercher_clicked();

    void on_btn_refresh_clicked();

    void on_btn_tri_nom_clicked();

    void on_btn_tri_id_clicked();

    void on_btn_pdf_clicked();

    void on_btn_modifier_clicked();

    void on_btn_supprimer_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gestsponso *ui;
    Promotion tmpp;
};

#endif // GESTSPONSO_H
