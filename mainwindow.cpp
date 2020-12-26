#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);


    //*************************************************************************meriem******************************************************
    ui->paiment->setVisible(false);
    ui->label_28->setVisible(false);

    ui->AfficherFilmTable->setModel(tmpF.afficher_film());
    ui->AfficherTicketTable->setModel(empc.afficher_ticket());
    //selection d'une ligne
    ui->AfficherTicketTable->resizeColumnsToContents();
    ui->AfficherTicketTable->resizeRowsToContents();
    ui->AfficherTicketTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->AfficherTicketTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
    ui->AfficherTicketTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    //selection d'une ligne
    ui->AfficherFilmTable->resizeColumnsToContents();
    ui->AfficherFilmTable->resizeRowsToContents();
    ui->AfficherFilmTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->AfficherFilmTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
    ui->AfficherFilmTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //*******************************************************************sinda************************************************************
    ui->tabWidget->setTabText(2,"Statistique");
    ui->AfficherClient->setModel(tmpc.afficher_client());
    Afficher_Client_Table();//fn selection
    ui->AfficherClient2->setModel(tmpc.afficher_client());
    Afficher_Client_Table2();//fn selection

    ui->AfficheCarteFidelite_2->setModel(tmpf.afficher_cartefidelite());
    Afficher_Carte_Table();
    ui->id_client_3->setVisible(false);
    ui->id_carte_2->setVisible(false);
    ui->id_client_2->setVisible(false);
    ui->cin_client_ajouter->setValidator(new QIntValidator(0,99999999,this));
    ui->telephone_ajouter->setValidator(new QIntValidator(0,99999999,this));

    setWindowIcon(QIcon("C:/Users/sinda/Documents/ProjetQT_Image/popcornicon"));
    //annimation
    QPixmap pixel ("C:/Users/sinda/Documents/ProjetQT_Image/popcornicon");
    ui->icon_2->setPixmap(pixel.scaled(200,100,Qt::KeepAspectRatio));
    int w= ui->icon_2->width();
    int h=ui->icon_2->height();

    animation=new QPropertyAnimation(ui->icon_2,"geometry");
    animation->setDuration(1999);
    animation->setStartValue(ui->icon_2->geometry());
    animation->setEndValue(QRect(1180,20,w,h));
    animation->setLoopCount(-1);
    animation->start();


    //matkhalikech tekteb fel carte fidelite
    ui->cin_client_ajouter_2->setEnabled(false);
    ui->nom_ajouter_2->setEnabled(false);
    ui->prenom_ajouter_2->setEnabled(false);
    ui->telephone_ajouter_2->setEnabled(false);
    ui->adresse_ajouter_2->setEnabled(false);
    ui->mail_ajouter_2->setEnabled(false);

    // ************************************************************ROUKAIA***************************************************
    ui->affichage_salle->setModel(Etmp.afficher());
    ui->stackedWidget_3->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->mail_modif->setVisible(false);
    //ui->tabWidget_3->setStyleSheet("background-color:qlineargradient(spread:pad, x1:0.467, y1:0, x2:0.482, y2:1, stop:0 rgb(0,0,0), stop:1 rgb(255, 0, 0)); ; color :white ");
    ui->affichage_reservation->setModel(Etmp1.afficher_res());
    setWindowIcon(QIcon(":/photos/popcorn.png"));

    QPixmap pixel4 (":/photos/logoexcode.png");
    ui->expertCode->setPixmap(pixel4.scaled(200,50,Qt::KeepAspectRatio));

    QPixmap pixel1 (":/photos/popcorn.png");
    ui->Pathe->setPixmap(pixel1.scaled(200,100,Qt::KeepAspectRatio));

    QPixmap pixel2 (":/photos/logoexcode.png");
    ui->expertCode_2->setPixmap(pixel4.scaled(200,50,Qt::KeepAspectRatio));

    QPixmap pixel3 (":/photos/popcorn.png");
    ui->Pathe_2->setPixmap(pixel1.scaled(200,100,Qt::KeepAspectRatio));

    //animation pour logo popcorn
    int w3=ui->Pathe_2->width();
    int h3=ui->Pathe_2->height();

    animation2 = new QPropertyAnimation(ui->Pathe_2,"geometry");
    animation2->setDuration(1999);
    animation2->setStartValue(ui->Pathe_2->geometry());

    animation2->setEndValue(QRect(1100,20,w3,h3));
    animation2->setLoopCount(-1);
    animation2->start();

    //animation pour expert_code
    int w1=ui->expertCode_2->width();
    int h1=ui->expertCode_2->height();

    animation1 = new QPropertyAnimation(ui->expertCode_2,"geometry");
    animation1->setDuration(1999);
    animation1->setStartValue(ui->expertCode_2->geometry());
    animation1->setEndValue(QRect(1100,500,w1,h1));

    animation1->setLoopCount(-1);
    animation1->start();
    //animation pour logo popcorn
    int w0=ui->Pathe->width();
    int h0=ui->Pathe->height();

    animation2 = new QPropertyAnimation(ui->Pathe,"geometry");
    animation2->setDuration(1999);
    animation2->setStartValue(ui->Pathe->geometry());

    animation2->setEndValue(QRect(1100,20,w0,h0));
    animation2->setLoopCount(-1);
    animation2->start();

    //animation pour expert_code
    int w2=ui->expertCode->width();
    int h2=ui->expertCode->height();

    animation1 = new QPropertyAnimation(ui->expertCode,"geometry");
    animation1->setDuration(1999);
    animation1->setStartValue(ui->expertCode->geometry());
    animation1->setEndValue(QRect(1100,500,w2,h2));

    animation1->setLoopCount(-1);
    animation1->start();

    //Controle De saisie

    ui->label_5->setVisible(false);
    ui->label_3->setVisible(false);
    ui->nm_salle_ajout->setValidator(new QIntValidator(0,99,this));
    ui->nm_salle_modif->setValidator(new QIntValidator(0,999,this));
    ui->nm_salle_supp->setValidator(new QIntValidator(0,999,this));
    ui->nb_chaise_ajout->setValidator(new QIntValidator(0,999,this));
    ui->nb_chaise_modif->setValidator(new QIntValidator(0,999,this));
    ui->nb_baffles_ajout->setValidator(new QIntValidator(0,999,this));
    ui->nb_baffles_modif->setValidator(new QIntValidator(0,999,this));
    //  ui->id_client_4->setValidator(new QIntValidator(0,99999999,this));
    ui->id_client_5->setValidator(new QIntValidator(0,99999999,this));
    ui->id_client_6->setValidator(new QIntValidator(0,99999999,this));
    ui->id_reservation->setValidator(new QIntValidator(0,99999999,this));
    ui->id_reservation_2->setValidator(new QIntValidator(0,99999999,this));
    // ui->nb_personne->setValidator(new QIntValidator(0,99,this));
    ui->nb_personne_2->setValidator(new QIntValidator(0,99,this));
    ui->nb_ecrans_ajout->setValidator(new QIntValidator(0,999,this));
    /****************************************Connexion Mailing******************************************/
    connect(ui->ajouter_res, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->ajouter_carte, SIGNAL(clicked()),this, SLOT(sendMail()));

    QPixmap bkgnd(":/photos/backback.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    //selection d'une ligne reservation
    ui->affichage_reservation->resizeColumnsToContents();
    ui->affichage_reservation->resizeRowsToContents();
    ui->affichage_reservation->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->affichage_reservation->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
    ui->affichage_reservation->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    //selection d'une ligne
    ui->affichage_salle->resizeColumnsToContents();
    ui->affichage_salle->resizeRowsToContents();
    ui->affichage_salle->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->affichage_salle->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
    ui->affichage_salle->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);


}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_AjouterClient_2_clicked()
{
    //******************************************************************login**************************************************************
    employe c;
    c.setLogin(ui->lineEdit->text());
    c.setPassword(ui->lineEdit_2->text());
    client cli;
    if (cli.existe_emp(c))
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::information(this,"Erreur","Verifier Votre Adresse ou Mot De Passe ");
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
//*********************************************************************fim ticket**********************************************************
void MainWindow::on_AjouterFilm_clicked()
{
    Film f(ui->id_film->text().toInt(),ui->nom_film->text(),ui->realisateur->text(),
           ui->nationalite->currentText(),ui->date_sortie->date(),ui->disponibilite->date(),
           ui->categorie->currentText());
    f.ajouter_film();

    ui->AfficherFilmTable->setModel(tmpF.afficher_film());

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);
    ui->id_film->setText("");
    ui->nom_film->setText("");
    ui->realisateur->setText("");
    ui->nationalite->setCurrentText("");
    ui->categorie->setCurrentText("");
}


