#include <stdio.h>   // Это библиотека для ввода и вывода. Без неё printf и scanf не работают.
#include <math.h>    // Это библиотека для математики: sin, cos, log, sqrt и т.д.

// Если в системе нет числа Пи (M_PI), определим его сами. Это просто константа 3.14159...
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Функция для возведения числа A в 8-ю степень за 3 умножения (для варианта 7)
double power_8_fast(double base) {
    // Мы не будем умножать A на себя 7 раз — это долго.
    // Вместо этого: сначала A², потом A⁴ = A² * A², потом A⁸ = A⁴ * A⁴. Всего 3 умножения!
    double square = base * base;          // A² — возводим в квадрат (1-е умножение)
    double fourth = square * square;      // A⁴ — возводим квадрат в квадрат (2-е умножение)
    double eighth = fourth * fourth;      // A⁸ — возводим A⁴ в квадрат (3-е умножение)
    return eighth;  // Возвращаем результат — это и есть A в 8-й степени
}

// ================= ВАРИАНТ 1 =================
void execute_variant_1() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 1 ---\n");

    // Задание 1: ввести два числа, найти сумму и произведение
    double num1, num2;  // Объявляем две переменные для хранения чисел (тип double — для дробных чисел)

    // Просим пользователя ввести два числа
    printf("Введите два положительных числа (через пробел): ");

    // scanf — это функция, которая ЧИТАЕТ то, что ввёл пользователь с клавиатуры
    // "%lf" — это формат: lf = long float, то есть double (дробное число)
    // &chislo1 — амперсанд & означает "адрес переменной". Без него scanf не сможет записать число в переменную.
    // Мы говорим: "Запиши первое число в chislo1, второе — в chislo2"
    scanf("%lf %lf", &num1, &num2);

    // Считаем сумму и произведение
    double sum_result = num1 + num2;      // Складываем — это сумма
    double product_result = num1 * num2;  // Умножаем — это произведение

    // Выводим результаты
    // %.2f — значит: вывести число с плавающей точкой, с 2 знаками после запятой
    printf("Сумма = %.2f\n", sum_result);
    printf("Произведение = %.2f\n", product_result);

    // Задание 2: переводим метры в футы (1 метр = 3.28084 фута)
    double meters;  // Переменная для хранения метров
    printf("Введите расстояние в метрах: ");
    scanf("%lf", &meters);  // Считываем введённое значение в переменную metry

    // Умножаем метры на коэффициент перевода
    double feet = meters * 3.28084;

    // Выводим результат
    printf("%.2f метров = %.2f футов\n", meters, feet);

    // Задание 3: из трёхзначного числа убрать первую цифру слева и приписать её справа
    int input_number;  // int — целое число (трёхзначное)
    printf("Введите трёхзначное число: ");
    scanf("%d", &input_number);  // %d — формат для целых чисел (int)

    // Как извлечь цифры:
    // chislo / 100 — целая часть деления на 100 → первая цифра (например, 123 / 100 = 1)
    int first_digit = input_number / 100;

    // chislo % 100 — остаток от деления на 100 → последние две цифры (123 % 100 = 23)
    int last_two_digits = input_number % 100;

    // Формируем новое число: сначала последние две цифры * 10 (чтобы освободить место под одну цифру), потом + первая цифра
    // Пример: было 123 → ostalnye_tsifry=23 → 23*10=230 → +1 = 231
    int rotated_number = last_two_digits * 10 + first_digit;

    printf("Новое число: %d\n", rotated_number);

    // Задание 4: вычисляем две математические функции
    double x;  // Переменная x, в которую пользователь введёт число
    printf("Введите значение x: ");
    scanf("%lf", &x);  // Считываем x

    // Функция 1: ln(x + sqrt(1 + x²))
    // log(...) — натуральный логарифм
    // sqrt(...) — квадратный корень
    // x*x — это x в квадрате
    double func1 = log(x + sqrt(1 + x*x));
    printf("f(x) = ln(x + sqrt(1+x²)) = %.6f\n", func1);

    // Функция 2: x*arctg(x) - ln(sqrt(1+x²))
    // atan(x) — арктангенс от x
    double func2 = x * atan(x) - log(sqrt(1 + x*x));
    printf("f(x) = x*arctg(x) - ln(sqrt(1+x²)) = %.6f\n", func2);
}

