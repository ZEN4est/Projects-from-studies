INSERT INTO pilkarz (imie, nazwisko, pozycja)
VALUES
    ('Robert', 'Lewandowski', 'Napastnik'),
    ('Arkadiusz', 'Milik', 'Napastnik'),
    ('Jakub', 'Moder', 'Pomocnik'),
    ('Karol', 'Linetty', 'Pomocnik'),
    ('Bartosz', 'Bereszyński', 'Obrońca'),
    ('Łukasz', 'Piszczek', 'Obrońca'),
    ('Wojciech', 'Szczęsny', 'Bramkarz'),
    ('Sebastian', 'Walukiewicz', 'Bramkarz');



INSERT INTO trener (imie, nazwisko, specjalizacja, zarobki_za_trening)
VALUES
    ('Adam', 'Nowak', 'Napastnik', 1000),
    ('Jan', 'Kowalski', 'Pomocnik', 800),
    ('Piotr', 'Wiśniewski', 'Obrońca', 900),
    ('Marcin', 'Wójcik', 'Bramkarz', 1200);

INSERT INTO sala (nazwa, koszt)
VALUES
    ('Sala A', 1000),
    ('Sala B', 1500),
    ('Sala C', 2000),
    ('Sala D', 1200),
    ('Sala E', 1800);
            
            
INSERT INTO sprzet (nazwa, koszt)
VALUES
    ('Piłki',100),
    ('Hantle',80),
    ('Maty do ćwiczeń', 60),
    ('Małe bramki',130),
    ('Grzybki',20);

INSERT INTO trening (dzien_treningu, trener_id, sala_id, sprzet_id)
VALUES
    ('Poniedziałek', 1, 1, 1),
    ('Poniedziałek', 2, 2, 2),
    ('Wtorek', 4, 2, 2),
    ('Wtorek', 2, 5, 1),
    ('Środa', 3, 3, 4),
    ('Środa', 4, 5, 3),
    ('Czwartek', 2, 1, 1),
    ('Czwartek', 1, 4, 4),
    ('Piątek', 1, 2, 3),
    ('Sobota', 2, 1, 2),
    ('Sobota', 4, 3, 3),
    ('Niedziela', 3, 5, 1);
 

insert into trening_pilkarz (trening_id, pilkarz_id) values
    (1,1),
    (1,2),
    (2,3),
    (2,4),
    (3,7),
    (3,8),
    (4,3),
    (4,4),
    (5,5),
    (5,6),
    (6,7),
    (6,8),
    (7,3),
    (7,4),
    (8,1),
    (8,2),
    (9,1),
    (9,2),
    (10,3),
    (10,4),
    (11,7),
    (11,8),
    (12,5),
    (12,6);

INSERT INTO fizjoterapeuta (Imie, Nazwisko, zarobki_za_trening)
VALUES
    ('Adam', 'Kowalski', 500),
    ('Michał', 'Kaczmarek', 500),
    ('Kamil', 'Kowalczyk', 550),
    ('Grzegorz', 'Lis', 600);


insert into cwiczenia_fizjoterapeuta (fizjoterapeuta_id, pilkarz_id, dzien_cwiczen) values
    (1,1, 'Poniedziałek'),
    (3,3, 'Poniedziałek'),
    (2,2, 'Wtorek'),
    (4,5, 'Wtorek'),
    (1,4, 'Środa'),
    (3,6, 'Środa'),
    (4,7, 'Środa'),
    (2,8, 'Czwartek'),
    (4,1, 'Czwartek'),
    (1,2, 'Piątek'),
    (3,4, 'Piątek'),
    (4,6, 'Piątek'),
    (2,7, 'Sobota'),
    (3,5, 'Sobota'),
    (4,8, 'Niedziela'),
    (1,3, 'Niedziela');