void MainWindow::on_ModifierFilm_clicked()
{
    QString idf=ui->id_film->text();
    Film *tmpCl=new Film();
    tmpCl->setid_film(ui->id_film->text().toInt());
    tmpCl->setnom_film(ui->nom_film->text());
    tmpCl->setrealisateur(ui->realisateur->text());
    tmpCl->setnationalite(ui->nationalite->currentText());
    tmpCl->setdate_sortie(ui->date_sortie->date());
    tmpCl->setdisponibilite(ui->disponibilite->date());
    tmpCl->setcategories(ui->categorie->currentText());




    QString str = " Vous voulez vraiment modifier le film ayant le id :"+ ui->id_film->text();
    int ret = QMessageBox::question(this, tr("modification"),str,QMessageBox::Ok|QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Ok:

        //  tmpCl->setid_film(ui->id_film->text().toInt());

        if (tmpCl->modifier_film()){

            ui->AfficherFilmTable->setModel(tmpF.afficher_film());
            ui->id_film->setText("");
            ui->nom_film->setText("");
            ui->realisateur->setText("");
            ui->nationalite->setCurrentText("");
            ui->categorie->setCurrentText("");

            //Afficher_Film_Table();

        }break;
    case QMessageBox::Cancel:

        break;
    default:
        // should never be reached
        break;
    }
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_SupprimerFilm_clicked()
{
    QItemSelectionModel *select=ui->AfficherFilmTable->selectionModel();
    QString idd=select->selectedRows(0).value(0).data().toString();
    Film *tmpCl=new Film();

    QString str = " Vous voulez vraiment supprimer \n le film  ayant le id :"+ ui->id_film->text();
    int ret = QMessageBox::question(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Ok:

        tmpCl->setid_film(ui->id_film->text().toInt());
        if (tmpCl->supprimer_film()){

            ui->AfficherFilmTable->setModel(tmpF.afficher_film());
        }break;
    case QMessageBox::Cancel:

        break;
    default:
        // should never be reached
        break;
    }
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);
    ui->id_film->setText("");
    ui->nom_film->setText("");
    ui->realisateur->setText("");
    ui->nationalite->setCurrentText("");
    ui->categorie->setCurrentText("");

}

void MainWindow::on_refresh_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);

    ui->id_film->setText("");
    ui->nom_film->setText("");
    ui->realisateur->setText("");
    ui->nationalite->setCurrentText("");
    ui->categorie->setCurrentText("");
}

void MainWindow::on_recherche_cursorPositionChanged()
{
    Film f;
    ui->AfficherFilmTable->setModel(f.rechercher_film(ui->recherche->text()));
    f.afficher_film();

}

void MainWindow::on_radioButton_clicked()
{
    ui->AfficherFilmTable->setModel(tmpF.trier_film());

}

