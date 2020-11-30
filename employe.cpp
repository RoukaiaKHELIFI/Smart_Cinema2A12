#include "employe.h"
#include "QSqlQuery"

bool  employe::existe()
{
        QSqlQuery  *query  = new QSqlQuery();
        query->prepare("select * from employe where login=? and password=?" );
        query->addBindValue(getLogin());
        query->addBindValue(this->getPassword());
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
