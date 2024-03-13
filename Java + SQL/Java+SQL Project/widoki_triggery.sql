drop function if exists dodaj_pilkarza, usun_zalezne_pilkarz, usun_zalezne_trener, usun_zalezne_fizjoterapeuta, usun_zalezne_trening, usun_zalezne_sala, usun_zalezne_sprzet, sprawdz_pozycje cascade;
drop view if exists widok_treningu, widok_cwiczenia_fizjoterapeuta, widok_wydatki_tygodniowe_treningi, widok_wydatki_tygodniowe_na_fizjoterapie, widok_wydatki_tygodniowe_trenerzy, widok_wydatki_tygodniowe_sala, widok_wydatki_tygodniowe_sprzet, widok_wydatki_tygodniowe_fizjoterapeuta, widok_srednie_zarobki_fizjoterapeuci,widok_srednie_zarobki_trenerzy cascade;

CREATE VIEW widok_treningu AS
SELECT 
    t.trening_id,
    t.dzien_treningu as dzien_treningu,
    t.trener_id,
    tr.imie AS trener_imie,
    tr.nazwisko AS trener_nazwisko,
    tr.imie || ' ' || tr.nazwisko AS trener_imie_nazwisko,
    tr.specjalizacja,
    tr.zarobki_za_trening as zarobki_za_trening,
    s.nazwa AS nazwa_sali,
    s.koszt as koszt_sali,
    sp.nazwa AS nazwa_sprzetu,
    sp.koszt as koszt_sprzetu
FROM trening t
JOIN trener tr ON t.trener_id = tr.trener_id
JOIN sala s ON t.sala_id = s.sala_id
JOIN sprzet sp ON t.sprzet_id = sp.sprzet_id
group by t.trening_id, tr.imie, tr.nazwisko, s.nazwa, sp.nazwa,t.dzien_treningu, tr.specjalizacja, tr.zarobki_za_trening, s.koszt, sp.koszt;



CREATE VIEW widok_cwiczenia_fizjoterapeuta AS
SELECT 
    cf.cwiczenia_fizjoterapeuta_id,
    cf.fizjoterapeuta_id, 
    cf.pilkarz_id,
    cf.dzien_cwiczen as dzien_cwiczen,
    f.imie AS fizjoterapeuta_imie,
    f.nazwisko AS fizjoterapeuta_nazwisko,
    f.imie || ' ' || f.nazwisko AS fizjoterapeuta_imie_nazwisko,
    f.zarobki_za_trening as zarobki_za_trening,
    p.imie AS pilkarz_imie,
    p.nazwisko AS pilkarz_nazwisko,
    p.imie || ' ' || p.nazwisko AS pilkarz_imie_nazwisko
FROM cwiczenia_fizjoterapeuta cf
JOIN fizjoterapeuta f ON cf.fizjoterapeuta_id = f.fizjoterapeuta_id
JOIN pilkarz p ON cf.pilkarz_id = p.pilkarz_id;

-- koszt tygodniowy treningów 
create view widok_wydatki_tygodniowe_treningi as
Select SUM(tr.zarobki_za_trening+s.koszt+sp.koszt) as koszt_tygodniowy_treningow
from trening t
join trener tr on t.trener_id = tr.trener_id
join sala s on t.sala_id = s.sala_id
join sprzet sp on t.sprzet_id = sp.sprzet_id;

--koszt tygodniowy cwiczen
create view widok_wydatki_tygodniowe_na_fizjoterapie as
Select SUM(f.zarobki_za_trening) as koszt_tygodniowy_cwiczen
from cwiczenia_fizjoterapeuta cf
join fizjoterapeuta f on cf.fizjoterapeuta_id = f.fizjoterapeuta_id;


--wydatki na trenerów tygodniowo
create view widok_wydatki_tygodniowe_trenerzy as
SELECT SUM(tr.zarobki_za_trening)as koszt_tygodniowy, count(tr.trener_id) as liczba_treningow,     tr.imie || ' ' || tr.nazwisko AS trener_imie_nazwisko
from trener tr
join trening t on tr.trener_id = t.trener_id
group by tr.imie, tr.nazwisko
order by koszt_tygodniowy desc;


-- --średnie zarobki trenerów
-- create view widok_srednie_zarobki_trenerzy as
-- SELECT AVG(tr.zarobki_za_trening)as srednie_zarobki, tr.imie || ' ' || tr.nazwisko AS trener_imie_nazwisko
-- from trener tr
-- group by tr.imie, tr.nazwisko;

-- --średnie zarobki fizjoterapeutów
-- create view widok_srednie_zarobki_fizjoterapeuci as
-- SELECT AVG(f.zarobki_za_trening)as srednie_zarobki, f.imie || ' ' || f.nazwisko AS fizjoterapeuta_imie_nazwisko
-- from fizjoterapeuta f
-- group by f.imie, f.nazwisko;



--wydatki na sale tygodniowo
CREATE VIEW widok_wydatki_tygodniowe_sala as
SELECT SUM(s.koszt)as koszt_tygodniowy,count(s.sala_id) as liczba_wynajec, s.nazwa as nazwa_sali
from sala s
join trening t on s.sala_id = t.sala_id
group by s.nazwa
order by koszt_tygodniowy desc;