void MainWindow::on_radioButton_2_clicked()
{
    ui->AfficherFilmTable->setModel(tmpF.trier_film_r());
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->AfficherFilmTable->setModel(tmpF.trier_film_n());
}

void MainWindow::on_radioButton_4_clicked()
{
    ui->AfficherFilmTable->setModel(tmpF.trier_film_c());
}

void MainWindow::on_Close_2_clicked()
{
    close();
}

void MainWindow::on_returnF_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ajouterTicket_clicked()
{
    Ticket t(ui->id_ticket->text().toInt(),ui->Id_film_ticket->text(),ui->prix_ticket->text().toInt(),
             ui->salles->currentText(),ui->paiment->currentText(),ui->nomfilm->text(),ui->id_client->text().toInt());
    t.ajouter_ticket();
    ui->AfficherTicketTable->setModel(empc.afficher_ticket());

    //carte_fidelite cf(ui->id_carte->text().toInt(),0,0,0);

    //cf.modifier_cartefidelite();//FC MODIFIER

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000) ;
}

void MainWindow::on_ModifierTicket_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);

    QString idt=ui->Id_film_ticket->text();
    Ticket *tmpTi=new Ticket();
    tmpTi->setid_ticket(ui->id_ticket->text().toInt());
    tmpTi->setid_film(ui->Id_film_ticket->text());
    tmpTi->setprix(ui->prix_ticket->text().toInt());
    tmpTi->setsalle(ui->salles->currentText());
    tmpTi->settype_paiment(ui->paiment->currentText());

    tmpTi->setnom_film(ui->nomfilm->text());
    tmpTi->setid_client(ui->id_client->text().toInt());


    QString str = " Vous voulez vraiment modifier le ticket ayant le id :"+ ui->id_ticket->text();
    int ret = QMessageBox::question(this, tr("modification"),str,QMessageBox::Ok|QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Ok:

        if (tmpTi->modifier_ticket()){


            ui->AfficherTicketTable->setModel(empc.afficher_ticket());


        }break;
    case QMessageBox::Cancel:

        break;
    default:
        // should never be reached
        break;
    }
    ui->id_ticket->setText("");
    ui->Id_film_ticket->setText("");
    ui->prix_ticket->setText("");
    ui->salles->setCurrentText("");
    ui->paiment->setCurrentText("");
    ui->nomfilm->setText("");
    ui->id_client->setText("");
}

void MainWindow::on_SupprimerTicket_clicked()
{
    QItemSelectionModel *select=ui->AfficherTicketTable->selectionModel();
    QString idd=select->selectedRows(0).value(0).data().toString();
    Ticket *tmpCl=new Ticket();

    QString str = " Vous voulez vraiment supprimer \n ticket  ayant le id :"+ ui->id_ticket->text();
    int ret = QMessageBox::question(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Ok:

        tmpCl->setid_ticket(ui->id_ticket->text().toInt());
        if (tmpCl->supprimer_ticket()){

            ui->AfficherTicketTable->setModel(empc.afficher_ticket());
        }break;
    case QMessageBox::Cancel:

        break;
    default:
        // should never be reached
        break;
    }
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);
}

void MainWindow::on_refreshT_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);

    ui->id_ticket->setText("");
    ui->Id_film_ticket->setText("");
    ui->prix_ticket->setText("");
    ui->salles->setCurrentText("");
    ui->paiment->setCurrentText("");
    ui->nomfilm->setText("");
    ui->id_client->setText("");
}

void MainWindow::on_recherchecase_2_cursorPositionChanged()
{
    Ticket t;
    ui->AfficherTicketTable->setModel(t.rechercher_ticket(ui->recherche->text()));
    t.afficher_ticket();

}

void MainWindow::on_Close_ticket_clicked()
{
    close();
}


void MainWindow::on_returnTick_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Close_ticket_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_AfficherFilmTable_activated(const QModelIndex &index)
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);

    QString ch=ui->AfficherFilmTable->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from film where id_film ='"+ch+"'");
    if(query.exec()){
        while(query.next()){

            ui->id_film->setText(query.value(0).toString());
            ui->nom_film->setText(query.value(1).toString());
            ui->realisateur->setText(query.value(2).toString());
            ui->nationalite->setCurrentText(query.value(3).toString());
            ui->date_sortie->setDate(query.value(4).toDate());
            ui->disponibilite->setDate(query.value(5).toDate());
            ui->categorie->setCurrentText(query.value(6).toString());

        }
    }
}

void MainWindow::on_AfficherTicketTable_activated(const QModelIndex &index)
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);

    QString ch=ui->AfficherTicketTable->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from ticket where id_ticket ='"+ch+"'");
    if(query.exec()){
        while(query.next()){

            ui->id_ticket->setText(query.value(0).toString());
            ui->Id_film_ticket->setText(query.value(1).toString());
            ui->prix_ticket->setText(query.value(2).toString());
            ui->salles->setCurrentText(query.value(3).toString());
            ui->paiment->setCurrentText(query.value(4).toString());
            ui->nomfilm->setText(query.value(6).toString());
            ui->id_client->setText(query.value(7).toString());

        }
    }
}

//**********************************************************************client carte****************************************************************

//selection de toute une ligne tab client
void MainWindow::Afficher_Client_Table(){
    ui->AfficherClient->resizeColumnsToContents();
    ui->AfficherClient->resizeRowsToContents();
    ui->AfficherClient->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->AfficherClient->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
    ui->AfficherClient->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}
//selection de toute une ligne tab carte
void MainWindow::Afficher_Carte_Table(){
    ui->AfficheCarteFidelite_2->resizeColumnsToContents();
    ui->AfficheCarteFidelite_2->resizeRowsToContents();
    ui->AfficheCarteFidelite_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ui->AfficheCarteFidelite_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
    ui->AfficheCarteFidelite_2->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}
