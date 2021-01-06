--------------------------------------------------------
--  Fichier cr�� - mercredi-janvier-06-2021   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table RESERVATION
--------------------------------------------------------

  CREATE TABLE "ROUKAIA"."RESERVATION" 
   (	"ID_CLIENT" NUMBER, 
	"ID_RESERVATION" VARCHAR2(20 BYTE), 
	"NB_PERSONNE" VARCHAR2(20 BYTE), 
	"NOM_FILM" VARCHAR2(30 BYTE), 
	"DATE_RES" DATE, 
	"MAIL_RESERVATION" VARCHAR2(30 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into ROUKAIA.RESERVATION
SET DEFINE OFF;
Insert into ROUKAIA.RESERVATION (ID_CLIENT,ID_RESERVATION,NB_PERSONNE,NOM_FILM,DATE_RES,MAIL_RESERVATION) values ('45555555','150447','2','Respect',to_date('10/12/20','DD/MM/RR'),'oussama.jmaa@esprit.tn');
Insert into ROUKAIA.RESERVATION (ID_CLIENT,ID_RESERVATION,NB_PERSONNE,NOM_FILM,DATE_RES,MAIL_RESERVATION) values ('4455555','150447','3','Fast & Furious 9',to_date('31/12/20','DD/MM/RR'),'roukaia.khelifi@esprit.tn');
Insert into ROUKAIA.RESERVATION (ID_CLIENT,ID_RESERVATION,NB_PERSONNE,NOM_FILM,DATE_RES,MAIL_RESERVATION) values ('122333','150447','2','Fast & Furious 9',to_date('17/12/20','DD/MM/RR'),'oussama.jmaa@esprit.tn');
Insert into ROUKAIA.RESERVATION (ID_CLIENT,ID_RESERVATION,NB_PERSONNE,NOM_FILM,DATE_RES,MAIL_RESERVATION) values ('124563315','150447','2','Soul',to_date('30/12/20','DD/MM/RR'),'roukaia.khelifi@esprit.tn');
Insert into ROUKAIA.RESERVATION (ID_CLIENT,ID_RESERVATION,NB_PERSONNE,NOM_FILM,DATE_RES,MAIL_RESERVATION) values ('49774977','150447','12','Fast & Furious 9',to_date('30/12/20','DD/MM/RR'),'roukaia.khelifi@esprit.tn');
Insert into ROUKAIA.RESERVATION (ID_CLIENT,ID_RESERVATION,NB_PERSONNE,NOM_FILM,DATE_RES,MAIL_RESERVATION) values ('12334566','55012','10','Respect',to_date('28/12/20','DD/MM/RR'),'roukaia.khelifi@esprit.tn');
--------------------------------------------------------
--  DDL for Index RESERVATION_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ROUKAIA"."RESERVATION_PK" ON "ROUKAIA"."RESERVATION" ("ID_CLIENT", "ID_RESERVATION") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table RESERVATION
--------------------------------------------------------

  ALTER TABLE "ROUKAIA"."RESERVATION" MODIFY ("ID_CLIENT" NOT NULL ENABLE);
  ALTER TABLE "ROUKAIA"."RESERVATION" MODIFY ("ID_RESERVATION" NOT NULL ENABLE);
  ALTER TABLE "ROUKAIA"."RESERVATION" MODIFY ("NB_PERSONNE" NOT NULL ENABLE);
  ALTER TABLE "ROUKAIA"."RESERVATION" MODIFY ("NOM_FILM" NOT NULL ENABLE);
  ALTER TABLE "ROUKAIA"."RESERVATION" MODIFY ("DATE_RES" NOT NULL ENABLE);
