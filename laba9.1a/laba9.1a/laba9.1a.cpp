
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialty { КН, МЕ, ТН, ІФ, ФІ };

string strSpecialty[] = { "КН","МЕ","ТН","ІФ","ФІ" };

struct Student
{
    string prizv;
    Specialty specialty;
    short unsigned kurs;
    short unsigned physics;
    short unsigned math;
    union
    {
        short unsigned programming;
        short unsigned methods;
        short unsigned pedagogika;
    };

};

void create(Student* s, const int N);
void print(Student* s, const int N);
double average_mark(Student& s);
void print_average_marks(Student* s, const int N);
double physics_five_four(Student* s, const int N);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: "; cin >> N;
    Student* s = new Student[N];
    create(s, N);
    print(s, N);
    print_average_marks(s, N);
    cout << "| Процент студентів які отримали з фізики " << char(34) << "4" << char(34) << " або " << char(34) << "5" << char(34) << ": " << fixed << setw(6) << setprecision(2) << physics_five_four(s, N) << "%" << setw(51) << "|" << endl;
    cout << "=================================================================================================================" << endl;
    delete[] s;
}

void create(Student* s, const int N)
{
    int kurs = 0, specialty;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент№ " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << "  прізвище: "; getline(cin, s[i].prizv);
        cout << "  курс: "; cin >> s[i].kurs;
        cout << "  спеціальність (0 - Комп'ютерні науки, 1 - Математика та економіка, 2 - Трудове навчання, 3 - Інформатика, 4 - Фізика та інформатика): "; cin >> specialty;
        s[i].specialty = (Specialty)specialty;
        cout << "  оцінка з фізики: "; cin >> s[i].physics;
        cout << "  оцінка з математики: "; cin >> s[i].math;
        switch (specialty)
        {
        case 0:
            cout << "  оцінка з програмування: "; cin >> s[i].programming;
            break;
        case 3:
            cout << "  оцінка з чисельних методів: "; cin >> s[i].methods;
            break;
        case 1:
        case 2:
        case 4:
            cout << "  оцінка з педагогіки: "; cin >> s[i].pedagogika;
            break;
        }

    }
}

void print(Student* s, const int N)
{
    cout << "================================================================================================================="
        << endl;
    cout << "| №  | Прізвище     | Курс | Спеціальність | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
        << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(13) << left << s[i].prizv
            << "| " << setw(3) << right << s[i].kurs << "  "
            << "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
            << "| " << setw(4) << right << s[i].physics << "   "
            << "| " << setw(6) << right << s[i].math << "     ";
        switch (s[i].specialty)
        {
        case 0:
            cout << "| " << setw(7) << right << s[i].programming << "       |" << setw(18) << "|" << setw(13) << "|" << endl;
            break;
        case 3:
            cout << "| " << setw(15) << "|" << setw(10) << right << s[i].methods << "       |" << setw(13) << "|" << endl;
            break;
        case 1:
        case 2:
        case 4:
            cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].pedagogika << "     |" << endl;
            break;
        }
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        
    }
    cout << "=================================================================================================================" << endl;
}

double average_mark(Student& s)
{
    return (s.physics + s.math + s.programming) / 3.;
}
void print_average_marks(Student* s, const int N)
{
    cout << "| Середні оцінки: " << setw(95) << "|" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|    " << i + 1 << ") " << setw(10) << left << s[i].prizv << " - " << setw(4) << left << setprecision(3) << average_mark(s[i]) << right << setw(89) << " | " << endl;
    }
}

double physics_five_four(Student* s, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (s[i].physics == 4 || s[i].physics == 5)
            k++;
    return 100.0 * k / N;
}