// ================= ВАРИАНТ 2 =================
void execute_variant_2() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 2 ---\n");

    // Задание 1: площадь и периметр прямоугольника
    double side_a, side_b;  // Стороны прямоугольника
    printf("Введите стороны прямоугольника a и b (через пробел): ");
    scanf("%lf %lf", &side_a, &side_b);  // Считываем два числа

    double area = side_a * side_b;                // Площадь = длина * ширина
    double perimeter = 2 * (side_a + side_b);     // Периметр = сумма всех сторон * 2
    printf("Площадь = %.2f\n", area);
    printf("Периметр = %.2f\n", perimeter);

    // Задание 2: градусы → радианы (формула: радианы = градусы * π / 180)
    double degrees;
    printf("Введите угол в градусах: ");
    scanf("%lf", &degrees);

    // M_PI — это наше число Пи (3.14159...), которое мы определили выше
    double radians = degrees * M_PI / 180.0;
    printf("%.2f градусов = %.6f радиан\n", degrees, radians);

    // Задание 3: из трёхзначного числа убрать последнюю цифру и приписать её в начало
    int input_number;
    printf("Введите трёхзначное число: ");
    scanf("%d", &input_number);

    // Последняя цифра — остаток от деления на 10 (123 % 10 = 3)
    int last_digit = input_number % 10;

    // Первые две цифры — целая часть от деления на 10 (123 / 10 = 12)
    int first_two_digits = input_number / 10;

    // Новое число: последнюю цифру умножаем на 100 (чтобы она стала первой), и прибавляем первые две цифры
    // Пример: 3 * 100 = 300 + 12 = 312
    int rotated_number = last_digit * 100 + first_two_digits;
    printf("Новое число: %d\n", rotated_number);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: x*cos(x) - sin(x)
    // cos(x) и sin(x) — стандартные функции, принимают x в радианах
    double func1 = x * cos(x) - sin(x);
    printf("f(x) = x*cos(x) - sin(x) = %.6f\n", func1);

    // Функция 2: (1 + x²)*arctg(x)
    double func2 = (1 + x*x) * atan(x);
    printf("f(x) = (1 + x²)*arctg(x) = %.6f\n", func2);
}

// ================= ВАРИАНТ 3 =================
void execute_variant_3() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 3 ---\n");

    // Задание 1: длина окружности и площадь круга по диаметру
    double diameter;  // Диаметр
    printf("Введите диаметр окружности d: ");
    scanf("%lf", &diameter);

    // Длина окружности = π * диаметр
    double circumference = M_PI * diameter;

    // Площадь круга = π * радиус², а радиус = d/2
    double circle_area = M_PI * (diameter/2) * (diameter/2);
    printf("Длина окружности = %.2f\n", circumference);
    printf("Площадь круга = %.2f\n", circle_area);

    // Задание 2: радианы → градусы (градусы = радианы * 180 / π)
    double radians;
    printf("Введите угол в радианах: ");
    scanf("%lf", &radians);
    double degrees = radians * 180.0 / M_PI;
    printf("%.6f радиан = %.2f градусов\n", radians, degrees);

    // Задание 3: в трёхзначном числе поменять местами сотни и десятки
    int input_number;
    printf("Введите трёхзначное число: ");
    scanf("%d", &input_number);

    // Извлекаем каждую цифру:
    int hundreds = input_number / 100;              // Первая цифра (например, 123 → 1)
    int tens = (input_number / 10) % 10;            // Вторая цифра: сначала делим на 10 (123→12), потом берём остаток от деления на 10 (12%10=2)
    int units = input_number % 10;                  // Третья цифра (остаток от деления на 10)

    // Меняем сотни и десятки местами: было 123 (1,2,3) → стало 213 (2,1,3)
    int swapped_number = tens * 100 + hundreds * 10 + units;
    printf("Новое число: %d\n", swapped_number);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: ln(sqrt((1+x)/(1-x)))
    // Сначала считаем дробь (1+x)/(1-x), потом корень, потом логарифм
    double func1 = log(sqrt((1 + x) / (1 - x)));
    printf("f(x) = ln(sqrt((1+x)/(1-x))) = %.6f\n", func1);

    // Функция 2: x*arcsin(x) + sqrt(1-x²)
    // asin(x) — арксинус
    double func2 = x * asin(x) + sqrt(1 - x*x);
    printf("f(x) = x*arcsin(x) + sqrt(1-x²) = %.6f\n", func2);
}

