#include <stdio.h>   // Это библиотека для ввода и вывода. Без неё printf и scanf не работают.
#include <math.h>    // Это библиотека для математики: sin, cos, log, sqrt и т.д.

// Если в системе нет числа Пи (M_PI), определим его сами. Это просто константа 3.14159...
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Функция для возведения числа A в 8-ю степень за 3 умножения (для варианта 7)
double vozvedi_v_8_stepen(double A) {
    // Мы не будем умножать A на себя 7 раз — это долго.
    // Вместо этого: сначала A², потом A⁴ = A² * A², потом A⁸ = A⁴ * A⁴. Всего 3 умножения!
    double A_v_kvadrate = A * A;          // A² — возводим в квадрат (1-е умножение)
    double A_v_4_stepeni = A_v_kvadrate * A_v_kvadrate; // A⁴ — возводим квадрат в квадрат (2-е умножение)
    double A_v_8_stepeni = A_v_4_stepeni * A_v_4_stepeni; // A⁸ — возводим A⁴ в квадрат (3-е умножение)
    return A_v_8_stepeni;  // Возвращаем результат — это и есть A в 8-й степени
}

// ================= ВАРИАНТ 1 =================
void variant1() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 1 ---\n");

    // Задание 1: ввести два числа, найти сумму и произведение
    double chislo1, chislo2;  // Объявляем две переменные для хранения чисел (тип double — для дробных чисел)

    // Просим пользователя ввести два числа
    printf("Введите два положительных числа (через пробел): ");

    // scanf — это функция, которая ЧИТАЕТ то, что ввёл пользователь с клавиатуры
    // "%lf" — это формат: lf = long float, то есть double (дробное число)
    // &chislo1 — амперсанд & означает "адрес переменной". Без него scanf не сможет записать число в переменную.
    // Мы говорим: "Запиши первое число в chislo1, второе — в chislo2"
    scanf("%lf %lf", &chislo1, &chislo2);

    // Считаем сумму и произведение
    double summa = chislo1 + chislo2;      // Складываем — это сумма
    double proizvedenie = chislo1 * chislo2; // Умножаем — это произведение

    // Выводим результаты
    // %.2f — значит: вывести число с плавающей точкой, с 2 знаками после запятой
    printf("Сумма = %.2f\n", summa);
    printf("Произведение = %.2f\n", proizvedenie);

    // Задание 2: переводим метры в футы (1 метр = 3.28084 фута)
    double metry;  // Переменная для хранения метров
    printf("Введите расстояние в метрах: ");
    scanf("%lf", &metry);  // Считываем введённое значение в переменную metry

    // Умножаем метры на коэффициент перевода
    double futy = metry * 3.28084;

    // Выводим результат
    printf("%.2f метров = %.2f футов\n", metry, futy);

    // Задание 3: из трёхзначного числа убрать первую цифру слева и приписать её справа
    int chislo;  // int — целое число (трёхзначное)
    printf("Введите трёхзначное число: ");
    scanf("%d", &chislo);  // %d — формат для целых чисел (int)

    // Как извлечь цифры:
    // chislo / 100 — целая часть деления на 100 → первая цифра (например, 123 / 100 = 1)
    int pervaya_tsifra = chislo / 100;

    // chislo % 100 — остаток от деления на 100 → последние две цифры (123 % 100 = 23)
    int ostalnye_tsifry = chislo % 100;

    // Формируем новое число: сначала последние две цифры * 10 (чтобы освободить место под одну цифру), потом + первая цифра
    // Пример: было 123 → ostalnye_tsifry=23 → 23*10=230 → +1 = 231
    int novoe_chislo = ostalnye_tsifry * 10 + pervaya_tsifra;

    printf("Новое число: %d\n", novoe_chislo);

    // Задание 4: вычисляем две математические функции
    double x;  // Переменная x, в которую пользователь введёт число
    printf("Введите значение x: ");
    scanf("%lf", &x);  // Считываем x

    // Функция 1: ln(x + sqrt(1 + x²))
    // log(...) — натуральный логарифм
    // sqrt(...) — квадратный корень
    // x*x — это x в квадрате
    double funktsiya1 = log(x + sqrt(1 + x*x));
    printf("f(x) = ln(x + sqrt(1+x²)) = %.6f\n", funktsiya1);

    // Функция 2: x*arctg(x) - ln(sqrt(1+x²))
    // atan(x) — арктангенс от x
    double funktsiya2 = x * atan(x) - log(sqrt(1 + x*x));
    printf("f(x) = x*arctg(x) - ln(sqrt(1+x²)) = %.6f\n", funktsiya2);
}

