# Metody Numeryczne 2019
semestr 4 AGH WIMiIP

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
1.0;12.0     //punkt
```
