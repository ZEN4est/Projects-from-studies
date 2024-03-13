drop table if exists trening, pilkarz, trener, sala, sprzet,fizjoterapeuta,cwiczenia_fizjoterapeuta, trening_pilkarz cascade;
create table pilkarz
(
    pilkarz_id                      SERIAL PRIMARY KEY,
    imie                            varchar(30) not null,
    nazwisko                        varchar(30) not null,
    pozycja                         varchar(30) not null
);

create table trener
(
    trener_id                       SERIAL PRIMARY KEY,
    imie                            varchar(30) not null,
    nazwisko                        varchar(30) not null,
    specjalizacja                   varchar(30) not null,
    zarobki_za_trening              integer not null
);

CREATE TABLE sala
(
    sala_id                         SERIAL PRIMARY KEY,
    nazwa                           varchar(30) NOT NULL UNIQUE,
    koszt                           integer NOT NULL
);

create table sprzet
(
    sprzet_id                       SERIAL PRIMARY KEY,
    nazwa                           varchar(30) not null UNIQUE,
    koszt                           integer not null

);

create table trening
(
    trening_id                      SERIAL PRIMARY KEY,
    dzien_treningu                  varchar(30),
    trener_id                       integer not null,
    sala_id                         integer not null,
    sprzet_id                       integer not null,
    FOREIGN KEY (trener_id) REFERENCES trener(trener_id),   
    FOREIGN KEY (sala_id) REFERENCES sala(sala_id),
    FOREIGN KEY (sprzet_id) REFERENCES sprzet(sprzet_id)  
);

create table fizjoterapeuta
(
    fizjoterapeuta_id               SERIAL PRIMARY KEY,
    imie                            varchar(30) not null,
    nazwisko                        varchar(30) not null,
    zarobki_za_trening              integer not null
);

create  table cwiczenia_fizjoterapeuta(
    cwiczenia_fizjoterapeuta_id     SERIAL PRIMARY KEY,
    fizjoterapeuta_id               integer not null,
    pilkarz_id                      integer not null,
    dzien_cwiczen                  varchar(30) not null,
    FOREIGN KEY (fizjoterapeuta_id) REFERENCES fizjoterapeuta(fizjoterapeuta_id),
    FOREIGN KEY (pilkarz_id) REFERENCES pilkarz(pilkarz_id)
);

CREATE TABLE trening_pilkarz (
    trening_pilkarz_id              SERIAL PRIMARY KEY,
    trening_id                      INTEGER NOT NULL,
    pilkarz_id                      INTEGER NOT NULL,
    FOREIGN KEY (trening_id) REFERENCES trening(trening_id),
    FOREIGN KEY (pilkarz_id) REFERENCES pilkarz(pilkarz_id)
);







