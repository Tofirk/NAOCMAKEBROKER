#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------


#------------------------------------------------------------
# Table: Type
#------------------------------------------------------------

CREATE TABLE Type(
        idType Int  Auto_increment  NOT NULL ,
        nom    Varchar (50) NOT NULL
	,CONSTRAINT Type_PK PRIMARY KEY (idType)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Questions
#------------------------------------------------------------

CREATE TABLE Questions(
        idQuestions Int  Auto_increment  NOT NULL ,
        questions   Varchar (50) NOT NULL ,
        reponse     Varchar (50) NOT NULL ,
        idType      Int NOT NULL
	,CONSTRAINT Questions_PK PRIMARY KEY (idQuestions)

	,CONSTRAINT Questions_Type_FK FOREIGN KEY (idType) REFERENCES Type(idType)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: niveau
#------------------------------------------------------------

CREATE TABLE niveau(
        idNiveau Int  Auto_increment  NOT NULL ,
        nom      Varchar (50) NOT NULL
	,CONSTRAINT niveau_PK PRIMARY KEY (idNiveau)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: seance
#------------------------------------------------------------

CREATE TABLE seance(
        idSeance          Int  Auto_increment  NOT NULL ,
        intitule          Varchar (50) NOT NULL ,
        question_en_cours Int NOT NULL ,
        idNiveau          Int
	,CONSTRAINT seance_PK PRIMARY KEY (idSeance)

	,CONSTRAINT seance_niveau_FK FOREIGN KEY (idNiveau) REFERENCES niveau(idNiveau)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: eleve
#------------------------------------------------------------

CREATE TABLE eleve(
        idEleve  Int  Auto_increment  NOT NULL ,
        prenom   Varchar (50) NOT NULL ,
        idNiveau Int NOT NULL
	,CONSTRAINT eleve_PK PRIMARY KEY (idEleve)

	,CONSTRAINT eleve_niveau_FK FOREIGN KEY (idNiveau) REFERENCES niveau(idNiveau)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: CONTENIR
#------------------------------------------------------------

CREATE TABLE CONTENIR(
        idQuestions Int NOT NULL ,
        idSeance    Int NOT NULL
	,CONSTRAINT CONTENIR_PK PRIMARY KEY (idQuestions,idSeance)

	,CONSTRAINT CONTENIR_Questions_FK FOREIGN KEY (idQuestions) REFERENCES Questions(idQuestions)
	,CONSTRAINT CONTENIR_seance0_FK FOREIGN KEY (idSeance) REFERENCES seance(idSeance)
)ENGINE=InnoDB;

