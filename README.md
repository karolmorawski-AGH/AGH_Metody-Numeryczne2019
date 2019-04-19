# Metody Numeryczne 2019
semestr 4 AGH WIMiIP

## Funkcje główne:

### *Interpolacja Lagrange'a:*
```cpp
double lag_inter(double x);
```

Struktura pliku wejściowego:

```cpp
4           //stopien wielomianu
-2,5        //punkt
-1,-2       //punkt
0,4         //punkt
1,-7        //punkt
2,2         //punkt
```

Output:
```cpp
-0.117188 
```



### *Aproksymacja średniokwadratowa*
Baza wielomianów Legendre’a
```cpp
double hWithStar(double x, std::string filename)
```

Struktura pliku wejściowego:

```cpp
6           //stopien
-1.0;0.1    //punkt
-0.4;5.3    //punkt
-0.2;4.4    //punkt
-0.1;2.5    //punkt
0.4;3.7     //punkt
1.0;12.0    //punkt
```

### *Interpolacja Newtona*

```cpp
double newton(int value, std::vector<double> x, std::vector<double> y);
```

### *Kwadratury proste*

Metoda trapezów - liczy dla danych punktów z wektora *x*
```cpp
double integrationNum(std::vector<double> fx, double(*fun)(double));
```

Struktura pliku wejściowego:

```cpp
-1.0    //wspolrzedna x
-0.4    //wspolrzedna x
-0.2    //wspolrzedna x
-0.1    //wspolrzedna x
0.4     //wspolrzedna x
1.0     //wspolrzedna x
```

Kwadratura Newtona-Cotesa (wzór trapezów)  - liczy całkę z funkcji dla podanego przedziału z daną precyzją
```cpp
double nc_trapez(double, double, int, double(*fun)(double));
```

Kwadratura Newtona-Cotesa (wzór Simpsona)  - liczy całkę z funkcji dla podanego przedziału z daną precyzją
```cpp
double nc_simpson(double, double, int, double(*fun)(double));
```

### *Całkowanie numeryczne*

Metoda prostokątów
```cpp
double rectangular_integration(std::vector<double>, int, int, unsigned int);
```

Metoda trapezów
```cpp
double trapezoidal_integration(std::vector<double>, int, int, unsigned int);
```

### *Kwadratura Gaussa*

```cpp
double gauss_quad(double a, double b, int precision, double(*fun)(double));
```

### *Metoda Eulera:*

```cpp
double euler(double x, double y0, double h, double(*fun)(double, double));
```

### *Metoda Heune'a (ulepszona metoda Eulera):*

```cpp
double heune(double x, double y0, double h, double(*fun)(double, double));
```

### *Zmodyfikowana metoda Eulera:*

```cpp
double euler_mod(double x, double y0, double h, double(*fun)(double, double));
```

### *Metoda Runge-Kutta:*

```cpp
double runge_kutta(double x, double y0, double h, double(*fun)(double, double));
```

## Funkcje pomocnicze: 

Wszystkie znajdują się w ``` MNmath.cpp ```

### *Funkcje matematyczne:*

```cpp
math_pow(x);          //y=x^a
math_exp(x);          //y=x^e
math_linear(x);       //y=a*x
math_const_func(x);   //y=a
math_poly(x);         //wielomian (horner)
p_ciepln(x,y)         //równanie przewodnictwa cieplnego
```

Najlepiej użyć wrappera
```cpp 
math_wrapper(string name, double param); 
``` 
gdzie liczba argumentów zależy od typu funkcji (od 0 do 2 parametrów).

### *Czytanie z pliku wejściowego:*

Czyta dane z pliku wejściowego, domyślny separator:  ```;```

```cpp
std::vector<std::vector<std::string>> readCSV(std::string filename);
```

Czyta dane z pliku wejściowego, umożliwia określenie separatora:

```cpp
std::vector<std::vector<std::string>> readCSV(std::string filename, char delimeter);
```