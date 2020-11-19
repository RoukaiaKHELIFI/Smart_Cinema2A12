#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include<QIcon>
#include <QPropertyAnimation>
#include <QPixmap>
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
  //  void on_pushButton_clicked(bool checked);

    //void on_pushButton_2_clicked();

  //  void on_annuler_clicked();

    void on_close_clicked();

    void on_closeClient_clicked();

    void on_AjouterClient_clicked();


    void on_AfficherClientTable_activated();
    void Afficher_Client_Table();

    void on_SupprimerClient_clicked();

    void on_ModifierClient_clicked();

private:
    Ui::MainWindow *ui;
    client tmpc;
    QPropertyAnimation *animation;
};
#endif // MAINWINDOW_H