//selection de toute une ligne tab client 2
void MainWindow::Afficher_Client_Table2(){
    ui->AfficherClient2->resizeColumnsToContents();
    ui->AfficherClient2->resizeRowsToContents();
    ui->AfficherClient2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->AfficherClient2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed,QHeaderView::Stretch);
    ui->AfficherClient2->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void MainWindow::refraiche()
{
    ui->id_client_2->setText("");
    ui->cin_client_ajouter->setText("");
    ui->genre_ajouter->setCurrentIndex(0);
    ui->nom_ajouter->setText("");
    ui->prenom_ajouter->setText("");
    ui->etatcivil_ajouter->setCurrentIndex(0);
    ui->telephone_ajouter->setText("");
    ui->mail_ajouter->setText("");
    ui->fontion_ajouter->setCurrentIndex(0);
    ui->adresse_ajouter->setText("");
    ui->id_client_3->setText("");
    ui->cin_client_ajouter_2->setText("");
    ui->nom_ajouter_2->setText("");
    ui->prenom_ajouter_2->setText("");
    ui->telephone_ajouter_2->setText("");
    ui->adresse_ajouter_2->setText("");
    ui->mail_ajouter_2->setText("");
    ui->AfficherClient->setModel(tmpc.afficher_client());
    ui->AfficheCarteFidelite_2->setModel(tmpf.afficher_cartefidelite());
    ui->AfficherClient2->setModel(tmpc.afficher_client());
    Afficher_Client_Table();
    Afficher_Client_Table2();
    Afficher_Carte_Table();
    ui->id_client_2->setText("");
    ui->id_carte_2->setText("");
    ui->id_client_3->setText("");
}
void MainWindow::on_ajouterClient_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);

    client c(ui->cin_client_ajouter->text().toInt(),ui->nom_ajouter->text(),ui->prenom_ajouter->text(),ui->dateNaissance_ajouter->date(),
             ui->telephone_ajouter->text().toInt(),ui->fontion_ajouter->currentText(),ui->adresse_ajouter->text()
             ,QDate::currentDate(),ui->mail_ajouter->text(),ui->genre_ajouter->currentText(),ui->etatcivil_ajouter->currentText());

    if (c.controle_saisie() == "")
    {

        QString str = " Vous voulez vraiment ajouter ce client:" ;
        int ret = QMessageBox::question(this, tr("ajout"),str,QMessageBox::Ok|QMessageBox::Cancel);

        switch (ret) {
        case QMessageBox::Ok:
        { if(c.getCin()==0 )//SI ELEVE
            {
                if(! c.existe_client_tel() )
                {     c.ajouter_client();
                    ui->AfficherClient->setModel(tmpc.afficher_client());
                    refraiche();
                }
                else
                {
                    QMessageBox::critical(this,tr("erreure")," num tel existe !!");
                }

            }
            else//mehouch eleve
            {
                if (! c.existe_client_cin() && ! c.existe_client_tel() )
                {
                    c.ajouter_client();
                    ui->AfficherClient->setModel(tmpc.afficher_client());
                    refraiche();
                }
                else
                {
                    QMessageBox::critical(this,"/n erreure","/n cin exite ou num tel existe !!");
                }
            }
        }
            break;
        case QMessageBox::Cancel:

            break;
        default:
            // should never be reached
            break;

        }}
    else {
        QMessageBox::critical(this,"erreure",c.controle_saisie());
    }

}

void MainWindow::on_modifierClient_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);
    QString idd=ui->id_client_2->text();
    client *tmpCl=new client();
    tmpCl->setId(ui->id_client_2->text().toInt());
    tmpCl->setCin(ui->cin_client_ajouter->text().toInt());
    tmpCl->setNom(ui->nom_ajouter->text());
    tmpCl->setPrenom(ui->prenom_ajouter->text());
    tmpCl->setDate_naissance(ui->dateNaissance_ajouter->date());
    tmpCl->setNumTel(ui->telephone_ajouter->text().toInt());
    tmpCl->setFonction(ui->fontion_ajouter->currentText());
    tmpCl->setAdresse(ui->adresse_ajouter->text());
    tmpCl->setMail_client(ui->mail_ajouter->text());
    tmpCl->setGenre(ui->genre_ajouter->currentText());
    tmpCl->setEtat_civil(ui->etatcivil_ajouter->currentText());
    if (idd=="")
    { QMessageBox::information(this,"non existe"," id not selected");}
    else
    {if (tmpCl->controle_saisie() == "")//pas de message
        {
            QString str = " Vous voulez vraiment modifier le client ayant le id :"+ ui->id_client->text();
            int ret = QMessageBox::question(this, tr("modification"),str,QMessageBox::Ok|QMessageBox::Cancel);
            switch (ret) {
            case QMessageBox::Ok:

                if (tmpCl->modifier_client()){

                    ui->AfficherClient->setModel(tmpc.afficher_client());
                    Afficher_Client_Table();
                    refraiche();
                }break;
            case QMessageBox::Cancel:

                break;
            default:
                // should never be reached
                break;
            }
        }
        else
        {
            QMessageBox::information(this,"erreure",tmpCl->controle_saisie());
        }

    }
}
//tab to input
void MainWindow::on_AfficherClient_activated()
{
    QString l=ui->AfficherClient->selectionModel()->selectedIndexes().at(0).data().toString();
    ui->id_client_2->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(1).data().toString();
    ui->cin_client_ajouter->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(2).data().toString();
    ui->nom_ajouter->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(3).data().toString();
    ui->prenom_ajouter->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(4).data().toString();
    //ui->dateNaissance->setDate(l);//->setDate("dd-mm-yyyy");

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(5).data().toString();
    ui->telephone_ajouter->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(6).data().toString();
    if(l=="Eleve")
    {ui->fontion_ajouter->setCurrentIndex(1);}
    else
    {  if(l=="Etudiant(e)")
            ui->fontion_ajouter->setCurrentIndex(2);
        else
        {  if(l=="Employe(e)")
                ui->fontion_ajouter->setCurrentIndex(3);
            else
            {  if(l=="Retraite(e)")
                    ui->fontion_ajouter->setCurrentIndex(4);
                else
                {  if(l=="Chomeur(e)")
                        ui->fontion_ajouter->setCurrentIndex(5);
                }}}}

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(7).data().toString();
    ui->adresse_ajouter->setText(l);

    //l=ui->AfficherClientTable->selectionModel()->selectedIndexes().at(8).data().toString();
    //ui->datecreation->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(9).data().toString();
    ui->mail_ajouter->setText(l);

    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(10).data().toString();
    if(l=="Femme")
    {ui->genre_ajouter->setCurrentIndex(1);}
    else
    {  if(l=="Homme")
            ui->genre_ajouter->setCurrentIndex(2); }


    l=ui->AfficherClient->selectionModel()->selectedIndexes().at(11).data().toString();
    if(l=="Marie(e)")
    {ui->etatcivil_ajouter->setCurrentIndex(2);}
    else
    {  if(l=="Celibataire")
            ui->etatcivil_ajouter->setCurrentIndex(1); }
}