// ================= ВАРИАНТ 4 =================
void execute_variant_4() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 4 ---\n");

    // Задание 1: объём и площадь поверхности куба
    double edge_length;  // Длина ребра
    printf("Введите длину ребра куба a: ");
    scanf("%lf", &edge_length);

    // Объём куба = a * a * a (или a³)
    double volume = edge_length * edge_length * edge_length;

    // Площадь поверхности = 6 граней, каждая a² → 6*a*a
    double surface_area = 6 * edge_length * edge_length;
    printf("Объём куба = %.2f\n", volume);
    printf("Площадь поверхности = %.2f\n", surface_area);

    // Задание 2: Фаренгейт → Цельсий (C = (F - 32) * 5/9)
    double fahrenheit;
    printf("Введите температуру в градусах Фаренгейта: ");
    scanf("%lf", &fahrenheit);
    double celsius = (fahrenheit - 32) * 5.0 / 9.0;  // 5.0 и 9.0 — чтобы деление было дробным, а не целочисленным
    printf("%.2f°F = %.2f°C\n", fahrenheit, celsius);

    // Задание 3: в трёхзначном числе поменять местами десятки и единицы
    int input_number;
    printf("Введите трёхзначное число: ");
    scanf("%d", &input_number);

    int hundreds = input_number / 100;
    int tens = (input_number / 10) % 10;
    int units = input_number % 10;

    // Было ABC → стало ACB
    int swapped_number = hundreds * 100 + units * 10 + tens;
    printf("Новое число: %d\n", swapped_number);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: sin(x) / ((1-x²) * sqrt(1-x²))
    double func1 = sin(x) / ((1 - x*x) * sqrt(1 - x*x));
    printf("f(x) = sin(x)/((1-x²)sqrt(1-x²)) = %.6f\n", func1);

    // Функция 2: (1+x)*ln(1+x)
    double func2 = (1 + x) * log(1 + x);
    printf("f(x) = (1+x)*ln(1+x) = %.6f\n", func2);
}

// ================= ВАРИАНТ 5 =================
void execute_variant_5() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 5 ---\n");

    // Задание 1: площадь кольца (S = π*(R1² - R2²))
    double outer_radius, inner_radius;
    printf("Введите внешний радиус R1 и внутренний R2 (R1 > R2, через пробел): ");
    scanf("%lf %lf", &outer_radius, &inner_radius);

    double ring_area = M_PI * (outer_radius*outer_radius - inner_radius*inner_radius);
    printf("Площадь кольца = %.2f\n", ring_area);

    // Задание 2: килограммы → фунты (1 кг ≈ 2.20462 фунта)
    double kilograms;
    printf("Введите массу в килограммах: ");
    scanf("%lf", &kilograms);
    double pounds = kilograms * 2.20462;
    printf("%.2f кг = %.2f фунтов\n", kilograms, pounds);

    // Задание 3: сумма цифр трёхзначного числа
    int input_number;
    printf("Введите трёхзначное число: ");
    scanf("%d", &input_number);

    int hundreds = input_number / 100;
    int tens = (input_number / 10) % 10;
    int units = input_number % 10;

    int digit_sum = hundreds + tens + units;
    printf("Сумма цифр = %d\n", digit_sum);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: (1/4)*ln((1+x)/(1-x)) + (1/2)*arctg(x)
    double func1 = 0.25 * log((1 + x) / (1 - x)) + 0.5 * atan(x);
    printf("f(x) = (1/4)*ln((1+x)/(1-x)) + (1/2)*arctg(x) = %.6f\n", func1);

    // Функция 2: (1+x)*exp(-x)
    // exp(-x) — это e в степени -x (e ≈ 2.718...)
    double func2 = (1 + x) * exp(-x);
    printf("f(x) = (1+x)*exp(-x) = %.6f\n", func2);
}

// ================= ВАРИАНТ 6 =================
void execute_variant_6() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 6 ---\n");

    // Задание 1: сила притяжения F = G * m1 * m2 / R²
    double mass1, mass2, distance_km;
    printf("Введите массы m1 и m2 (в кг) и расстояние R (в км, через пробел): ");
    scanf("%lf %lf %lf", &mass1, &mass2, &distance_km);

    double G = 6.67430e-11;  // Гравитационная постоянная (очень маленькое число)
    double distance_m = distance_km * 1000; // Переводим километры в метры (умножаем на 1000)
    double force = G * mass1 * mass2 / (distance_m * distance_m); // Считаем силу по формуле
    printf("Сила притяжения = %.2e Ньютон\n", force); // %.2e — вывод в научной нотации (например, 1.23e-10)

    // Задание 2: километры → версты (1 км ≈ 0.937383 версты)
    double kilometers;
    printf("Введите расстояние в километрах: ");
    scanf("%lf", &kilometers);
    double versts = kilometers * 0.937383;
    printf("%.2f км = %.2f вёрст\n", kilometers, versts);

    // Задание 3: произведение цифр трёхзначного числа
    int input_number;
    printf("Введите трёхзначное число: ");
    scanf("%d", &input_number);

    int hundreds = input_number / 100;
    int tens = (input_number / 10) % 10;
    int units = input_number % 10;

    int digit_product = hundreds * tens * units;
    printf("Произведение цифр = %d\n", digit_product);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: arctg((2-2x)/(1+4x))
    double func1 = atan((2 - 2*x) / (1 + 4*x));
    printf("f(x) = arctg((2-2x)/(1+4x)) = %.6f\n", func1);

    // Функция 2: exp(x)*cos(x)
    double func2 = exp(x) * cos(x);
    printf("f(x) = exp(x)*cos(x) = %.6f\n", func2);
}

