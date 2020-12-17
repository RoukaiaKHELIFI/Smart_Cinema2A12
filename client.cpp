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
