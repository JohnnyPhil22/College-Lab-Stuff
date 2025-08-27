#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool isEvenIfElse(int n)
{
    if (n % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEvenTern(int n)
{
    return (n % 2 == 0) ? true : false;
}

string monthFromNumberIfElse(int n)
{
    if (n == 1)
    {
        return "January";
    }
    else if (n == 2)
    {
        return "February";
    }
    else if (n == 3)
    {
        return "March";
    }
    else if (n == 4)
    {
        return "April";
    }
    else if (n == 5)
    {
        return "May";
    }
    else if (n == 6)
    {
        return "June";
    }
    else if (n == 7)
    {
        return "July";
    }
    else if (n == 8)
    {
        return "August";
    }
    else if (n == 9)
    {
        return "September";
    }
    else if (n == 10)
    {
        return "October";
    }
    else if (n == 11)
    {
        return "November";
    }
    else if (n == 12)
    {
        return "December";
    }
    else
    {
        return "Invalid month number";
    }
}

string monthFromNumberSwitchCase(int n)
{
    switch (n)
    {
    case 1:
        return "January";

    case 2:
        return "February";

    case 3:
        return "March";

    case 4:
        return "April";

    case 5:
        return "May";

    case 6:
        return "June";

    case 7:
        return "July";

    case 8:
        return "August";

    case 9:
        return "September";

    case 10:
        return "October";

    case 11:
        return "November";

    case 12:
        return "December";

    default:
        return "Invalid month number";
    }
}

void x1(int n)
{
    float x1ForLoop = 0, x1WhileLoop = 0;
    for (int i = 1; i <= n; i++)
    {
        x1ForLoop += i / (i + 1);
    }
    int i = 1;
    while (i <= n)
    {
        x1WhileLoop += i / (i + 1);
        i++;
    }

    cout << fixed << setprecision(2) << "\tx1 For Loop: " << x1ForLoop << endl
         << fixed << setprecision(2) << "\tx1 While Loop: " << x1WhileLoop << endl;
}

void x2(int n)
{
    float x2ForLoop = 0, x2WhileLoop = 0;
    for (int i = 1, j = 1; i <= n && j <= n; i++, j++)
    {
        x2ForLoop += i * j;
    }
    int i = 1, j = 1;
    while (i <= n && j <= n)
    {
        x2WhileLoop += i * j;
        i++;
        j++;
    }

    cout << fixed << setprecision(2) << "\tx2 For Loop: " << x2ForLoop << endl
         << fixed << setprecision(2) << "\tx2 While Loop: " << x2WhileLoop << endl;
}

void x3(int n)
{
    float x3ForLoop = 0, x3WhileLoop = 0;
    for (int i = 1, j = 1, k = 1; i <= n && j <= n && k <= n; i++, j++, k++)
    {
        x3ForLoop += 1 / sqrt(i + j + k);
    }
    int i = 1, j = 1, k = 1;
    while (i <= n && j <= n && k <= n)
    {
        x3WhileLoop += 1 / sqrt(i + j + k);
        i++;
        j++;
        k++;
    }

    cout << fixed << setprecision(2) << "\tx3 For Loop: " << x3ForLoop << endl
         << fixed << setprecision(2) << "\tx3 While Loop: " << x3WhileLoop << endl;
}

void x4(int n)
{
    float x4ForLoop = 0, x4WhileLoop = 0;
    for (int i = 1; i <= n; i++)
    {
        int jSum = 0;
        for (int j = 1; j <= n; j++)
        {
            jSum += j;
        }
        x4ForLoop += i * jSum;
    }
    int i = 1, j = 1;
    while (i <= n && j <= n)
    {
        int jSum = 0;
        for (int j = 1; j <= n; j++)
        {
            jSum += j;
        }
        x4WhileLoop += i * jSum;
        i++;
        j++;
    }

    cout << fixed << setprecision(2) << "\tx4 For Loop: " << x4ForLoop << endl
         << fixed << setprecision(2) << "\tx4 While Loop: " << x4WhileLoop << endl;
}

void x5(int n)
{
    float x5ForLoop = 0, x5WhileLoop = 0;

    cout << "\tx5 For Loop: ";
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            cout << 4;
        }
        else
        {
            cout << 9;
        }
    }

    cout << endl
         << "\tx5 While Loop: ";
    int i = 1;
    while (i <= n)
    {
        if (i % 2 == 0)
        {
            cout << 4;
        }
        else
        {
            cout << 9;
        }
        i++;
    }
    cout << endl;
}