void MainWindow::on_SupprimerClient_clicked()
{
    //sound
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);

    QString idd=ui->id_client_2->text();
    client *tmpCl=new client();
    if (idd=="")
    { QMessageBox::information(this,"non existe","id n'existe pas");}
    else
    {
        QString str = " Vous voulez vraiment supprimer \n l client ayant le id :"+ ui->id_client_2->text();
        int ret = QMessageBox::question(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Ok:

            tmpCl->setId(ui->id_client->text().toInt());
            if (tmpCl->supprimer_client()){

                ui->AfficherClient->setModel(tmpc.afficher_client());
                Afficher_Client_Table();
                refraiche();
            }break;
        case QMessageBox::Cancel:

            break;
        default:
            // should never be reached
            break;
        }
    }
}

void MainWindow::on_ajouter_carte_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);


    Smtp* smtp = new Smtp("sindachamakh27@gmail.com", "27Novembre", ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail("sindachamakh27@gmail.com",ui->mail_ajouter_2->text(), "Smart_Cinema","Carte Fidilite Cree Pour L'utilisateur Identifier Par : "+ui->cin_client_ajouter_2->text());

    QString idd=ui->id_client_3->text();

    if (idd=="")
    { QMessageBox::information(this,"non existe","selectionner un client");}
    else{
        carte_fidelite c(ui->id_client_3->text().toInt(),QDate::currentDate(),100,0);

        QString str = " Vous voulez vraiment ajouter cette carte fidelite:" ;
        int ret = QMessageBox::question(this, tr("Ajout"),str,QMessageBox::Ok|QMessageBox::Cancel);

        switch (ret) {
        case QMessageBox::Ok:
        {
            if(! c.existe_carte() )
            {    c.ajouter_cartefidelite();
                ui->AfficheCarteFidelite_2->setModel(tmpf.afficher_cartefidelite());
                refraiche();
            }
            else
            {
                QMessageBox::critical(this,tr("erreur")," carte fidelite existe !!");
            }

        }
            break;
        case QMessageBox::Cancel:

            break;
        default:
            // should never be reached
            break;

        }
    }
}

void MainWindow::on_filtrerClient_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);

    if ((ui->genre_filtre->currentText() == "") && (ui->fonction_filtre->currentText() == "") && (ui->Etat_civil_filtre->currentText() == ""))
    {
        QMessageBox::information(this,"erreur"," aucun champs a filtrer");

    }
    else
    {
        client v;
        ui->AfficherClient->setModel(v.filtre(ui->genre_filtre->currentText(),ui->fonction_filtre->currentText(),ui->Etat_civil_filtre->currentText()));
        Afficher_Client_Table();
    }
}

void MainWindow::on_recherchecase_3_cursorPositionChanged()
{
    client v;
    ui->AfficherClient->setModel(v.rechercher_existe(ui->recherchecase_3->text()));
    Afficher_Client_Table();
}

void MainWindow::on_refresh_2_clicked()
{
    refraiche();
}

void MainWindow::on_closeClient_clicked()
{
    close();
}

void MainWindow::on_SupprimerCarte_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);

    QString idd=ui->id_carte_2->text();
    carte_fidelite *tmpcf=new carte_fidelite();
    if (idd=="")
    { QMessageBox::information(this,"non existe","id n'existe pas");}
    else
    {
        QString str = " Vous voulez vraiment supprimer \n l carte ayant le id :"+ ui->id_carte_2->text();
        int ret = QMessageBox::question(this, tr("suppression"),str,QMessageBox::Ok|QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Ok:

            tmpcf->setId_client(ui->id_client_3->text().toInt());
            if (tmpcf->supprimer_cartefidelite_id_client())
            {
                ui->AfficheCarteFidelite_2->setModel(tmpf.afficher_cartefidelite());
                Afficher_Carte_Table();
                refraiche();
            }break;
        case QMessageBox::Cancel:

            break;
        default:
            // should never be reached
            break;
        }
    }
}

void MainWindow::on_modifier_carte_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("D:/Techargement/mouse.mp3"));
    player->play();
    player->setVolume(1000);

    QString idd=ui->id_client_3->text();

    if (idd=="")
    { QMessageBox::information(this,"non existe","selectionner le client");}
    else{
        carte_fidelite cf(ui->id_carte_2->text().toInt(),ui->id_client_3->text().toInt(),0,0);

        QString str = " Vous voulez vraiment ajouter des points " ;
        int ret = QMessageBox::question(this, tr("enregistrement"),str,QMessageBox::Ok|QMessageBox::Cancel);

        switch (ret) {
        case QMessageBox::Ok:
        {
            cf.modifier_cartefidelite();
            ui->AfficheCarteFidelite_2->setModel(tmpf.afficher_cartefidelite());
            refraiche();
        }
            break;
        case QMessageBox::Cancel:

            break;
        default:
            // should never be reached
            break;

        }
    }

}