// ================= ВАРИАНТ 2 =================
void variant2() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 2 ---\n");

    // Задание 1: площадь и периметр прямоугольника
    double a, b;  // Стороны прямоугольника
    printf("Введите стороны прямоугольника a и b (через пробел): ");
    scanf("%lf %lf", &a, &b);  // Считываем два числа

    double ploshad = a * b;                // Площадь = длина * ширина
    double perimetr = 2 * (a + b);         // Периметр = сумма всех сторон * 2
    printf("Площадь = %.2f\n", ploshad);
    printf("Периметр = %.2f\n", perimetr);

    // Задание 2: градусы → радианы (формула: радианы = градусы * π / 180)
    double gradusy;
    printf("Введите угол в градусах: ");
    scanf("%lf", &gradusy);

    // M_PI — это наше число Пи (3.14159...), которое мы определили выше
    double radiany = gradusy * M_PI / 180.0;
    printf("%.2f градусов = %.6f радиан\n", gradusy, radiany);

    // Задание 3: из трёхзначного числа убрать последнюю цифру и приписать её в начало
    int chislo;
    printf("Введите трёхзначное число: ");
    scanf("%d", &chislo);

    // Последняя цифра — остаток от деления на 10 (123 % 10 = 3)
    int poslednyaya_tsifra = chislo % 10;

    // Первые две цифры — целая часть от деления на 10 (123 / 10 = 12)
    int pervye_dve_tsifry = chislo / 10;

    // Новое число: последнюю цифру умножаем на 100 (чтобы она стала первой), и прибавляем первые две цифры
    // Пример: 3 * 100 = 300 + 12 = 312
    int novoe_chislo = poslednyaya_tsifra * 100 + pervye_dve_tsifry;
    printf("Новое число: %d\n", novoe_chislo);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: x*cos(x) - sin(x)
    // cos(x) и sin(x) — стандартные функции, принимают x в радианах
    double funktsiya1 = x * cos(x) - sin(x);
    printf("f(x) = x*cos(x) - sin(x) = %.6f\n", funktsiya1);

    // Функция 2: (1 + x²)*arctg(x)
    double funktsiya2 = (1 + x*x) * atan(x);
    printf("f(x) = (1 + x²)*arctg(x) = %.6f\n", funktsiya2);
}

// ================= ВАРИАНТ 3 =================
void variant3() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 3 ---\n");

    // Задание 1: длина окружности и площадь круга по диаметру
    double d;  // Диаметр
    printf("Введите диаметр окружности d: ");
    scanf("%lf", &d);

    // Длина окружности = π * диаметр
    double dlina_okruzhnosti = M_PI * d;

    // Площадь круга = π * радиус², а радиус = d/2
    double ploshad_kruga = M_PI * (d/2) * (d/2);
    printf("Длина окружности = %.2f\n", dlina_okruzhnosti);
    printf("Площадь круга = %.2f\n", ploshad_kruga);

    // Задание 2: радианы → градусы (градусы = радианы * 180 / π)
    double radiany;
    printf("Введите угол в радианах: ");
    scanf("%lf", &radiany);
    double gradusy = radiany * 180.0 / M_PI;
    printf("%.6f радиан = %.2f градусов\n", radiany, gradusy);

    // Задание 3: в трёхзначном числе поменять местами сотни и десятки
    int chislo;
    printf("Введите трёхзначное число: ");
    scanf("%d", &chislo);

    // Извлекаем каждую цифру:
    int sotni = chislo / 100;              // Первая цифра (например, 123 → 1)
    int desyatki = (chislo / 10) % 10;     // Вторая цифра: сначала делим на 10 (123→12), потом берём остаток от деления на 10 (12%10=2)
    int edinitsy = chislo % 10;            // Третья цифра (остаток от деления на 10)

    // Меняем сотни и десятки местами: было 123 (1,2,3) → стало 213 (2,1,3)
    int novoe_chislo = desyatki * 100 + sotni * 10 + edinitsy;
    printf("Новое число: %d\n", novoe_chislo);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: ln(sqrt((1+x)/(1-x)))
    // Сначала считаем дробь (1+x)/(1-x), потом корень, потом логарифм
    double funktsiya1 = log(sqrt((1 + x) / (1 - x)));
    printf("f(x) = ln(sqrt((1+x)/(1-x))) = %.6f\n", funktsiya1);

    // Функция 2: x*arcsin(x) + sqrt(1-x²)
    // asin(x) — арксинус
    double funktsiya2 = x * asin(x) + sqrt(1 - x*x);
    printf("f(x) = x*arcsin(x) + sqrt(1-x²) = %.6f\n", funktsiya2);
}