void f1(int n)
{
    long long f1ForLoop = 0, f1WhileLoop = 0;
    for (int i = 1; i <= n; i++)
    {
        f1ForLoop += pow(i, 2);
    }
    int i = 1;
    while (i <= n)
    {
        f1WhileLoop += pow(i, 2);
        i++;
    }

    cout << "\tf1 For Loop: " << f1ForLoop << endl
         << "\tf1 While Loop: " << f1WhileLoop << endl;
}

void f2(int n)
{
    long long f2ForLoop = 1, f2WhileLoop = 1;
    for (int i = 1; i <= n; i++)
    {
        f2ForLoop *= (i - 1);
    }
    int i = 1;
    while (i <= n)
    {
        f2WhileLoop *= (i - 1);
        i++;
    }

    cout << "\tf2 For Loop: " << f2ForLoop << endl
         << "\tf2 While Loop: " << f2WhileLoop << endl;
}

void f3(int n, int m)
{
    long long f3ForLoop = 1, f3WhileLoop = 1;
    for (int i = 1; i <= n; i++)
    {
        double prod = 1.0;
        for (int j = 1; j <= m; j++)
        {
            prod *= sqrt(i) * pow(j, 2);
        }
        f3ForLoop += prod;
    }
    int i = 1;
    while (i <= n)
    {
        double prod = 1.0;
        for (int j = 1; j <= m; j++)
        {
            prod *= sqrt(i) * pow(j, 2);
        }
        f3WhileLoop += prod;
        i++;
    }

    cout << "\tf3 For Loop: " << f3ForLoop << endl
         << "\tf3 While Loop: " << f3WhileLoop << endl;
}

void f4(int n, int a)
{
    long long f4ForLoop = 0, f4WhileLoop = 0, res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += a * pow(i, 2);
    }
    f4ForLoop = sqrt(res);

    int i = 1;
    while (i <= n)
    {
        res += a * pow(i, 2);
        i++;
    }
    f4WhileLoop = sqrt(res);
    cout << "\tf4 For Loop: " << f4ForLoop << endl
         << "\tf4 While Loop: " << f4WhileLoop << endl;
}

int main()
{
    while (true)
    {
        int choice;
        cout << "Choose question (1: Is Number Even?, 2: Month from number, 3: Compute expressions, 4: Exit): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int num;
            cout << "Enter integer: ";
            cin >> num;

            cout << "If Statement Function: " << (isEvenIfElse(num) ? "True" : "False") << endl
                 << "Ternary Function: " << (isEvenTern(num) ? "True" : "False") << endl;
            break;

        case 2:
            int month;
            cout << "Enter month number: ";
            cin >> month;

            cout << "If Statement Function: " << monthFromNumberIfElse(month) << endl
                 << "Switch Case Function: " << monthFromNumberSwitchCase(month) << endl;
            break;

        case 3:
            cout << "Expressions with n = 10:" << endl;
            x1(10);
            x2(10);
            x3(10);
            x4(10);
            x5(10);
            f1(10);
            f2(10);
            f3(10, 5);
            f4(10, 2);

            cout << "Expressions with n = 100:" << endl;
            x1(100);
            x2(100);
            x3(100);
            x4(100);
            x5(100);
            f1(100);
            f2(100);
            f3(100, 5);
            f4(100, 2);

            cout << "Expressions with n = 1000:" << endl;
            x1(1000);
            x2(1000);
            x3(1000);
            x4(1000);
            x5(1000);
            f1(1000);
            f2(1000);
            f3(1000, 5);
            f4(1000, 2);
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}