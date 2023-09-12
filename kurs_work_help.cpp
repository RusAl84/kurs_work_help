#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#define _SRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)
using namespace std;
class exam
{
private:
    int numsess;
    string subj;
    int mark;
public:
    void getmark(int a)
    {
        a = mark;
    }
    void markuc()
    {
        mark = -1;
    }
    void copy(exam a, exam b)
    {
        b.numsess = a.numsess;
        b.subj = a.subj;
        b.mark = a.mark;
    }
    void print()
    {
        cout << endl << "Введите номер сессии:" << endl;
        cin >> numsess;
        cout << endl << "Введите название предмета:" << endl;
        cin >> subj;
        cout << endl << "Введите результат сдачи экзамена/зачета(либо оценку , либо 1 если зачет/0 если незачет) :" << endl;
        cin >> mark;
        if (mark > 5 or mark < 0)
        {
            while (mark > 5 or mark < 0)
            {
                cout << endl << "Введите результат сдачи экзамена/зачета(либо оценку , либо 1 если зачет/0 если незачет) :" << endl;
                cin >> mark;
            }
        }
    }
    void set()
    {
        cout << endl << "сессия №" << numsess << endl << subj << endl;
        if (mark > 1)
        {
            cout << "оценка " << mark << endl;
        }
        else
        {
            if (mark == 0)
            {
                cout << "оценка незачет";
            }
            else
            {
                cout << "оценка зачет";
            }
        }
    }
};
class date
{
public:
    unsigned short int day;
    unsigned short int month;
    int year;
    void getybd(int b)
    {
        b = year;
    }
};
class student :date
{
private:
    string n1;
    string n2;
    string n3;
    string inst;
    int yor;
    bool sex;
    string noc;
    string nog;
    string noz;
     exam roe[90];
public:
    void set()
    {
        cout << endl << "Введите фамилию студента";
        cin >> n1;
        cout << endl << "Введите имя студента";
        cin >> n2;
        cout << endl << "Введите отчество студента";
        cin >> n3;
        cout << endl << "Введите год поступления студента в вуз";
        cin >> yor;
        cout << endl << "Введите название института";
        cin >> inst;
        cout << endl << "Введите название кафедры";
        cin >> noc;
        cout << endl << "Введите название группы";
        cin >> nog;
        cout << endl << "Введите номер зачетной книжки студента";
        cin >> noz;
        cout << endl << "Введите пол студента(мужской-0, женский-1)";
        cin >> sex;
        cout << endl << "Введите день рождения:" << endl;
        cin >> day;
        cout << endl << "Введите месяц рождения:" << endl;
        cin >> month;
        cout << endl << "Введите год рождения:" << endl;
        cin >> year;
        int i = 0;
        bool x = 0;
        while (true)

        {
            cout << endl << "Следующий экзамен - 1/закончить ввод данных - 0";
            cin >> x;
            if (x == 0)
            {
                for (int p = i; p < 90; p++)
                {
                    roe[p].markuc();
                }
                cout << endl;
                break;
            }
            roe[i].set();
            i++;
        }
    }
    void print()
    {
        cout << endl << n1 << endl << n2 << endl << n3 << endl << day << "." << month << "." << year << endl << sex << endl << yor << endl;
        cout << inst << endl << noc << endl << nog << endl << noz << endl;
        for (int i = 0; i < sizeof(roe) / sizeof(exam); i++)
        {
            roe[i].print();
        }
    }
    void copy(student a, student b)
    {
        b.n1 = a.n1;
        b.n2 = a.n2;
        b.n3 = a.n3;
        b.inst = a.inst;
        b.yor = a.yor;
        b.sex = a.sex;
        b.noc = a.noc;
        b.nog = a.nog;
        b.nog = a.noz;
        for (int l = 0; l < 90; l++)
        {
            b.roe[l].copy(a.roe[l], b.roe[l]);
        }
    }
    void avgm(float b)
    {
        float sum = 0;
        int c = 0;
        int counter = 0;
        for (int a = 0; a < 90; a++)
        {
            roe[a].getmark(c);
            if (c == -1)
            {
                b = sum / counter;
                break;
            }
            roe[a].getmark(c);
            sum += c;
            counter++;
        }
    }
    void getz(string b)
    {
        b = noz;
    }
    void getg(string b)
    {
        b = nog;
    }
    void get1n(string b)
    {
        b = n1;
    }
    void getyor(int b)
    {
        b = yor;
    }
};




