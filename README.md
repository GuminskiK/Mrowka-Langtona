# Mrowka-Langtona
[![C/C++ CI](https://github.com/GuminskiK/Mrowka-Langtona/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/GuminskiK/Mrowka-Langtona/actions/workflows/c-cpp.yml)

Projekt Mrówki Langtona, praca dwuosobowa. 

Mrówka Langtona jest prostym automatem komórkowym, który generuje ciekawe wzory.  

  Program działa w ten sposób, że tworzymy pewną dwuwymiarową siatkę, składająca się z pól w kolorze czarnym i białym. Następnie umieszczamy na niej mrówkę (może być ona reprezentowana przez np. trójkąt), która porusza się w jednym z 4-ech kierunków (góra, dół, lewo, prawo). Zgodnie z następującymi zasadami: 

  • Mrówka znajduje się w komórce białej, wykonuje: obrót o 90 stopni w prawo, zmienia kolor komórki na przeciwny, przesuwa się o jedną komórkę do przodu. 

  • Mrówka znajduje się w komórce czarnej, wykonuje: obrót o 90 stopni w lewo, zmienia kolor komórki na przeciwny, przesuwa się o jedną komórkę do przodu. 

Wywołanie programu:

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

		N - Północ 

		E - Wschód 

		S - Południe 

		W - Zachód 

		(domyślnie N)	 

Losowej planszy 

	Program generuje losową planszę. Ziarno używane do generacji planszy jest ustalane na podstawie aktualnego czasu podczas wykonania. 

	./mrowka -g [WIERSZE] [KOLUMNY] [LICZBA ITERACJI] [PRZEDROSTEK] [KIERUNEK] [PROCENT WYPEŁNIENIA] 


	WIERSZE – Ilość wierszy planszy, na której znajduje się mrówka (domyślnie 8) 

	KOLUMNY - Ilość kolumn planszy, na której znajduje się mrówka (domyślnie 10) 

	LICZBA ITERACJI – Oznacza, ile razy poruszy się mrówka (domyślnie 20) 

	PRZEDROSTEK – Przedrostek plików wyjściowych, nazwa wszystkich plików wyjściowych będzie zaczynała się od tego przedrostka (domyślnie ML) 

	KIERUNEK – Kierunek początkowy mrówki. Jako kierunek można podać: 

		N - Północ 
	
		E - Wschód 

		S - Południe 

		W - Zachód 

		(domyślnie N)	 

	PROCENT WYPEŁNIENIA - W jakim stopniu plansza jest wypełniona przeszkodami (domyślnie 10). Znaku procenta nie trzeba dodawać. 

 

Wczytanej planszy 

	Wczytuje plik przechowujący aktualny stan planszy i na jego podstawie kontynuuje. 

	./mrowka -w [PLIK] [PRZEDROSTEK] [ILOSC ITERACJI] 


	PLIK – Wczytany plik zawierający stan wygenerowany przez uruchomienie programu mrowka 

	PRZEDROSTEK - Przedrostek plików wyjściowych, nazwa wszystkich plików wyjściowych będzie zaczynała się od tego przedrostka (domyślnie ML) 

	ILOSC ITERACJI - Oznacza, ile razy poruszy się mrówka po wczytaniu stanu (domyślnie 20) 