void MainWindow::on_refrech2_clicked()
{
    refraiche();
}

void MainWindow::on_AfficheCarteFidelite_2_activated()
{
    QString l=ui->AfficheCarteFidelite_2->selectionModel()->selectedIndexes().at(0).data().toString();
    ui->id_carte_2->setText(l);
    l=ui->AfficheCarteFidelite_2->selectionModel()->selectedIndexes().at(1).data().toString();
    ui->id_client_3->setText(l);

}

void MainWindow::on_AfficherClient2_activated()
{
    QString l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(0).data().toString();
    ui->id_client_3->setText(l);

    l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(1).data().toString();
    ui->cin_client_ajouter_2->setText(l);

    l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(2).data().toString();
    ui->nom_ajouter_2->setText(l);

    l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(3).data().toString();
    ui->prenom_ajouter_2->setText(l);

    l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(5).data().toString();
    ui->telephone_ajouter_2->setText(l);



    l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(7).data().toString();
    ui->adresse_ajouter_2->setText(l);

    l=ui->AfficherClient2->selectionModel()->selectedIndexes().at(9).data().toString();
    ui->mail_ajouter_2->setText(l);

}

void MainWindow::on_recherchecase_4_cursorPositionChanged()
{
    client v;
    ui->AfficherClient2->setModel(v.rechercher_existe(ui->recherchecase_4->text()));
    Afficher_Client_Table2();
}

void MainWindow::on_recherchecase_5_cursorPositionChanged()
{
    carte_fidelite v;
    ui->AfficheCarteFidelite_2->setModel(v.rechercher_existe(ui->recherchecase_5->text()));
    Afficher_Carte_Table();
}

void MainWindow::on_close_2_clicked()
{
    close();
}

void MainWindow::on_return_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_return_ticket_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Return2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_triperso_2_clicked()
{
    ui->AfficherClient->setModel(tmpc.trier_personaliser_client(ui->colonnetrie_2->currentText()));
    Afficher_Client_Table();//fn selection

}

void MainWindow::on_trier_clicked()
{
    carte_fidelite v;
    ui->AfficheCarteFidelite_2->setModel(v.trier_cartefidelite());
    Afficher_Carte_Table();
}

void MainWindow::on_triperso_clicked()
{

    carte_fidelite v;
    ui->AfficheCarteFidelite_2->setModel(v.trier_personaliser_cartefidelite(ui->colonnetrie->currentText()));
    Afficher_Carte_Table();
}

void MainWindow::on_trier_client_clicked()
{
    ui->AfficherClient->setModel(tmpc.trier_client());
    Afficher_Client_Table();//fn selection
}

void MainWindow::on_triperso_3_clicked()
{

    int tri=0;

    //****** 1 + 2
    if( ui->checkBox->isChecked() && ui->checkBox_2->isChecked())
        tri=3;
    //****** 1 + 3
    if( ui->checkBox->isChecked() && ui->checkBox_3->isChecked())
        tri=5;
    //****** 2 + 3
    if(ui->checkBox_2->isChecked() && ui->checkBox_3->isChecked())
        tri=6;
    //****** 1 + 2 + 3
    if( ui->checkBox->isChecked() && ui->checkBox_3->isChecked() && ui->checkBox_2->isChecked())
        tri=7;
    if( ui->checkBox->isChecked())
        tri=1;
    if(ui->checkBox_2->isChecked())
        tri=2;
    if(ui->checkBox_3->isChecked())
        tri=4;


    carte_fidelite v;
    ui->AfficheCarteFidelite_2->setModel(v.trier_personaliser_cartefidelite_multiple(tri,"all"));
    Afficher_Carte_Table();


}

//***********************************************************************salle reservation****************************************************************************


void MainWindow::on_pushButton_3_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);

    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_8_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_9_clicked()

{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_10_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    QString idd=ui->nm_salle_supp->text();
    Salle *Etmp=new Salle();
    if (idd=="")
    { QMessageBox::information(this,"Erreur","Numero de Salle n'est pas Selectioné");}
    else
    {
        QString str = " Vous voulez vraiment supprimer Salle \n ayant le Numero:"+ ui->nm_salle_supp->text();
        int ret = QMessageBox::question(this, tr("Suppression"),str,QMessageBox::Yes|QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Yes:
            int x = ui->nm_salle_supp->text().toInt();
            if (Etmp->supprimer(x))
            {
                ui->affichage_salle->setModel(Etmp->afficher());
            }
            break;


        }
    }
}

