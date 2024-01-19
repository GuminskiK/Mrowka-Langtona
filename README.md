# Mrowka-Langtona
[![C/C++ CI](https://github.com/GuminskiK/Mrowka-Langtona/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/GuminskiK/Mrowka-Langtona/actions/workflows/c-cpp.yml)

Projekt Mrówki Langtona, praca dwuosobowa. 

Mrówka Langtona jest prostym automatem komórkowym, który generuje ciekawe wzory.  

  Program działa w ten sposób, że tworzymy pewną dwuwymiarową siatkę, składająca się z pól w kolorze czarnym i białym. Następnie umieszczamy na niej mrówkę (może być ona reprezentowana przez np. trójkąt), która porusza się w jednym z 4-ech kierunków (góra, dół, lewo, prawo). Zgodnie z następującymi zasadami: 

  • Mrówka znajduje się w komórce białej, wykonuje: obrót o 90 stopni w prawo, zmienia kolor komórki na przeciwny, przesuwa się o jedną komórkę do przodu. 

  • Mrówka znajduje się w komórce czarnej, wykonuje: obrót o 90 stopni w lewo, zmienia kolor komórki na przeciwny, przesuwa się o jedną komórkę do przodu. 

## Wywołanie programu:

	./mrowka [argumenty] 

Program można wywołać w 3 trybach:  

- Pustej planszy 

- Losowej planszy 

- Wczytanej planszy 


Pustej planszy 

Program działa na pustej planszy. 

	./mrowka [WIERSZE] [KOLUMNY] [LICZBA ITERACJI] [PRZEDROSTEK] [KIERUNEK]  

	
WIERSZE – Ilość wierszy planszy, na której znajduje się mrówka (domyślnie 8) 

KOLUMNY - Ilość kolumn planszy, na której znajduje się mrówka (domyślnie 10) 

LICZBA ITERACJI – Oznacza, ile razy poruszy się mrówka (domyślnie 20) 

PRZEDROSTEK – Przedrostek plików wyjściowych, nazwa wszystkich plików wyjściowych będzie zaczynała się od tego przedrostka (domyślnie ML) 

KIERUNEK – Kierunek początkowy mrówki. Jako kierunek można podać: 

* N - Północ 

* E - Wschód 

* S - Południe 

* W - Zachód 

(domyślnie N)	 

### Losowej planszy 

Program generuje losową planszę. Ziarno używane do generacji planszy jest ustalane na podstawie aktualnego czasu podczas wykonania. 

	./mrowka -g [WIERSZE] [KOLUMNY] [LICZBA ITERACJI] [PRZEDROSTEK] [KIERUNEK] [PROCENT WYPEŁNIENIA] 


WIERSZE – Ilość wierszy planszy, na której znajduje się mrówka (domyślnie 8) 

KOLUMNY - Ilość kolumn planszy, na której znajduje się mrówka (domyślnie 10) 

LICZBA ITERACJI – Oznacza, ile razy poruszy się mrówka (domyślnie 20) 

PRZEDROSTEK – Przedrostek plików wyjściowych, nazwa wszystkich plików wyjściowych będzie zaczynała się od tego przedrostka (domyślnie ML) 

KIERUNEK – Kierunek początkowy mrówki. Jako kierunek można podać: 

* N - Północ 
	
* E - Wschód 

* S - Południe 

* W - Zachód 

(domyślnie N)	 

PROCENT WYPEŁNIENIA - W jakim stopniu plansza jest wypełniona przeszkodami (domyślnie 10). Znaku procenta nie trzeba dodawać. 

 

### Wczytanej planszy 

Wczytuje plik przechowujący aktualny stan planszy i na jego podstawie kontynuuje. 

	./mrowka -w [PLIK] [PRZEDROSTEK] [ILOSC ITERACJI] 


PLIK – Wczytany plik zawierający stan wygenerowany przez uruchomienie programu mrowka 

PRZEDROSTEK - Przedrostek plików wyjściowych, nazwa wszystkich plików wyjściowych będzie zaczynała się od tego przedrostka (domyślnie ML) 

ILOSC ITERACJI - Oznacza, ile razy poruszy się mrówka po wczytaniu stanu (domyślnie 20) 
## Testowanie 

W celu przetestowania programu można za pomocą “make check” wykonać testy.  

W katalogu testy znajdują się podkatalogi będące pojedynczymi testami. 

Pliki znajdujące się w katalogach testowy to: 
* args – Plik zawierający argumenty z którymi program będzie działał.  

* Input – Plik używany jako standardowe wejście. 

* output – Plik będący porównywany z wyjściem. W przypadku, którym plik “output” nie istnieje wyjście nie jest porównywane. 

* f* - plik zaczynające się na literę f, to wszystkie pliki, z których testowany program będzie mógł korzystać 

* Pozostałe pliki - Pozostałe pliki są porównywane z utworzonymi przez program plikami. Brak pliku po jednej stronie jest traktowany jako różnica. 

W przypadku różnicy porównywanych testów, test jest oznaczony jako nieudany. Aby program testujący zakończył działanie kodem 0 wszystkie testy muszą zostać zaliczone. 

make check jest wykonywane dla każdej operacji “push” lub “pull request” na gałęź główną na github. Informacja o statusie ostatniego testowania jest widoczna w README.  

  

## Tworzenie GIFa z wygenerowanych plansz 

Aby utworzyć GIF z wygenerowanych plansz można użyć znajdującego się w korzeniu projektu skryptu to_gif.sh. 

Użycie: 

	./to_gif.sh [KATALOG PLANSZ] [ODSTĘP CZASOWY] [PREFIX] [WYSOKOŚĆ] [SZEROKOŚĆ] [POCZATEK] [KONIEC] 

**KATALOG PLANSZY** - Ścieżka do katalogu, w którym znajdują się plansze. 

**ODSTĘP CZASOWY** - Ilość czasu w ms pomiędzy klatkami 

**PREFIX** – Prefiks plików będących używanych do kreacji GIFa. 

**WYSOKOŚĆ** - Wysokość GIFa w pikselach. 

**SZEROKOŚĆ** - Szerokość GIFa w pikselach. 

**POCZĄTEK** - Numer pierwszej planszy. 

	*KONIEC* – Numer ostatniej planszy.