// ================= ВАРИАНТ 4 =================
void variant4() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 4 ---\n");

    // Задание 1: объём и площадь поверхности куба
    double a;  // Длина ребра
    printf("Введите длину ребра куба a: ");
    scanf("%lf", &a);

    // Объём куба = a * a * a (или a³)
    double obyom = a * a * a;

    // Площадь поверхности = 6 граней, каждая a² → 6*a*a
    double ploshad_poverhnosti = 6 * a * a;
    printf("Объём куба = %.2f\n", obyom);
    printf("Площадь поверхности = %.2f\n", ploshad_poverhnosti);

    // Задание 2: Фаренгейт → Цельсий (C = (F - 32) * 5/9)
    double F;
    printf("Введите температуру в градусах Фаренгейта: ");
    scanf("%lf", &F);
    double C = (F - 32) * 5.0 / 9.0;  // 5.0 и 9.0 — чтобы деление было дробным, а не целочисленным
    printf("%.2f°F = %.2f°C\n", F, C);

    // Задание 3: в трёхзначном числе поменять местами десятки и единицы
    int chislo;
    printf("Введите трёхзначное число: ");
    scanf("%d", &chislo);

    int sotni = chislo / 100;
    int desyatki = (chislo / 10) % 10;
    int edinitsy = chislo % 10;

    // Было ABC → стало ACB
    int novoe_chislo = sotni * 100 + edinitsy * 10 + desyatki;
    printf("Новое число: %d\n", novoe_chislo);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: sin(x) / ((1-x²) * sqrt(1-x²))
    double funktsiya1 = sin(x) / ((1 - x*x) * sqrt(1 - x*x));
    printf("f(x) = sin(x)/((1-x²)sqrt(1-x²)) = %.6f\n", funktsiya1);

    // Функция 2: (1+x)*ln(1+x)
    double funktsiya2 = (1 + x) * log(1 + x);
    printf("f(x) = (1+x)*ln(1+x) = %.6f\n", funktsiya2);
}

// ================= ВАРИАНТ 5 =================
void variant5() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 5 ---\n");

    // Задание 1: площадь кольца (S = π*(R1² - R2²))
    double R1, R2;
    printf("Введите внешний радиус R1 и внутренний R2 (R1 > R2, через пробел): ");
    scanf("%lf %lf", &R1, &R2);

    double ploshad_koltsa = M_PI * (R1*R1 - R2*R2);
    printf("Площадь кольца = %.2f\n", ploshad_koltsa);

    // Задание 2: килограммы → фунты (1 кг ≈ 2.20462 фунта)
    double kg;
    printf("Введите массу в килограммах: ");
    scanf("%lf", &kg);
    double funty = kg * 2.20462;
    printf("%.2f кг = %.2f фунтов\n", kg, funty);

    // Задание 3: сумма цифр трёхзначного числа
    int chislo;
    printf("Введите трёхзначное число: ");
    scanf("%d", &chislo);

    int sotni = chislo / 100;
    int desyatki = (chislo / 10) % 10;
    int edinitsy = chislo % 10;

    int summa_tsifr = sotni + desyatki + edinitsy;
    printf("Сумма цифр = %d\n", summa_tsifr);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: (1/4)*ln((1+x)/(1-x)) + (1/2)*arctg(x)
    double funktsiya1 = 0.25 * log((1 + x) / (1 - x)) + 0.5 * atan(x);
    printf("f(x) = (1/4)*ln((1+x)/(1-x)) + (1/2)*arctg(x) = %.6f\n", funktsiya1);

    // Функция 2: (1+x)*exp(-x)
    // exp(-x) — это e в степени -x (e ≈ 2.718...)
    double funktsiya2 = (1 + x) * exp(-x);
    printf("f(x) = (1+x)*exp(-x) = %.6f\n", funktsiya2);
}

// ================= ВАРИАНТ 6 =================
void variant6() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 6 ---\n");

    // Задание 1: сила притяжения F = G * m1 * m2 / R²
    double m1, m2, R_km;
    printf("Введите массы m1 и m2 (в кг) и расстояние R (в км, через пробел): ");
    scanf("%lf %lf %lf", &m1, &m2, &R_km);

    double G = 6.67430e-11;  // Гравитационная постоянная (очень маленькое число)
    double R_m = R_km * 1000; // Переводим километры в метры (умножаем на 1000)
    double sila = G * m1 * m2 / (R_m * R_m); // Считаем силу по формуле
    printf("Сила притяжения = %.2e Ньютон\n", sila); // %.2e — вывод в научной нотации (например, 1.23e-10)

    // Задание 2: километры → версты (1 км ≈ 0.937383 версты)
    double km;
    printf("Введите расстояние в километрах: ");
    scanf("%lf", &km);
    double versty = km * 0.937383;
    printf("%.2f км = %.2f вёрст\n", km, versty);

    // Задание 3: произведение цифр трёхзначного числа
    int chislo;
    printf("Введите трёхзначное число: ");
    scanf("%d", &chislo);

    int sotni = chislo / 100;
    int desyatki = (chislo / 10) % 10;
    int edinitsy = chislo % 10;

    int proizvedenie_tsifr = sotni * desyatki * edinitsy;
    printf("Произведение цифр = %d\n", proizvedenie_tsifr);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: arctg((2-2x)/(1+4x))
    double funktsiya1 = atan((2 - 2*x) / (1 + 4*x));
    printf("f(x) = arctg((2-2x)/(1+4x)) = %.6f\n", funktsiya1);

    // Функция 2: exp(x)*cos(x)
    double funktsiya2 = exp(x) * cos(x);
    printf("f(x) = exp(x)*cos(x) = %.6f\n", funktsiya2);
}

