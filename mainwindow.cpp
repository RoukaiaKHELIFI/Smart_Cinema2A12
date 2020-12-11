#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "salle.h"
#include <QMessageBox>
#include "reservation.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    ui->tableView->setModel(Etmp.afficher());
    ui->affichage_reservation->setModel(Etmp1.afficher_res());
    setWindowIcon(QIcon("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/popcorn"));

    QPixmap pixel ("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/logo");
    ui->expertCode->setPixmap(pixel.scaled(200,50,Qt::KeepAspectRatio));

    QPixmap pixel1 ("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/popcorn");
    ui->Pathe->setPixmap(pixel1.scaled(200,100,Qt::KeepAspectRatio));

    QPixmap pixel2 ("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/logo");
    ui->expertCode_2->setPixmap(pixel.scaled(200,50,Qt::KeepAspectRatio));

    QPixmap pixel3 ("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/popcorn");
    ui->Pathe_2->setPixmap(pixel1.scaled(200,100,Qt::KeepAspectRatio));

    //animation pour logo pathé
    int w=ui->Pathe_2->width();
    int h=ui->Pathe_2->height();

    animation = new QPropertyAnimation(ui->Pathe_2,"geometry");
    animation->setDuration(1999);
    animation->setStartValue(ui->Pathe_2->geometry());

    animation->setEndValue(QRect(600,20,w,h));
    animation->setLoopCount(-1);
    animation->start();

    //animation pour expert_code
    int w1=ui->expertCode_2->width();
    int h1=ui->expertCode_2->height();

    animation1 = new QPropertyAnimation(ui->expertCode_2,"geometry");
    animation1->setDuration(1999);
    animation1->setStartValue(ui->expertCode_2->geometry());
    animation1->setEndValue(QRect(600,300,w1,h1));

    animation1->setLoopCount(-1);
    animation1->start();
    //animation pour logo pathé
    int w0=ui->Pathe->width();
    int h0=ui->Pathe->height();

    animation = new QPropertyAnimation(ui->Pathe,"geometry");
    animation->setDuration(1999);
    animation->setStartValue(ui->Pathe->geometry());

    animation->setEndValue(QRect(600,20,w0,h0));
    animation->setLoopCount(-1);
    animation->start();

    //animation pour expert_code
    int w2=ui->expertCode->width();
    int h2=ui->expertCode->height();

    animation1 = new QPropertyAnimation(ui->expertCode,"geometry");
    animation1->setDuration(1999);
    animation1->setStartValue(ui->expertCode->geometry());
    animation1->setEndValue(QRect(600,300,w2,h2));

    animation1->setLoopCount(-1);
    animation1->start();
    //Controle De saisie
    //ui->nm_salle_ajout->setValidator(new QIntValidator(0,999,this));
    ui->nm_salle_modif->setValidator(new QIntValidator(0,999,this));
    ui->nm_salle_supp->setValidator(new QIntValidator(0,999,this));
    ui->nb_chaise_ajout->setValidator(new QIntValidator(0,999,this));
    ui->nb_chaise_modif->setValidator(new QIntValidator(0,999,this));
    ui->nb_baffles_ajout->setValidator(new QIntValidator(0,999,this));
    ui->nb_baffles_modif->setValidator(new QIntValidator(0,999,this));
    ui->id_client->setValidator(new QIntValidator(0,99999999,this));
    ui->id_client_2->setValidator(new QIntValidator(0,99999999,this));
    ui->id_client_3->setValidator(new QIntValidator(0,99999999,this));
    ui->id_reservation->setValidator(new QIntValidator(0,99999999,this));
    ui->id_reservation_2->setValidator(new QIntValidator(0,99999999,this));
    ui->nb_personne->setValidator(new QIntValidator(0,99,this));
    ui->nb_personne_2->setValidator(new QIntValidator(0,99,this));
    ui->nb_ecrans_ajout->setValidator(new QIntValidator(0,999,this));
    connect(ui->pushButton_16, SIGNAL(clicked()),this, SLOT(sendMail()));
    QPixmap bkgnd("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/background");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);

}