void MainWindow::on_pushButton_14_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    int num_salle = ui->nm_salle_ajout->text().toInt();
    int nb_baffles =ui->nb_baffles_ajout->text().toInt();
    int nb_chaise=ui->nb_chaise_ajout->text().toInt();
    int nb_ecrans=ui->nb_ecrans_ajout->text().toInt();
    Salle s;
    QString d= s.get_dispo();
    if(num_salle==0||nb_baffles==0||nb_chaise==0||nb_ecrans==0){
        QMessageBox::critical(nullptr,QObject::tr("Champs Vide !"),
                              QObject::tr("Ajouter non effectuer Veillez Remplir Les Champs.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
    else{
        Salle s(num_salle,nb_baffles,nb_chaise,nb_ecrans,d);
        bool test =s.ajouter();
        if(test){


            ui->affichage_salle->setModel(Etmp.afficher());

            QString  mt="";
            ui->nm_salle_ajout->setText(mt);
            ui->nb_baffles_ajout->setText(mt);
            ui->nb_chaise_ajout->setText(mt);
            ui->nb_ecrans_ajout->setText(mt);
            ui->stackedWidget_2->setCurrentIndex(0);
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Ajouter Effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                  QObject::tr("Ajouter non effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

        }
    }
}
void MainWindow::on_pushButton_13_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_return_from_ajout_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    QString vide="";
    ui->nm_salle_ajout->setText(vide);
    ui->nb_chaise_ajout->setText(vide);
    ui->nb_baffles_ajout->setText(vide);
}

void MainWindow::on_pushButton_15_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    int num_salle = ui->nm_salle_modif->text().toInt();
    int nb_baffles =ui->nb_baffles_modif->text().toInt();
    int nb_chaise=ui->nb_chaise_modif->text().toInt();
    int nb_ecrans=ui->nb_ecrans_modif->text().toInt();
    QString dispo;
    Ticket t;
    Salle s;
    if(t.somme_ticket(num_salle)>=nb_chaise){
        s.disponibilite()="Salle Pas Disponible";
        dispo = s.disponibilite();
    }
    else dispo = s.get_dispo();

    if(num_salle==0||nb_baffles==0||nb_chaise==0||nb_ecrans==0){

        QMessageBox::critical(nullptr,QObject::tr("Champs Vide !"),
                              QObject::tr("Modification non effectuer veillez Remplir Les champs.\n""Click cancel to exit"),QMessageBox::Cancel);

    }
    else {

        Salle s(num_salle,nb_baffles,nb_chaise,nb_ecrans,dispo);
        bool test =s.Update(num_salle);
        if(test){
            ui->affichage_salle->setModel(Etmp.afficher());
            QString  mt="";
            ui->nm_salle_modif->setText(mt);
            ui->nb_baffles_modif->setText(mt);
            ui->nb_chaise_modif->setText(mt);
            ui->nb_ecrans_modif->setText(mt);

            ui->stackedWidget_2->setCurrentIndex(0);
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Modification Effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                  QObject::tr("Modification non effectuer Veillez Verifier Les Champs.\n""Click cancel to exit"),QMessageBox::Cancel);

        }
    }
}
void MainWindow::on_pushButton_16_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_return_from_ajout_2_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    QString vide="";
    ui->nm_salle_modif->setText(vide);
    ui->nb_chaise_modif->setText(vide);
    ui->nb_baffles_modif->setText(vide);
}

void MainWindow::on_pushButton_17_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    int nums = ui->nm_salle_supp->text().toInt();
    bool test= Etmp.supprimer(nums);
    if(test){
        ui->affichage_salle->setModel(Etmp.afficher());
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

void MainWindow::on_pushButton_18_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_return_from_ajout_3_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    QString vide="";
    ui->nm_salle_supp->setText(vide);

}

void MainWindow::on_pushButton_12_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->affichage_salle->setModel(Etmp.trier());
}

void MainWindow::on_affichage_salle_activated(const QModelIndex &index)
{
    QString ch=ui->affichage_salle->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select numsalle,nbbaffles,dispo,nbchaise,nbecrans from salle where numsalle ='"+ch+"'");
    if(query.exec()){
        while(query.next()){
            ui->nm_salle_modif->setText(query.value(0).toString());
            ui->nb_chaise_modif->setText(query.value(1).toString());
            ui->nb_baffles_modif->setText(query.value(2).toString());
            ui->nb_ecrans_modif->setText(query.value(3).toString());

            ui->nm_salle_supp->setText(query.value(0).toString());
        }

    }
}

void MainWindow::on_recherche_salle_cursorPositionChanged()
{

    Salle s;

    ui->affichage_salle->setModel(s.rechercher(ui->recherche_salle->text()));
    s.afficher();
}

void MainWindow::on_recherche_reservation_cursorPositionChanged()
{
    Reservation r;
    ui->affichage_reservation->setModel(r.rechercher_res(ui->recherche_reservation->text()));
    r.afficher_res();
}

void MainWindow::on_pushButton_20_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget_3->setCurrentIndex(1);
    ui->id_reservation->setText(id_Reser);
}

void MainWindow::on_pushButton_21_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget_3->setCurrentIndex(2);
}

void MainWindow::on_pushButton_22_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    QString idd=ui->id_client_6->text();
    Reservation *Etmp1=new Reservation();
    if (idd=="")
    { QMessageBox::information(this,"non existe","id n'existe pas");}
    else
    {
        QString str = " Vous voulez vraiment supprimer Reservation \n ayant le id de client :"+ ui->id_client_6->text();
        int ret = QMessageBox::question(this, tr("Suppression"),str,QMessageBox::Yes|QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Yes:
            int x = ui->id_client_6->text().toInt();
            if (Etmp1->supprimer_res(x))
            {
                ui->affichage_reservation->setModel(Etmp1->afficher_res());
            }
            break;


        }
    }
}
void MainWindow::on_pushButton_19_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->affichage_reservation->setModel(Etmp1.trier_res());
}


void MainWindow::on_pushButton_25_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_return_from_ajout_4_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    QString empty="";
    ui->id_client_4->setText(empty);
    //ui->id_reservation->setText(empty);
    ui->nb_personne->setText(empty);

}

void MainWindow::on_pushButton_27_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_return_from_ajout_5_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    QString empty="";
    ui->id_client_5->setText(empty);
    ui->id_reservation_2->setText(empty);
    ui->nb_personne_2->setText(empty);
    //  ui->test->setText(empty);
}


void MainWindow::on_pushButton_29_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    int id_client = ui->id_client_6->text().toInt();
    bool test= Etmp1.supprimer_res(id_client);
    if(test){
        QString m="";
        ui->id_client_6->setText(m);

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

void MainWindow::on_return_from_ajout_6_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    QString empty="";
    ui->id_client_3->setText(empty);
}

