/*
 Autor: Dominik Kaczmarek
 Grupa: Pn/P 13:15
 Temat: Laboratorium 1
 Data: 23.10.2023 r.
 */
#include <stdio.h>
#include <math.h>

int rownanieKwadratowe()
{
    float a, b, c;
    printf("Podaj 3 liczby rzeczywiste: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("\n        %.2fx^2%+.2fx%+.2f=0\n\n", a, b, c);
    if (a==0) {
        printf("Rownanie kwadratowe jest nieprawidlowe.\n");
        return -1;
    }
    float delta = b*b - (4*a*c);
    printf("Delta wynosi %.2f.\n\n", delta);
    if (delta > 0) {
        float x1 = (-b - sqrt(delta))/(2*a);
        float x2 = (-b + sqrt(delta))/(2*a);
        printf("Rownanie ma 2 rozwiazania rzeczywiste: %.2f, %.2f.\n", x1, x2);
    }
    else if (delta == 0) {
        float x0 = (-b)/(2*a);
        printf("Rownanie ma 1 rozwiazanie rzeczywiste: %.2f.\n", x0);
    }
    else printf("Rownanie nie ma rozwiazan rzeczywistych.\n");
    return 0;
}

int dzienMiesiacRok() {
    int dzien, miesiac, rok;
    printf("Podaj dzien, miesiac i rok oddzielone kropkami: ");
    scanf("%d.%d.%d", &dzien, &miesiac, &rok);
    printf("Podana data: %d.%02d.%d.\n", dzien, miesiac, rok);
    if (miesiac <= 0 || miesiac > 12) {
        printf("Data jest niepoprawna.\n");
        return -1;
    }
    if (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 ||
        miesiac == 12) {
        if (0 < dzien && dzien <= 31) {
            printf("Data jest poprawna.");
            return 0;
        } else {
            printf("Data jest niepoprawna.\n");
            return -1;
        }
    }
    else if (miesiac != 2) {
        if (0 < dzien && dzien <= 30) {
            printf("Data jest poprawna.\n");
            return 0;
        } else {
            printf("Data jest niepoprawna.\n");
            return -1;
        }
    }
    else {
        bool przestepny;
        if (rok % 4 != 0 or ( rok % 100 == 0 and rok % 400 != 0)) przestepny = false;
        else przestepny = true;
        if (przestepny) {
            if (0 < dzien && dzien <= 29) {
                printf("Data jest poprawna.\n");
                return 0;
            } else {
                printf("Data jest niepoprawna.\n");
                return -1;
            }
        } else {
            if (0 < dzien && dzien <= 28) {
                printf("Data jest poprawna.\n");
                return 0;
            } else {
                printf("Data jest niepoprawna.\n");
                return -1;
            }
        }
    }
}

int trojkaty ()
{
    float a, b, c;
    printf("Podaj trzy dodatnie liczby oddzielone spacjami: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Wprowadzono niepoprawne liczby.");
        return -2;
    }
    if (a + b > c && a + c > b && b + c > a) printf("Mozna zbudowac trojkat.\n");
    else {
        printf("Nie mozna zbudowac trojkata.");
        return -1;
    }
    printf("Powstanie trojkat ");
    // rownoboczny
    if (a == b && b == c) printf("rownoboczny, ");
    // rownoramienny
    if (a == b || b == c || a == c) printf("rownoramienny, ");
    else printf("roznoboczny, ");
    float najdluzszyBok, bok2, bok3;
    najdluzszyBok = a;
    bok2 = b;
    bok3 = c;
    if (b > najdluzszyBok) {
        najdluzszyBok = b;
        bok2 = a;
        bok3 = c;
    }
    if (c > najdluzszyBok) {
        najdluzszyBok = c;
        bok2 = a;
        bok3 = b;
    }
    // ostrokatny
    if (najdluzszyBok*najdluzszyBok < (bok2*bok2 + bok3*bok3)) {
        printf("ostrokatny.");
        return 0;
    }
    // prostokatny
    if (najdluzszyBok*najdluzszyBok == (bok2*bok2 + bok3*bok3)) {
        printf("prostokatny.");
        return 0;
    }
    // rozwartokatny
    if (najdluzszyBok*najdluzszyBok > (bok2*bok2 + bok3*bok3)) {
        printf("rozwartokatny.");
        return 0;
    }
    return 0;
}

int promienieKol () {
    float minPromien, maxPromien, promien, zwiekszeniePromienia;
    int liczbaWierszy, wiersz = 1;
    printf("Podaj minimalny promien kola: ");
    scanf("%f", &minPromien);
    printf("Podaj maksymalny promien kola: ");
    scanf("%f", &maxPromien);
    printf("Podaj liczbe wierszy w tabeli: ");
    scanf("%i", &liczbaWierszy);

    zwiekszeniePromienia = (maxPromien - minPromien)/(liczbaWierszy - 1);
    promien = minPromien;
    printf("\n=========================================\n");
    printf("| Lp | promien | obwod kola | pole kola |\n");
    printf("=========================================\n");
    double obwodKola, poleKola;
    while (liczbaWierszy+1 != wiersz) {
        obwodKola = 2*M_PI*promien;
        poleKola = M_PI*promien*promien;
        printf("| %2i | %7.2f | %10.2lf | %9.2lf |\n", wiersz, promien, obwodKola, poleKola);
        promien += zwiekszeniePromienia;
        wiersz ++;
    }
    printf("=========================================\n");
    return 0;
}

int main ()
{
    printf("Autor: Dominik Kaczmarek (Pn/P)");
    int wybranaOpcja;
    while (true) {
        printf("\n\n\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
        printf("||       Wybierz zadanie do uruchomienia\n");
        printf("|| *1* Zadanie 1 - Rozwiazywanie rownania kwadratowego\n");
        printf("|| *2* Zadanie 2 - Sprawdzanie poprawnosci daty\n");
        printf("|| *3* Zadanie 3 - Budowanie trojkata\n");
        printf("|| *4* Zadanie 4 - Obliczanie obwodow i pol kol w tabeli\n");
        printf("|| *5* Zakoncz dzialanie programu\n");
        printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
        printf("Wprowadz numer wybranej opcji: ");
        scanf("%i", &wybranaOpcja);
        printf("\n\n");
        switch (wybranaOpcja) {
            case 1: rownanieKwadratowe();
                break;
            case 2: dzienMiesiacRok();
                break;
            case 3: trojkaty();
                break;
            case 4: promienieKol();
                break;
            case 5:
                goto koniec;
            default:
                printf("Wprowadzono nieprawidlowa cyfre.");
                break;
        }
    }
    koniec:
    return 0;
}