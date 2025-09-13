#include <bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "x ";
        cout << endl;
    }
}

void pattern2A(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << "x ";
        cout << endl;
    }
}

void pattern2B(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << j + 1 << " ";
        cout << endl;
    }
}

void pattern2C(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << i + 1 << " ";
        cout << endl;
    }
}

void pattern2D(int n)
{
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << ++num << " ";
        cout << endl;
    }
}

void pattern2E(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << char('A' + j) << " ";
        cout << endl;
    }
}

void pattern2F(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << char('A' + i) << " ";
        cout << endl;
    }
}

void pattern2G(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
            cout << char('A' + n - 1 - j) << " ";
        cout << endl;
    }
}

void pattern2H(int n)
{
    for (int i = 0; i < n; i++)
    {
        bool bit = !(i & 1);
        for (int j = 0; j <= i; j++)
        {
            cout << bit << " ";
            bit = !bit;
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << (i + j + 1) % 2 << " ";
        cout << endl;
    }
}

void pattern3A(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
            cout << "x ";
        cout << endl;
    }
}

void pattern3B(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}

void pattern3C(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
            cout << char(j + 'A') << " ";
        cout << endl;
    }
}

void pattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int k = 0; k < n - i - 1; k++)
            cout << "_ ";

        // stars
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "x ";

        // stars
        for (int k = 0; k < n - i - 1; k++)
            cout << "_ ";
        cout << endl;
    }
}

void pattern5(int n)
{
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int k = 0; k < i; k++)
            cout << "_ ";

        // stars
        for (int j = 0; j < 2 * (n - i) - 1; j++)
            cout << "x ";

        // spaces
        for (int k = 0; k < i; k++)
            cout << "_ ";
        cout << endl;
    }
}

void pattern6(int n)
{
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int k = 0; k < n - i - 1; k++)
            cout << "_ ";

        // stars
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "x ";

        // stars
        for (int k = 0; k < n - i - 1; k++)
            cout << "_ ";
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int k = 0; k < i; k++)
            cout << "_ ";

        // stars
        for (int j = 0; j < 2 * (n - i) - 1; j++)
            cout << "x ";

        // spaces
        for (int k = 0; k < i; k++)
            cout << "_ ";
        cout << endl;
    }
}

void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << "x ";
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
            cout << "x ";
        cout << endl;
    }
}

void pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << j + 1 << " ";

        int spaces = 2 * (n - i - 1);
        for (int k = 0; k < spaces; k++)
            cout << "_ ";

        for (int j = i + 1; j > 0; j--)
            cout << j << " ";
        cout << endl;
    }
}

void pattern9(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n - i - 1; k++)
            cout << "_ ";

        for (int j = 0; j < i; j++)
            cout << char('A' + j) << " ";
        for (int j = i; j >= 0; j--)
            cout << char('A' + j) << " ";
        cout << endl;
    }
}

void pattern10(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
            cout << "x ";

        int spaces = 2 * (n - i - 1);
        for (int k = 0; k < spaces; k++)
            cout << "_ ";

        for (int j = i; j >= 0; j--)
            cout << "x ";
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
            cout << "x ";

        int spaces = 2 * (n - i - 1);
        for (int k = 0; k < spaces; k++)
            cout << "_ ";

        for (int j = i; j >= 0; j--)
            cout << "x ";
        cout << endl;
    }
}

void pattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
            cout << "x ";

        int spaces = 2 * (n - i - 1);
        for (int k = 0; k < spaces; k++)
            cout << "_ ";

        for (int j = i; j >= 0; j--)
            cout << "x ";
        cout << endl;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
            cout << "x ";

        int spaces = 2 * (n - i - 1);
        for (int k = 0; k < spaces; k++)
            cout << "_ ";

        for (int j = i; j >= 0; j--)
            cout << "x ";
        cout << endl;
    }
}

void pattern12(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                cout << "x ";
            else
                cout << "_ ";
        cout << endl;
    }
}

int main()
{
    pattern1(5);

    cout << "\n";
    pattern2A(5);

    cout << "\n";
    pattern2B(5);

    cout << "\n";
    pattern2C(5);

    cout << "\n";
    pattern2D(5);

    cout << "\n";
    pattern2E(5);

    cout << "\n";
    pattern2F(5);

    cout << "\n";
    pattern2G(5);

    cout << "\n";
    pattern2H(5);

    cout << "\n";
    pattern3A(5);

    cout << "\n";
    pattern3B(5);

    cout << "\n";
    pattern3C(5);

    cout << "\n";
    pattern4(5);

    cout << "\n";
    pattern5(5);

    cout << "\n";
    pattern6(5);

    cout << "\n";
    pattern7(5);

    cout << "\n";
    pattern8(5);

    cout << "\n";
    pattern9(5);

    cout << "\n";
    pattern10(5);

    cout << "\n";
    pattern11(5);

    cout << "\n";
    pattern12(5);

    return 0;
}