void MainWindow::on_pushButton_28_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_affichage_reservation_activated(const QModelIndex &index)
{

    QString ch =ui->affichage_reservation->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from reservation where id_client='"+ch+"' ");
    if(query.exec()){

        while(query.next()){
            ui->id_client_5->setText(query.value(0).toString());
            ui->id_reservation_2->setText(query.value(1).toString());
            ui->nb_personne_2->setText(query.value(2).toString());
            ui->comboBox_2->setCurrentText(query.value(3).toString());
            ui->date_res_2->setDate(query.value(4).toDate());
            ui->id_client_6->setText(query.value(0).toString());
            ui->mail_modif->setText(query.value(5).toString());

        }
    }
}



void MainWindow::on_pushButton_23_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_32_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_31_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_33_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_34_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ajouter_res_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    Smtp* smtp = new Smtp("roukaia70@gmail.com","sousourourou9899@", ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    QString msg ="Votre Identifiant est : "+ui->id_client_4->text()+"\n"+"Date De Reservation : "+ui->date_res->text()+"\n"+"ID Reservation : "+id_Reser+"\n"+"Nom Film : "+ui->comboBox->currentText()+"\n"+"Nombre De Personne :"+ui->nb_personne->text()+"\n\n"+"Merci de venir avant 15minutes pour confirmer votre réservation en utilisant nos serrures electrique et n'oubliez pas vos masques"+"\n\n"+"Pathé.";
    smtp->sendMail("roukaia70@gmail.com", ui->mail_reservation->text(), "Reservation Confirmé",msg);

    int id_client = ui->id_client_4->text().toInt();
    int nb_personne=ui->nb_personne->text().toInt();
    QDate dater= ui->date_res->date();
    QString nomfilm=ui->comboBox->currentText();

    QString id_reservation =id_Reser;
    QString mail=ui->mail_reservation->text();
    if(id_client==0||nb_personne==0||nomfilm==""||mail==""){

        QMessageBox::critical(nullptr,QObject::tr("Champs Vide ! "),
                              QObject::tr("Ajouter non effectuer Veillez Remplir Les champs.\n""Click cancel to exit"),QMessageBox::Cancel);

    }else{
        Reservation r(id_client,id_reservation,nb_personne,nomfilm,dater,ui->mail_reservation->text());

        bool test =r.ajouter_res();
        if(test){

            QString m="";
            ui->id_client_4->setText(m);
            ui->id_reservation->setText(m);
            ui->nb_personne->setText(m);
            ui->mail_reservation->setText(m);
            ui->comboBox->setCurrentIndex(0);
            dater.currentDate();
            ui->stackedWidget_3->setCurrentIndex(0);
            ui->affichage_reservation->setModel(Etmp1.afficher_res());

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Ajouter Effectuer The ID Reservation Has been Sent.\n""Click cancel to exit"),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                  QObject::tr("Ajouter non effectuer Vous pouvez Verifier les Champs.\n""Click cancel to exit"),QMessageBox::Cancel);

        }
    }
}




void MainWindow::on_pushButton_24_clicked()
{
    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_modif_res_clicked()
{

    Smtp* smtp = new Smtp("roukaia70@gmail.com","sousourourou9899@", ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    QString msg ="Votre Identifiant est : "+ui->id_client_5->text()+"\n"+"Date De Reservation : "+ui->date_res_2->text()+"\n"+"ID Reservation : "+id_Reser+"\n"+"Nom Film : "+ui->comboBox_2->currentText()+"\n"+"Nombre De Personne :"+ui->nb_personne_2->text()+"\n"+"\n"+"Merci de venir avant 15minutes pour confirmer votre réservation en utilisant nos serrures electrique et n'oubliez pas vos masques"+"\n\n"+"Pathé.";

    smtp->sendMail("roukaia70@gmail.com", ui->mail_modif->text(), "Reservation Modifié",msg);

    QMediaPlayer *player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/khelifi/Documents/projet/Bouttons/Pop.mp3"));
    player->play();
    player->setVolume(1000);
    int id_client = ui->id_client_5->text().toInt();
    int nb_personne=ui->nb_personne_2->text().toInt();
    QDate dater= ui->date_res_2->date();
    QString nomfilm=ui->comboBox_2->currentText();


    QString id_reservation =id_Reser;
    if(id_client==0||nb_personne==0||nomfilm==""){
        QMessageBox::critical(nullptr,QObject::tr("Champs Vide!"),
                              QObject::tr("Modification non effectuer Veillez Remplir Les champs.\n""Click cancel to exit"),QMessageBox::Cancel);

    }else{
        Reservation r(id_client,id_reservation,nb_personne,nomfilm,dater,ui->mail_reservation->text());
        bool test = r.update_res(id_client);
        if(test){

            ui->affichage_reservation->setModel(Etmp1.afficher_res());
            QString m="";
            ui->id_client_5->setText(m);
            ui->id_reservation_2->setText(m);
            ui->nb_personne_2->setText(m);
            ui->comboBox_2->setCurrentIndex(0);


            dater.currentDate();
            ui->stackedWidget_3->setCurrentIndex(0);
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Modification Effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                  QObject::tr("Modification non effectuer.\n""Click cancel to exit"),QMessageBox::Cancel);

        }
    }
}



void MainWindow::on_id_client_4_textChanged()
{
    Reservation r;
    if(!r.verif(ui->id_client_4->text())){
        ui->label_3->setVisible(true);
    }
    else{
        ui->label_3->setVisible(false);


    }
}

void MainWindow::on_nb_personne_textChanged()
{
    Reservation r;
    if(!r.verif(ui->nb_personne->text())){
        ui->label_5->setVisible(true);
    }
    else{
        ui->label_5->setVisible(false);


    }
}

