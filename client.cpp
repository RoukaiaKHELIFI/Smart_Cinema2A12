#include "client.h"
#include <QSqlQuery>
#include <string>
bool client:: ajouter_client( )
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (ID_CLIENT,CIN,NOM,PRENOM,NUM_TEL,ADRESSE,MAIL_CLIENT,FONCTION,GENRE,ETAT_CIVILE,DATE_CREATION,DATE_NAISSANCE)"
                   "VALUES (ID_CLIENT.nextval,:CIN,:NOM,:PRENOM,:NUM_TEL,:ADRESSE,:MAIL_CLIENT,:FONCTION,:GENRE,:ETAT_CIVILE,:DATE_CREATION,:DATE_NAISSANCE)");
    query.bindValue(":CIN",this->getCin());
    query.bindValue(":NOM",this->getNom());
    query.bindValue(":PRENOM",this->getPreom());
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


    model->setQuery(" select * from client ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUM_TEL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("FONCTION"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("DATE_CREATION"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("MAIL_CLIENT"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("ETAT_CIVILE"));
    return model;
}

bool client::supprimer_client()
{
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE id_client=?");

         query.addBindValue(this->getID());

     return query.exec();
}


bool client::modifier_client()
{
    QSqlQuery  query ;
    query.prepare("UPDATE client set CIN=? , NOM=? , PRENOM=? , DATE_NAISSANCE=? ,NUM_TEL=? ,FONCTION=?,ADRESSE=?,MAIL_CLIENT=?,GENRE=?,ETAT_CIVILE=? WHERE ID_CLIENT=?");
    query.addBindValue(this->getCin());
    query.addBindValue(this->getNom());
    query.addBindValue(this->getPreom());
    query.addBindValue(this->getDate_naissance());
    query.addBindValue(this->getNumTel());
    query.addBindValue(this->getFonction());
    query.addBindValue(this->getAdresse());
    query.addBindValue(this->getMail_client());
    query.addBindValue(this->getGenre());
    query.addBindValue(this->getEtat_civil());
    query.addBindValue(this->getID());
    return query.exec();
}



bool  client::existe_client_cin()
{
        QSqlQuery  *query  = new QSqlQuery();
        query->prepare("select * from client where cin=?" );
        query->addBindValue(this->getCin());
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
        query->prepare("select * from client where  NUM_TEL=?" );
        query->addBindValue(this->getNumTel());
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


            QString prenom=this->getPreom().toLower();
                if (this->getPreom().length() < 3)
                {
                    msg=msg+" le prenom doit contenir au moins 3 caractere \n " ;}

               return msg;
}
