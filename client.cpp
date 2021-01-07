#include "client.h"
#include "carte_fidelite.h"
#include "employe.h"
bool client:: ajouter_client( )
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (ID_CLIENT,CIN,NOM,PRENOM,NUM_TEL,ADRESSE,MAIL_CLIENT,FONCTION,GENRE,ETAT_CIVILE,DATE_CREATION,DATE_NAISSANCE)"
                   "VALUES (ID_CLIENT.nextval,:CIN,:NOM,:PRENOM,:NUM_TEL,:ADRESSE,:MAIL_CLIENT,:FONCTION,:GENRE,:ETAT_CIVILE,:DATE_CREATION,:DATE_NAISSANCE)");
    query.bindValue(":CIN",this->getCin());
    query.bindValue(":NOM",this->getNom());
    query.bindValue(":PRENOM",this->getPrenom());
    query.bindValue(":NUM_TEL",this->getNumTel());
    query.bindValue(":ADRESSE",this->getAdresse());
    query.bindValue(":MAIL_CLIENT",this->getMail_client());
    query.bindValue(":FONCTION",this->getFonction());
    query.bindValue(":GENRE",this->getGenre());
    query.bindValue(":ETAT_CIVILE",this->getEtat_civil());
    query.bindValue(":DATE_CREATION",this->getDate_creation());
    query.bindValue(":DATE_NAISSANCE",this->getDate_naissance());
    return query.exec();


    }

