#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QIcon>
#include<QPropertyAnimation>
#include <QMediaPlayer>
#include "salle.h"
#include "reservation.h"
#include <QSqlTableModel>


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
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_3_clicked();

    void on_return_from_ajout_clicked();

    void on_return_from_ajout_2_clicked();

    void on_return_from_ajout_3_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_17_clicked();

    void on_return_from_ajout_4_clicked();

    void on_pushButton_19_clicked();

    void on_return_from_ajout_5_clicked();

    void on_pushButton_20_clicked();

    void on_return_from_ajout_6_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_16_clicked();



    void on_pushButton_21_clicked();



    void on_pushButton_18_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_12_clicked();


   // void on_tableView_activated(const QModelIndex &index);




    void on_recherche_salle_cursorPositionChanged();

    void on_recherche_reservation_cursorPositionChanged();


private:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
    QPropertyAnimation *animation1;
    QMediaPlayer *musicConect=new QMediaPlayer;
    Salle Etmp;
    Reservation Etmp1;
};
#endif // MAINWINDOW_H