void MainWindow::on_return_from_ajout_clicked()
{
    QString vide="";
    ui->nm_salle_ajout->setText(vide);
    ui->nb_chaise_ajout->setText(vide);
    ui->nb_baffles_ajout->setText(vide);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_return_from_ajout_2_clicked()
{
    QString vide="";
    ui->nm_salle_modif->setText(vide);
    ui->nb_chaise_modif->setText(vide);
    ui->nb_baffles_modif->setText(vide);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_return_from_ajout_3_clicked()
{
    QString vide="";
    ui->nm_salle_supp->setText(vide);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);

}

void MainWindow::on_pushButton_13_clicked()
{
    QRandomGenerator generator;
    for(int i=0;i<1;++i){
        //  generator.seed();
        int x = Random::get(10000000,20000000);
        QString ra = QString::number(x);
        ui->id_reservation->setText(ra);

    }

    ui->stackedWidget_2->setCurrentIndex(1);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_return_from_ajout_4_clicked()
{
    QString empty="";
    ui->id_client->setText(empty);
    ui->id_reservation->setText(empty);
    ui->nb_personne->setText(empty);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);

}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_return_from_ajout_5_clicked()
{
    QString empty="";
    ui->id_client_2->setText(empty);
    ui->id_reservation_2->setText(empty);
    ui->nb_personne_2->setText(empty);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_return_from_ajout_6_clicked()
{
    QString empty="";
    ui->id_client_3->setText(empty);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Desktop/ROU/qtprojects/Gerer_Salle_Reservation_Roukaia_Khelifi/bouttonsound.mp3"));
    player->play();
    player->setVolume(1000);



}

void MainWindow::on_pushButton_7_clicked()
{

    int num_salle = ui->nm_salle_ajout->text().toInt();
    int nb_baffles =ui->nb_baffles_ajout->text().toInt();
    int nb_chaise=ui->nb_chaise_ajout->text().toInt();
    int nb_ecrans=ui->nb_ecrans_ajout->text().toInt();

   QString dispo = ui->dispo->text();
    Salle s(num_salle,nb_baffles,nb_chaise,nb_ecrans,dispo);
    bool test =s.ajouter();
    if(test){


        ui->tableView->setModel(Etmp.afficher());

        QString  mt="";
        ui->nm_salle_ajout->setText(mt);
        ui->nb_baffles_ajout->setText(mt);
        ui->nb_chaise_ajout->setText(mt);
        ui->nb_ecrans_ajout->setText(mt);
        ui->dispo->setText(mt);
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajouter Effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Ajouter non effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_10_clicked()
{
    int nums = ui->nm_salle_supp->text().toInt();
    bool test= Etmp.supprimer(nums);
    if(test){
        ui->tableView->setModel(Etmp.afficher());
        QString  mt="";
        ui->nm_salle_supp->setText(mt);


        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Supprission Effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Supprission non effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
}


void MainWindow::on_pushButton_8_clicked()
{
    int num_salle = ui->nm_salle_modif->text().toInt();
    int nb_baffles =ui->nb_baffles_modif->text().toInt();
    int nb_chaise=ui->nb_chaise_modif->text().toInt();
    int nb_ecrans=ui->nb_ecrans_modif->text().toInt();
    QString dispo=ui->dispo_2->text();
    Salle s(num_salle,nb_baffles,nb_chaise,nb_ecrans,dispo);
    bool test =s.Update(num_salle);
    if(test){
        ui->tableView->setModel(Etmp.afficher());
        QString  mt="";
        ui->nm_salle_modif->setText(mt);
        ui->nb_baffles_modif->setText(mt);
        ui->nb_chaise_modif->setText(mt);
        ui->nb_ecrans_modif->setText(mt);
        ui->dispo_2->setText(mt);
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Modification Effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Modification non effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->user->text(), ui->pwd->text(), ui->server->text(), ui->port->text().toInt());

    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail(ui->user->text(), "roukaia.khelifi@esprit.tn", ui->subject->text(),"Date De Reservation : "+ui->date_res->text()+"\n"+"Nom Film : "+ui->comboBox->currentText());

}
void MainWindow::on_pushButton_16_clicked()
{
    int id_client = ui->id_client->text().toInt();
    int nb_personne=ui->nb_personne->text().toInt();
    QDate dater= ui->date_res->date();
    QString nomfilm=ui->comboBox->currentText();
    int id_reservation=ui->id_reservation->text().toInt();

    Reservation r(id_client,id_reservation,nb_personne,nomfilm,dater);
    bool test =r.ajouter_res();

    if(test){

        QString m="";
        ui->id_client->setText(m);
        ui->id_reservation->setText(m);
        ui->nb_personne->setText(m);
        ui->rcpt->setText(m);
        ui->comboBox->setCurrentIndex(0);
        dater.currentDate();

        QString s= QString ::number(id_client);
        ui->affichage_reservation->setModel(Etmp1.afficher_res());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajouter Effectuer A QR Code Has been Sent.\n""Click cancel to exit"),QMessageBox::Cancel);



    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Ajouter non effectuer Vous pouvez Verifier l'IDs (Unique).\n""Click cancel to exit"),QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_21_clicked()
{
    int id_client = ui->id_client_3->text().toInt();
    bool test= Etmp1.supprimer_res(id_client);


    if(test){
        QString m="";
        ui->id_client_3->setText(m);

        ui->affichage_reservation->setModel(Etmp1.afficher_res());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Supprission Effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Supprission non effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
}


void MainWindow::on_pushButton_18_clicked()
{
    int id_client=ui->id_client_2->text().toInt();
    int id_reser=ui->id_reservation_2->text().toInt();
    int nb_personne=ui->nb_personne_2->text().toInt();
    QString nomfilm=ui->comboBox_2->currentText();

    QDate dater=ui->date_res_2->date();

    Reservation r(id_client,id_reser,nb_personne,nomfilm,dater);
    bool test = r.update_res(id_client);
    if(test){

        ui->affichage_reservation->setModel(Etmp1.afficher_res());
        QString m="";
        ui->id_client_2->setText(m);
        ui->id_reservation_2->setText(m);
        ui->nb_personne_2->setText(m);
        ui->comboBox_2->setCurrentIndex(0);

        dater.currentDate();
        dater.currentDate();
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Modification Effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Modification non effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
}




void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(Etmp.trier());
}



void MainWindow::on_pushButton_12_clicked()
{
    ui->affichage_reservation->setModel(Etmp1.trier_res());
}

void MainWindow::on_recherche_salle_cursorPositionChanged()
{
    Salle s;

    ui->tableView->setModel(s.rechercher(ui->recherche_salle->text()));
    s.afficher();
}

void MainWindow::on_recherche_reservation_cursorPositionChanged()
{
    Reservation r;
    ui->affichage_reservation->setModel(r.rechercher_res(ui->recherche_reservation->text()));
    r.afficher_res();
}


void MainWindow::on_affichage_reservation_activated(const QModelIndex &index)
{

    QString ch =ui->affichage_reservation->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from reservation where id_client='"+ch+"' ");
    if(query.exec()){

        while(query.next()){
            ui->id_client_2->setText(query.value(0).toString());
            ui->id_reservation_2->setText(query.value(1).toString());
            ui->nb_personne_2->setText(query.value(2).toString());
            ui->comboBox->currentText();
            ui->date_res_2->setDate(query.value(4).toDate());
            ui->id_client_3->setText(query.value(0).toString());

        }
    }
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString ch=ui->tableView->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from salle where numsalle ='"+ch+"'");
    if(query.exec()){
        while(query.next()){
            ui->nm_salle_modif->setText(query.value(0).toString());
            ui->nb_chaise_modif->setText(query.value(1).toString());
            ui->nb_baffles_modif->setText(query.value(2).toString());
            ui->nb_ecrans_modif->setText(query.value(3).toString());
            ui->dispo_2->setText(query.value(4).toString());
            ui->nm_salle_supp->setText(query.value(0).toString());
        }

    }
}