// ================= ВАРИАНТ 7 =================
void variant7() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 7 ---\n");

    // Задание 1: возвести A в 8-ю степень за 3 умножения
    double A;
    printf("Введите число A: ");
    scanf("%lf", &A);

    // Считаем по шагам:
    double A2 = A * A;          // A² — первое умножение
    double A4 = A2 * A2;        // A⁴ — второе умножение
    double A8 = A4 * A4;        // A⁸ — третье умножение

    printf("A² = %.6f\n", A2);
    printf("A⁴ = %.6f\n", A4);
    printf("A⁸ = %.6f\n", A8);

    // Задание 2: метры → ярды (1 м ≈ 1.09361 ярда)
    double metry;
    printf("Введите расстояние в метрах: ");
    scanf("%lf", &metry);
    double yardy = metry * 1.09361;
    printf("%.2f метров = %.2f ярдов\n", metry, yardy);

    // Задание 3: поменять старшие цифры у двух трёхзначных чисел
    int chislo1, chislo2;
    printf("Введите два трёхзначных числа (через пробел): ");
    scanf("%d %d", &chislo1, &chislo2);

    // Извлекаем старшие цифры (сотни)
    int sotni1 = chislo1 / 100;
    int sotni2 = chislo2 / 100;

    // Извлекаем оставшиеся две цифры (десятки и единицы)
    int ostatok1 = chislo1 % 100;
    int ostatok2 = chislo2 % 100;

    // Меняем старшие цифры местами:
    int novoe1 = sotni2 * 100 + ostatok1;  // У первого числа теперь старшая цифра от второго
    int novoe2 = sotni1 * 100 + ostatok2;  // У второго — от первого

    printf("После обмена старшими цифрами:\n");
    printf("Первое число стало: %d\n", novoe1);
    printf("Второе число стало: %d\n", novoe2);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: exp(x)*sin(x)
    double funktsiya1 = exp(x) * sin(x);
    printf("f(x) = exp(x)*sin(x) = %.6f\n", funktsiya1);

    // Функция 2: (1-x²)*ln(1+x)
    double funktsiya2 = (1 - x*x) * log(1 + x);
    printf("f(x) = (1-x²)*ln(1+x) = %.6f\n", funktsiya2);
}

// ================= ГЛАВНАЯ ФУНКЦИЯ (с которой начинается выполнение программы) =================
int main() {
    printf("============================================\n");
    printf(" ЛАБОРАТОРНАЯ РАБОТА ПО ЯЗЫКУ C (2 КУРС) \n");
    printf("       ВСЕ 7 ВАРИАНТОВ В ОДНОЙ ПРОГРАММЕ    \n");
    printf("============================================\n");

    int nomer_varianta;  // Переменная, куда запишем номер выбранного варианта
    printf("\nВыберите вариант (введите цифру от 1 до 7): ");

    // Считываем целое число, которое ввёл пользователь
    // %d — потому что nomer_varianta — это int (целое число)
    // &nomer_varianta — передаём адрес переменной, чтобы scanf могла туда записать значение
    scanf("%d", &nomer_varianta);

    // Ветвление: в зависимости от введённого номера — вызываем нужную функцию
    switch (nomer_varianta) {
        case 1:
            variant1();  // Вызываем функцию варианта 1
            break;       // break — чтобы не выполнять следующие case
        case 2:
            variant2();
            break;
        case 3:
            variant3();
            break;
        case 4:
            variant4();
            break;
        case 5:
            variant5();
            break;
        case 6:
            variant6();
            break;
        case 7:
            variant7();
            break;
        default:
            // Если ввели не от 1 до 7 — выводим ошибку
            printf("Ошибка! Нужно ввести число от 1 до 7.\n");
            return 1;  // return 1 — программа завершается с ошибкой
    }

    printf("\n============================================\n");
    printf("    РАБОТА ВЫПОЛНЕНА. МОЖНО СДАВАТЬ! 😉     \n");
    printf("============================================\n");

    return 0;  // return 0 — программа завершилась успешно
}