--wydatki na sprzet tygodniowo 
CREATE VIEW widok_wydatki_tygodniowe_sprzet as
SELECT SUM(sp.koszt)as koszt_tygodniowy,count(sp.sprzet_id) as liczba_wypozyczen, sp.nazwa as nazwa_sprzetu
from sprzet sp
join trening t on sp.sprzet_id = t.sprzet_id
group by sp.nazwa
order by koszt_tygodniowy desc;

--wydatki na fizjoterapeutów tygodniowo
CREATE VIEW widok_wydatki_tygodniowe_fizjoterapeuta as
SELECT SUM(f.zarobki_za_trening)as koszt_tygodniowy, count(f.fizjoterapeuta_id) as liczba_zajec_fizjoterapeutycznych, f.imie || ' ' || f.nazwisko AS fizjoterapeuta_imie_nazwisko
from fizjoterapeuta f
join cwiczenia_fizjoterapeuta cf on f.fizjoterapeuta_id = cf.fizjoterapeuta_id
group by f.imie, f.nazwisko
order by koszt_tygodniowy desc;


--usuwanie zaleznego pilkarza
CREATE FUNCTION usun_zalezne_pilkarz()
RETURNS TRIGGER AS $$
BEGIN
    DELETE FROM trening_pilkarz WHERE pilkarz_id = OLD.pilkarz_id;
    DELETE FROM cwiczenia_fizjoterapeuta WHERE pilkarz_id = OLD.pilkarz_id;
    RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER usun_pilkarza_trigger
BEFORE DELETE ON pilkarz
FOR EACH ROW
EXECUTE FUNCTION usun_zalezne_pilkarz();


--usuwanie zaleznego trenera
CREATE FUNCTION usun_zalezne_trener()
RETURNS TRIGGER AS $$
BEGIN
    DELETE FROM trening WHERE trener_id = OLD.trener_id;
    RETURN OLD;
END;
$$ LANGUAGE plpgsql;

create trigger usun_trenera_trigger
BEFORE DELETE ON trener
FOR EACH ROW
EXECUTE FUNCTION usun_zalezne_trener();

--usuwanie zaleznego fizjoterapeuty
CREATE FUNCTION usun_zalezne_fizjoterapeuta()
RETURNS TRIGGER AS $$
BEGIN
    DELETE FROM cwiczenia_fizjoterapeuta WHERE fizjoterapeuta_id = OLD.fizjoterapeuta_id;
    RETURN OLD;
END;
$$ LANGUAGE plpgsql;

create trigger usun_fizjoterapeute_trigger
BEFORE DELETE ON fizjoterapeuta
FOR EACH ROW
EXECUTE FUNCTION usun_zalezne_fizjoterapeuta();

--usuwanie zaleznego treningu
CREATE FUNCTION usun_zalezne_trening()
RETURNS TRIGGER AS $$
BEGIN
    DELETE FROM trening_pilkarz WHERE trening_id = OLD.trening_id;
    RETURN OLD;
END;
$$ LANGUAGE plpgsql;

create trigger usun_trening_trigger
BEFORE DELETE ON trening
FOR EACH ROW
EXECUTE FUNCTION usun_zalezne_trening();

--usuwanie zaleznego sala
CREATE FUNCTION usun_zalezne_sala()
RETURNS TRIGGER AS $$
BEGIN
    DELETE FROM trening WHERE sala_id = OLD.sala_id;
    RETURN OLD;
END;
$$ LANGUAGE plpgsql;

create trigger usun_sala_trigger
BEFORE DELETE ON sala
FOR EACH ROW
EXECUTE FUNCTION usun_zalezne_sala();

--usuwanie zaleznego sprzet
CREATE FUNCTION usun_zalezne_sprzet()
RETURNS TRIGGER AS $$
BEGIN
    DELETE FROM trening WHERE sprzet_id = OLD.sprzet_id;
    RETURN OLD;
END;
$$ LANGUAGE plpgsql;

create trigger usun_sprzet_trigger
BEFORE DELETE ON sprzet
FOR EACH ROW
EXECUTE FUNCTION usun_zalezne_sprzet();


--sprawdzanie pozycji
CREATE FUNCTION sprawdz_pozycje()
RETURNS TRIGGER AS $$
DECLARE
    pilkarzPozycja varchar(30);
    trenerPozycja varchar(30);
BEGIN
    SELECT p.pozycja INTO pilkarzPozycja FROM pilkarz p 
    join trening_pilkarz tp on p.pilkarz_id = tp.pilkarz_id
    WHERE tp.pilkarz_id = NEW.pilkarz_id;

    SELECT t.specjalizacja INTO trenerPozycja FROM trener t
    join trening tr on t.trener_id = tr.trener_id
    join trening_pilkarz tp on tr.trening_id = tp.trening_id
    WHERE tp.trening_id = NEW.trening_id;

    IF pilkarzPozycja <> trenerPozycja THEN
        RAISE EXCEPTION 'Błędne dopasowanie pozycji';
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;


create trigger sprawdz_pozycje_trigger
BEFORE INSERT OR UPDATE ON trening_pilkarz
FOR EACH ROW
EXECUTE PROCEDURE sprawdz_pozycje();