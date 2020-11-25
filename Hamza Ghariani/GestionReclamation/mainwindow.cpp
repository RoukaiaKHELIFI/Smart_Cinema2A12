#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fconnection.h"
#include "acceuil.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->hide();



    QPixmap circleimg = QPixmap(":/img/seconnecter/l-1-circle.png");
    ui->circimg->setPixmap(circleimg);
    QPixmap loginimg = QPixmap(":/img/seconnecter/l-1-login.png");
    ui->loglogo->setPixmap(loginimg);
    QPixmap iconimg = QPixmap(":/img/seconnecter/icons/icons.png");
    ui->icons->setPixmap(iconimg);
    QPixmap developerLogo = QPixmap(":/img/seconnecter/Rezidevs.png");
    ui->hamzacopyright->setPixmap(developerLogo);
    QPixmap text2 = QPixmap(":/img/seconnecter/text1.png");
    ui->text2->setPixmap(text2);
    QPixmap bg = QPixmap(":/img/seconnecter/bg.jpg");
    ui->bg->setPixmap(bg);

    ui->utilisateur->setPlaceholderText("Utilisateur");
    ui->mdp->setPlaceholderText("Mot de passe");






}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginb_clicked()
{

    dbutilistaeur ut;
    QString utilisateur,mdp;
    utilisateur=ui->utilisateur->text();
    mdp=ui->mdp->text();
    bool trouver=ut.utilisateurF1(utilisateur);
    bool trouver2=ut.mdpF1(mdp);

    if(!trouver&&!trouver2)
        ui->testlogs->setText("Mot de passe ou Utilisateur incorrecte.");
    else
    {
        acceuil D1;
        D1.setModal(true);
        D1.exec();
    }






}
