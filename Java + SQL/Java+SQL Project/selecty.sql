Select SUM(koszt_sali) as koszt_sali,SUM(koszt_sprzetu) as koszt_sprzetu, SUM(zarobki_za_trening) as koszt_trenerow from widok_treningu;

SELECT  * from widok_wydatki_tygodniowe_treningi;

SELECT  SUM(zarobki_za_trening) as zarobki_za_trening from widok_cwiczenia_fizjoterapeuta;

select * from widok_wydatki_tygodniowe_trenerzy;

SELECT SUM(zarobki_za_trening) as koszt_trenerow from widok_treningu;

select * from widok_wydatki_tygodniowe_sala

SELECT SUM(koszt_sali) as koszt_sali from widok_treningu;

select * from widok_wydatki_tygodniowe_sprzet;

SELECT SUM(koszt_sprzetu) as koszt_sprzetu from widok_treningu;

select * from widok_wydatki_tygodniowe_fizjoterapeuta;

SELECT SUM(zarobki_za_trening) as koszt_fizjoterapeutow from widok_cwiczenia_fizjoterapeuta;

SELECT pilkarz_id, imie,nazwisko from pilkarz order by pilkarz_id asc;

--Wypisuje fizjoterapeutów którzy nie mają żadnych zajęć w danym dniu
SELECT fizjoterapeuta_id, imie, nazwisko FROM fizjoterapeuta WHERE fizjoterapeuta_id NOT IN (SELECT fizjoterapeuta_id FROM cwiczenia_fizjoterapeuta WHERE dzien_cwiczen = ?);

insert into cwiczenia_fizjoterapeuta(pilkarz_id,fizjoterapeuta_id,dzien_cwiczen) values (?,?,?);

insert into fizjoterapeuta(imie, nazwisko,zarobki_za_trening) values (?,?,?);

insert into pilkarz(imie, nazwisko, pozycja) values (?,?,?);

SELECT pilkarz_id, imie,nazwisko, pozycja from pilkarz order by pilkarz_id asc ;

SELECT  trening_id, dzien_treningu, trener_imie_nazwisko, specjalizacja from widok_treningu order by trening_id asc;

insert into trening_pilkarz(pilkarz_id,trening_id) values (?,?);

insert into sala(nazwa,koszt) values (?,?);

insert into sprzet(nazwa,koszt) values (?,?);

insert into trener(imie, nazwisko, specjalizacja,zarobki_za_trening) values (?,?,?,?);

--Wypisuje trenerów którzy nie mają żadnych zajęć w danym dniu
SELECT trener_id, imie, nazwisko FROM trener WHERE trener_id NOT IN (SELECT trener_id FROM trening WHERE dzien_treningu = ?);

--Wypisuje sale które nie mają żadnych zajęć w danym dniu
SELECT sala_id,nazwa,koszt FROM sala WHERE sala_id NOT IN (SELECT sala_id FROM trening WHERE dzien_treningu = ?);

--Wypisuje sprzęt który nie jest używany w danym dniu
SELECT sprzet_id,nazwa,koszt FROM sprzet WHERE sprzet_id NOT IN (SELECT sprzet_id FROM trening WHERE dzien_treningu = ?);

insert into trening(trener_id,sala_id,sprzet_id,dzien_treningu) values (?,?,?,?);

SELECT trener_imie_nazwisko, specjalizacja, nazwa_sali, nazwa_sprzetu, dzien_treningu from widok_treningu group by trener_imie_nazwisko, specjalizacja, nazwa_sali, nazwa_sprzetu, dzien_treningu;

SELECT fizjoterapeuta_imie_nazwisko, pilkarz_imie_nazwisko, dzien_cwiczen from widok_cwiczenia_fizjoterapeuta group by fizjoterapeuta_imie_nazwisko, pilkarz_imie_nazwisko, dzien_cwiczen;

--wypisuje treningi w których bierze udział dany piłkarz
Select nazwa_sali, dzien_treningu from widok_treningu where trening_id in (select trening_id from trening_pilkarz where pilkarz_id = ?);

--wypisuje cwiczenia w których bierze udział dany piłkarz
Select fizjoterapeuta_imie_nazwisko, dzien_cwiczen from widok_cwiczenia_fizjoterapeuta where pilkarz_id = ?;

Select dzien_treningu, nazwa_sali, nazwa_sprzetu from widok_treningu where trener_id = ?;

Select dzien_cwiczen, pilkarz_imie_nazwisko from widok_cwiczenia_fizjoterapeuta where fizjoterapeuta_id = ?;

SELECT fizjoterapeuta_id, imie, nazwisko from fizjoterapeuta;

SELECT trener_id, imie, nazwisko from trener;

SELECT pilkarz_id, imie, nazwisko from pilkarz;

SELECT pilkarz_id, imie,nazwisko from pilkarz;

SELECT trener_id, imie,nazwisko from trener;

SELECT fizjoterapeuta_id, imie,nazwisko from fizjoterapeuta;

SELECT sala_id, nazwa from sala;

SELECT sprzet_id, nazwa from sprzet;

SELECT trening_id, dzien_treningu, trener_imie_nazwisko from widok_treningu;

SELECT cwiczenia_fizjoterapeuta_id, dzien_cwiczen from cwiczenia_fizjoterapeuta;

--wypisuje informacje o piłkarzach przypisanych do treningów, dodatkowo wyświetla treneró którzy prowadza trening w którym uczestniczy piłkarz
Select tp.trening_pilkarz_id ,wk.trener_imie_nazwisko,p.imie, p.nazwisko from widok_treningu wk join trening_pilkarz tp on wk.trening_id = tp.trening_id join pilkarz p on p.pilkarz_id = tp.pilkarz_id group by tp.trening_pilkarz_id, wk.trener_imie_nazwisko, p.imie, p.nazwisko order by tp.trening_pilkarz_id;

SELECT * from trener;

SELECT * from fizjoterapeuta;

SELECT * from sala;

SELECT * from sprzet;

SELECT * from pilkarz;

SELECT * from trening;

SELECT * from trening_pilkarz;

SELECT * from cwiczenia_fizjoterapeuta;