// ================= ВАРИАНТ 7 =================
void execute_variant_7() {
    printf("\n--- ВЫПОЛНЯЕМ ВАРИАНТ 7 ---\n");

    // Задание 1: возвести A в 8-ю степень за 3 умножения
    double base;
    printf("Введите число A: ");
    scanf("%lf", &base);

    // Считаем по шагам:
    double squared = base * base;          // A² — первое умножение
    double fourth = squared * squared;     // A⁴ — второе умножение
    double eighth = fourth * fourth;       // A⁸ — третье умножение

    printf("A² = %.6f\n", squared);
    printf("A⁴ = %.6f\n", fourth);
    printf("A⁸ = %.6f\n", eighth);

    // Задание 2: метры → ярды (1 м ≈ 1.09361 ярда)
    double meters;
    printf("Введите расстояние в метрах: ");
    scanf("%lf", &meters);
    double yards = meters * 1.09361;
    printf("%.2f метров = %.2f ярдов\n", meters, yards);

    // Задание 3: поменять старшие цифры у двух трёхзначных чисел
    int number1, number2;
    printf("Введите два трёхзначных числа (через пробел): ");
    scanf("%d %d", &number1, &number2);

    // Извлекаем старшие цифры (сотни)
    int hundreds1 = number1 / 100;
    int hundreds2 = number2 / 100;

    // Извлекаем оставшиеся две цифры (десятки и единицы)
    int remainder1 = number1 % 100;
    int remainder2 = number2 % 100;

    // Меняем старшие цифры местами:
    int new_number1 = hundreds2 * 100 + remainder1;  // У первого числа теперь старшая цифра от второго
    int new_number2 = hundreds1 * 100 + remainder2;  // У второго — от первого

    printf("После обмена старшими цифрами:\n");
    printf("Первое число стало: %d\n", new_number1);
    printf("Второе число стало: %d\n", new_number2);

    // Задание 4: вычисляем две функции
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Функция 1: exp(x)*sin(x)
    double func1 = exp(x) * sin(x);
    printf("f(x) = exp(x)*sin(x) = %.6f\n", func1);

    // Функция 2: (1-x²)*ln(1+x)
    double func2 = (1 - x*x) * log(1 + x);
    printf("f(x) = (1-x²)*ln(1+x) = %.6f\n", func2);
}

// ================= ГЛАВНАЯ ФУНКЦИЯ (с которой начинается выполнение программы) =================
int main() {
    printf("============================================\n");
    printf(" ЛАБОРАТОРНАЯ РАБОТА ПО ЯЗЫКУ C (2 КУРС) \n");
    printf("       ВСЕ 7 ВАРИАНТОВ В ОДНОЙ ПРОГРАММЕ    \n");
    printf("============================================\n");

    int selected_variant;  // Переменная, куда запишем номер выбранного варианта
    printf("\nВыберите вариант (введите цифру от 1 до 7): ");

    // Считываем целое число, которое ввёл пользователь
    // %d — потому что nomer_varianta — это int (целое число)
    // &nomer_varianta — передаём адрес переменной, чтобы scanf могла туда записать значение
    scanf("%d", &selected_variant);

    // Ветвление: в зависимости от введённого номера — вызываем нужную функцию
    switch (selected_variant) {
        case 1:
            execute_variant_1();  // Вызываем функцию варианта 1
            break;       // break — чтобы не выполнять следующие case
        case 2:
            execute_variant_2();
            break;
        case 3:
            execute_variant_3();
            break;
        case 4:
            execute_variant_4();
            break;
        case 5:
            execute_variant_5();
            break;
        case 6:
            execute_variant_6();
            break;
        case 7:
            execute_variant_7();
            break;
        default:
            // Если ввели не от 1 до 7 — выводим ошибку
            printf("Ошибка! Нужно ввести число от 1 до 7.\n");
            return 1;  // return 1 — программа завершается с ошибкой
    }

    printf("\n============================================\n");
    printf("    РАБОТА ВЫПОЛНЕНА. МОЖНО СДАВАТЬ!    \n");
    printf("============================================\n");

    return 0;  // return 0 — программа завершилась успешно
}
