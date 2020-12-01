#ifndef GESTION_FILM_H
#define GESTION_FILM_H

#include <QDialog>
#include "film.h"
#include "ticket.h"
namespace Ui {
class gestion_film;
}

class gestion_film : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_film(QWidget *parent = nullptr);
    ~gestion_film();

private slots:
    void on_AjouterFilm_clicked();

    void on_ModifierFilm_clicked();

    void on_SupprimerFilm_clicked();

    void on_Close_2_clicked();

    void on_Close_ticket_clicked();

    void on_ajouterTicket_clicked();

    void on_SupprimerTicket_clicked();

    void on_ModifierTicket_2_clicked();

private:
    Ui::gestion_film *ui;
    Film tmpc;
        Ticket empc;
};

#endif // GESTION_FILM_H