int main()
{
    int i = -1, j = 0;
    string massbukv = { "АБВГДЕЁЖЗИЙКЛМНОП" };
    string str, str1;
    string filename = "DataKursOst.txt";
    const char* cch = "DataKursOst.txt";
    ifstream fin;
    student t;
    fin.open(filename, ofstream::app);
    setlocale(LC_ALL, "ru");
    student* mass = new student[0];
    student* masst = new student[0];
    if (!fin.is_open())
    {
        FILE* file;

        file = fopen(cch, "wb+");
        fclose(file);
    }
    else
    {
        while (fin.read((char*)&t, sizeof(student)))
        {
            i++;
        }
        student* mass = new student[i];
        student* masst = new student[i];
        j = i;
        i = 0;
        while (fin.read((char*)&t, sizeof(student)))
        {
            mass[i] = t;

        }
        fin.close();
    }
    cout << endl << "Здравствуйте.";
    int bre = 0;
    while (true)
    {
        cout << "Для добавления новых данных нажмите 0" << endl;
        cout << "Для изменения уже записанных данных нажмите 1" << endl;
        cout << "Для вывода данных нажмите 2";
        cout << "Для завершения работы программы нажмите 3" << endl;
        cin >> i;
        while (i < 0 or i>5)
        {
            cout << endl << "Был введен недопустимый код , пожалуйста повторите попытку" << endl;
            cout << "Для добавления новых данных нажмите 0" << endl;
            cout << "Для изменения уже записанных данных нажмите 1" << endl;
            cout << "Для вывода данных нажмите 2";
            cout << "Для завершения работы программы нажмите 3" << endl;;
            cin >> i;
        }
        switch (i)
        {
        case 0:
            cout << "информацию о скольких студентах необходимо добавить?";
            cin >> i;
            mass[j + i];
            i = 0;
            for (int k = 0; k <= i + j; k++)
            {
                if (k > j or k == j)
                {
                    mass[k] = masst[k];
                }
                else
                {
                    if (k == j + 1)
                    {
                        student* masst = new student[j + i];
                    }
                    mass[i].set();
                    mass[k].copy(mass[k], masst[k]);

                }
            }
            j = i + j;
            break;

        case 1:
            cout << endl << "ВВедите номер зачетной книжки" << endl;
            cin >> str;
            for (int k = 0; k <= j; k++)
            {
                mass[k].getz(str1);
                if (str1 == str)
                {
                    mass[k].set();
                    break;
                }
            }
            break;

        case 2:
            while (i < 0 or i>1)
            {
                cout << endl << "Если хотите вывести индивидуальную информацию нажмите 0" << endl;
                cout << endl << "Если хотите вывод по заданию в зачетке нажмите 1" << endl;
                cin >> i;
            }
            if (i == 0)
            {
                cout << endl << "ВВедите номер зачетной книжки" << endl;
                cin >> str;
                for (int k = 0; k <= j; k++)
                {
                    mass[k].getz(str1);
                    if (str1 == str)
                    {
                        mass[k].print();
                        break;
                    }
                }
            }
            else
            {
                int ch1 = 0;
                cout << endl << "ВВедите номер группы" << endl;
                cin >> str;
                for (int k = 0; k <= j; k++)
                {
                    mass[k].getg(str1);
                    if (str1 == str)
                    {
                        ch1++;
                    }
                }
                const int ch = ch1;
                student* mass1 = new student[ch - 1];
                int count = 0;
                for (int k = 0; k <= j; k++)
                {
                    mass[k].getg(str1);
                    if (str1 == str)
                    {
                        count++;
                        mass[k].copy(mass[k], mass1[count]);
                    }
                }
                count = 0;
                for (int k = 0; k < ch; k++)
                {
                    for (int n = 0; n < sizeof(massbukv) / sizeof(massbukv[0]); n++)
                    {
                        mass1[k].get1n(str);
                        if (str[0] == massbukv[n])
                        {
                            count++;
                        }
                    }
                }
                student* mass2 = new student[count - 1];
                student* mass3 = new student[ch - count - 1];
                int count2 = 0;
                int count1 = 0;
                for (int k = 0; k < ch; k++)
                {
                    for (int n = 0; n < sizeof(massbukv) / sizeof(massbukv[0]); n++)
                    {
                        mass1[k].get1n(str);
                        if (str[0] == massbukv[n])
                        {
                            mass1[k].copy(mass1[k], mass2[count2]);
                            count2++;
                        }
                        else
                        {
                            if (n == sizeof(massbukv) / sizeof(massbukv[0]) - 1)
                            {
                                mass1[k].copy(mass1[k], mass3[count1]);
                                count1++;
                            }
                        }
                    }
                }
                float avg1, avg2;
                avg1 = 0;
                avg2 = 0;
                for (int q = 0; q < count - 1; q++)
                {
                    for (int w = 0; w < count - 1; w++)
                    {
                        mass2[w].avgm(avg1);
                        mass2[w + 1].avgm(avg2);
                        if (avg1 > avg2)
                        {
                            mass2[w].copy(mass2[w], t);
                            mass2[w + 1].copy(mass2[w + 1], mass2[w]);
                            t.copy(t, mass2[w + 1]);
                        }
                    }
                }
                for (int q = 0; q < ch - count - 1; q++)
                {
                    for (int w = 0; w < ch - count - 1; w++)
                    {
                        mass3[w].avgm(avg1);
                        mass3[w + 1].avgm(avg2);
                        if (avg1 > avg2)
                        {
                            mass3[w].copy(mass3[w], t);
                            mass3[w + 1].copy(mass3[w + 1], mass3[w]);
                            t.copy(t, mass3[w + 1]);
                        }
                    }
                }
                cout << endl << "Если необходимо вывести массив нажмите 0" << endl;
                cout << endl << "Если необходимо поиск среди студентов с указанием интервала года рождения нажмите 1" << endl;
                cin >> count1;
                while (count1 > 1 or count1 < 0)
                {
                    cout << endl << "Если необходимо вывести подгруппу нажмите 0" << endl;
                    cout << endl << "Если необходимо поиск среди студентов с указанием интервала года рождения нажмите 1" << endl;
                    cin >> count1;
                }
                if (count1 == 0)
                {
                    cout << endl << "Если необходимо вывести 1ую подгруппу нажмите 0" << endl;
                    cout << endl << "Если необходимо вывести 2ую подгруппу нажмите 1" << endl;
                    cin >> count2;
                    while (count2 > 1 or count2 < 0)
                    {
                        cout << endl << "Если необходимо вывести 1ую подгруппу нажмите 0" << endl;
                        cout << endl << "Если необходимо вывести 2ую подгруппу нажмите 1" << endl;
                        cin >> count2;
                    }
                    if (count2 == 0)
                    {
                        for (int q = 0; q < count - 1; q++)
                        {
                            mass2[q].print();
                        }
                    }
                    else
                    {
                        for (int q = 0; q < ch - count - 1; q++)
                        {
                            mass3[q].print();
                        }
                    }
                }
                else
                {
                    cout << endl << "Если необходимо провести поиск по 1ой подгруппе нажмите 0" << endl;
                    cout << endl << "Если необходимо провести поиск по 2ой подгруппе нажмите 1" << endl;
                    cin >> count2;
                    while (count2 > 1 or count2 < 0)
                    {
                        cout << endl << "Если необходимо провести поиск по 1ой подгруппе нажмите 0" << endl;
                        cout << endl << "Если необходимо провести поиск по 2ой подгруппе нажмите 1" << endl;
                        cin >> count2;
                    }
                    cout << endl << "Введите нижнюю границу интервала" << endl;
                    cin >> count1;
                    cout << endl << "Введите верхнюю границу интервала" << endl;
                    cin >> count1;
                    int count3 = 0;
                    if (count2 == 0)
                    {
                        for (int q = 0; q < count - 1; q++)
                        {
                            mass2[q].getyor(count3);
                            if (count3 > count1 and count3 < count2)
                            {
                                mass2[q].print();
                            }
                        }
                    }
                    else
                    {
                        for (int q = 0; q < ch - count - 1; q++)
                        {
                            mass3[q].getyor(count3);
                            if (count3 > count1 and count3 < count2)
                            {
                                mass3[q].print();
                            }
                        }
                    }

                }

            }
        case 3:
            bre = 1;
            break;
        default:
            cout << endl << "damn im good!!!" << endl;
            break;
        }
        if (bre == 1)
        {
            ofstream fout;
            fout.open(filename, ios::out);
            if (!fout.is_open())
            {
                cout << endl << "Ошибка открытия файла" << endl;
            }
            else
            {
                for (int k = 0; k <= j; k++)
                {
                    fin.read((char*)&mass[k], sizeof(student));
                }
            }
            cout << endl << "Спасибо за внимание , можно мне оценку повыше?";
            break;
        }
    }
}