QSqlQueryModel * client::afficher_client()
{
    QSqlQueryModel *model=new QSqlQueryModel();


    model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by DATE_CREATION desc ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE NAISSANCE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM TEL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("FONCTION"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("DATE CREATION"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("MAIL CLIENT"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("ETAT CIVILE"));
    return model;
}

bool client::supprimer_client()
{
    carte_fidelite cf(this->getID(),0,0);
    cf.supprimer_cartefidelite_id_client();

    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE id_client=:id_client");
    query.bindValue(":id_client",this->getID());

     return query.exec();
}


bool client::modifier_client()
{
    QSqlQuery  query ;
    query.prepare("UPDATE client set CIN=:CIN , NOM=:NOM , PRENOM=:PRENOM ,"
                  " DATE_NAISSANCE=:DATE_NAISSANCE ,NUM_TEL=:NUM_TEL ,FONCTION=:FONCTION ,"
                  "ADRESSE=:ADRESSE,MAIL_CLIENT=:MAIL_CLIENT,GENRE=:GENRE,ETAT_CIVILE=:ETAT_CIVILE WHERE ID_CLIENT=:ID_CLIENT");
    query.bindValue(":CIN",this->getCin());
    query.bindValue(":NOM",this->getNom());
    query.bindValue(":PRENOM",this->getPrenom());
    query.bindValue(":DATE_NAISSANCE",this->getDate_naissance());
    query.bindValue(":NUM_TEL",this->getNumTel());
    query.bindValue(":FONCTION",this->getFonction());
    query.bindValue(":ADRESSE",this->getAdresse());
    query.bindValue(":MAIL_CLIENT",this->getMail_client());
    query.bindValue(":GENRE",this->getGenre());
    query.bindValue(":ETAT_CIVILE",this->getEtat_civil());
    query.bindValue(":ID_CLIENT",this->getID());
    return query.exec();
}



bool  client::existe_client_cin()
{
        QSqlQuery  *query  = new QSqlQuery();
        query->prepare("select * from client where cin=:cin" );
        query->bindValue(":CIN",this->getCin());
        query->exec();
        int count=0;
        while(query->next())//tchouf el ligne elli mbaedha
        {
         count++;
        }


       if (count == 0 )
       {
          return false;
       }
       else  {return true;}

}


bool  client::existe_client_tel()
{
        QSqlQuery  *query  = new QSqlQuery();
        query->prepare("select * from client where  NUM_TEL=:NUM_TEL" );
        query->bindValue(":NUM_TEL",this->getNumTel());
        query->exec();
        int count=0;
        while(query->next()){
         count++;
        }


       if (count == 0 )
       {
          return false;
       }
       else  {return true;}

}


QString client::controle_saisie()
{
   QString msg="";

   QString cin = QString::number(this->getCin());
   if (this->getFonction() != "Eleve")
   {
       if (cin.length() != 8)
       {
           msg=msg+" le cin doit contenir 8 chiffre " ;
       }
    }
   else if (this->getFonction() == "Eleve")
   {
        if( cin != "0")
        {
           msg=msg+" l eleve n admet pas une cin" ;
       }
    }

   QString tel = QString::number(this->getNumTel());
       if (tel.length() != 8)
       {
           msg=msg+" le telephone doit contenir 8 chiffre \n " ;
       }

       //int i=0;
       QString nom=this->getNom().toLower();
           if (this->getNom().length() < 3)
           {
               msg=msg+" le nom doit contenir au moins 3 caractere \n " ;
               /*for (i=0 ;i > nom.length() ;i++)
               {
                  // if (i )*/
           }


            QString prenom=this->getPrenom().toLower();
                if (this->getPrenom().length() < 3)
                {
                    msg=msg+" le prenom doit contenir au moins 3 caractere \n " ;}

               QString adresse=this->getAdresse().toLower();
                   if (this->getAdresse().length() < 1)
                   {
                       msg=msg+" il faut saisir l adresse " ;}


                  QString mail=this->getMail_client().toLower();
                      if (this->getMail_client().length() < 9)
                      {
                          msg=msg+" le mail doit contenir au moins 9 caractere \n " ;}

                     return msg;
}


QSqlQueryModel * client::rechercher_existe(QString num){

       QSqlQueryModel *model=new QSqlQueryModel();

       model->setQuery(" select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE  from client c where CIN like '%'||'"+num+"'||'%' or ID_CLIENT like '%'||'"+num+"'||'%' or ADRESSE like '%'||'"+num+"'||'%' or MAIL_CLIENT like '%'||'"+num+"'||'%'  or NOM like '%'||'"+num+"'||'%' or PRENOM like '%'||'"+num+"'||'%' or NUM_TEL like '%'||'"+num+"'||'%' or GENRE like '%'||'"+num+"'||'%' or FONCTION like '%'||'"+num+"'||'%' or ETAT_CIVILE like '%'||'"+num+"'||'%' order by DATE_CREATION desc");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID CLIENT"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE NAISSANCE"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM TEL"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("FONCTION"));
       model->setHeaderData(7,Qt::Horizontal,QObject::tr("ADRESSE"));
       model->setHeaderData(8,Qt::Horizontal,QObject::tr("DATE CREATION"));
       model->setHeaderData(9,Qt::Horizontal,QObject::tr("MAIL CLIENT"));
       model->setHeaderData(10,Qt::Horizontal,QObject::tr("GENRE"));
       model->setHeaderData(11,Qt::Horizontal,QObject::tr("ETAT CIVILE"));
       return model;

}







QSqlQueryModel * client::filtre(QString genre,QString fonction ,QString etat){

    QSqlQueryModel *model=new QSqlQueryModel();


    if (genre != "" & fonction != "" & etat != "")
    {
                model->setQuery("select * from client  where FONCTION='"+fonction+"' AND GENRE='"+genre+"' AND ETAT_CIVILE='"+etat+"'");

    }

    if (genre != "" & fonction == "" & etat != "")
    {
                model->setQuery("select * from client  where  GENRE='"+genre+"' AND ETAT_CIVILE='"+etat+"'");

    }

    if (genre != "" & fonction != "" & etat == "")
    {
                model->setQuery("select * from client  where FONCTION='"+fonction+"' AND GENRE='"+genre+"' ");

    }
    if (genre != "" & fonction == "" & etat == "")
    {
                model->setQuery("select * from client  where GENRE='"+genre+"' ");

    }
    if (genre == "" & fonction == "" & etat != "")
    {
                model->setQuery("select * from client  where  ETAT_CIVILE='"+etat+"'");

    }
    if (genre == "" & fonction != "" & etat != "")
    {
                model->setQuery("select * from client  where FONCTION='"+fonction+"'  AND ETAT_CIVILE='"+etat+"'");

    }
    if (genre == "" & fonction == "" & etat != "")
    {
                model->setQuery("select * from client  where  ETAT_CIVILE='"+etat+"'");

    }

    if (genre == "" & fonction != "" & etat == "")
    {
                model->setQuery("select * from client  where FONCTION='"+fonction+"'" );

    }


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE NAISSANCE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM TEL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("FONCTION"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("DATE CREATION"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("MAIL CLIENT"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("ETAT CIVILE"));
        return model;
}


bool client::existe_emp(employe e)
{
        QSqlQuery  *query  = new QSqlQuery();
        query->prepare("select * from employe where login=:login and password=:password" );
        query->bindValue(":login",e.getLogin());
        query->bindValue(":password",e.getPassword());
        query->exec();
        int count=0;
        while(query->next())//tchouf el ligne elli mbaedha
        {
         count++;
        }
       if (count == 0 )
       {
          return false;
       }
       else  {return true;}

}


QSqlQueryModel * client::trier_client()
{
    QSqlQueryModel *model=new QSqlQueryModel();


    model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by nom ,prenom ,DATE_CREATION desc ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE NAISSANCE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM TEL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("FONCTION"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("DATE CREATION"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("MAIL CLIENT"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("ETAT CIVILE"));
    return model;
}



QSqlQueryModel * client::trier_personaliser_client(QString c)
{
    QSqlQueryModel *model=new QSqlQueryModel();

    if (c=="ID_CLIENT")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by ID_CLIENT desc ");}

    if (c=="CIN")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by cin desc ");}

    if (c=="NOM")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by nom  ");}

    if (c=="PRENOM")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by prenom  ");}

    if (c=="DATE_NAISSANCE")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by DATE_NAISSANCE desc ");}

    if (c=="NUM_TEL")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by NUM_TEL desc ");}

    if (c=="FONCTION")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by FONCTION  ");}

    if (c=="ADRESSE")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by ADRESSE  ");}

    if (c=="DATE_CREATION")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by DATE_CREATION desc ");}

    if (c=="MAIL")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by MAIL_CLIENT  ");}


    if (c=="ETAT_CIVILE")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by ETAT_CIVILE  ");}


    if (c=="GENRE")
    {model->setQuery("select ID_CLIENT,TO_CHAR(CIN),NOM,PRENOM,DATE_NAISSANCE,TO_CHAR(NUM_TEL),FONCTION,ADRESSE,DATE_CREATION,MAIL_CLIENT,GENRE,ETAT_CIVILE from client order by GENRE  ");}

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE NAISSANCE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM TEL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("FONCTION"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("DATE CREATION"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("MAIL CLIENT"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("ETAT CIVILE"));
    return model;
}

void client::printPDF(QString date_creation,QString points,QString film,QString cin_c,QString tel_c)
{
    QPdfWriter pdf("C:/Users/sinda/Desktop/file.pdf"); //création du pdf

    QPainter painter(&pdf);
    //QImage image("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3/Actee.jpg"); //recupération de l'image

       QString DATE =QDate::currentDate().toString();

      /* QFile file;
       QDir::setCurrent("/tmp");
       file.setFileName("ActeF.pdf");
       //QDir::setCurrent("C:/Users/Bader Semah/Desktop/Smart_Municipality_2A3");
       QDir::setCurrent("C:/Users/user/Desktop/Smart_Municipality_2A3");
       file.open(QIODevice::ReadOnly);
       QImage image(file.fileName());
       painter.drawImage(0,0,image.scaled(4958,7017, Qt::IgnoreAspectRatio, Qt::FastTransformation));*/
        QFont font = painter.font();
        font.setPointSize(font.pointSize());
        painter.setFont(font);
       // painter.drawImage(0,0,image.scaled(7000,10000,Qt::IgnoreAspectRatio, Qt::FastTransformation));
        painter.setPen(Qt::black);
        painter.drawText(1000,4000,"CIN: ");
        painter.drawText(2000, 4000, cin_c);
        painter.drawText(1000,4300,"NOM: ");
        painter.drawText(2000, 4300, this->nom);
        painter.drawText(1000,4600,"PRENOM: ");
        painter.drawText(2000, 4600, this->prenom);
        painter.drawText(1000,4900,"ADRESSE:");
        painter.drawText(2000, 4900, this->adresse);
        painter.drawText(1000,5200,"MAIL: ");
        painter.drawText(2000, 5200, this->mail_client);
        painter.drawText(1000,5500,"TELEPHONE: ");
        painter.drawText(2000, 5500, tel_c);
        painter.drawText(2000, 5800, date_creation);
        painter.drawText(2000, 6100, points);
         painter.drawText(2000,6400, film);
         painter.drawText(1000,6700,"DATE: ");
        painter.drawText(2000, 6700, DATE);
        painter.end();
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("A pdf : fiche client has been created.");
        msgBox.exec();
}

