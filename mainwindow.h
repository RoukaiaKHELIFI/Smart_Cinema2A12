#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "film.h"
#include "ticket.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AjouterFilm_clicked();

    void on_SupprimerFilm_clicked();

    void on_Close_2_clicked();

    void on_Close_ticket_clicked();

    void on_ajouterTicket_clicked();



    void on_SupprimerTicket_clicked();

    void on_ModifierFilm_clicked();

    void on_RefreshFilm_clicked();

    void on_RefreshTicket_clicked();

    void on_ModifierTicket_clicked();

private:
    Ui::MainWindow *ui;
    Film tmpc;
    Ticket empc;
};
#endif // MAINWINDOW_H
