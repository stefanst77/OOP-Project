#include "Complex.h"

Complex::Complex()
{
    re = 0.0;
    im = 0.0;
}

Complex::Complex(const Complex &z)
{
    this->re = z.re;
    this->im = z.im;
}

Complex::~Complex()
{
    re = 0.0;
    im = 0.0;
    /**
    std::cout << "Numar distrus!\n";
    //*/
}

double Complex::Get_Re()
{
    return re;
}

double Complex::Get_Im()
{
    return im;
}

void Complex::Set_Re(double x)
{
    re = x;
}

void Complex::Set_Im(double x)
{
    im = x;
}

/**
void Complex::Citire()
{
    /// Am uitat ca citesc de la numere complexe
    /// si am facut o citire pentru numere intregi.
    /// Ma durea sufletul sa o sterg.

    std::cout << "z = ";

    std::string a;
    int poz_i, i, x, y, semn, lung;
    /// citire
    getline(std::cin, a);
    lung = a.length();
    /// poz_i = 1 -> a*i + b
    /// poz_i = 2 -> a + b*i
    poz_i = 0;
    i = 0;

    /// partea reala
    semn = 1;
    ///verificam spatiile goale, semnul si daca este i
    while ('0' > a[i] || a[i] > '9')
    {
        if (a[i] == '-')
            semn = -1;
        if (a[i] == 'i')
            poz_i = 1;
        i++;
    }
    /// vedem numarul
    x = 0;
    while ('0' <= a[i] && a[i] <= '9' && i < lung)
    {
        x = x * 10 + (a[i] - '0');
        i++;
    }
    x *= semn;
    /// verificam spatiile goale si daca este i pana la semn
    while (('0' > a[i] || a[i] > '9') && a[i] != '+' && a[i] != '-')
    {
        if (a[i] == 'i')
            poz_i = 1;
        i++;
    }

    /// partea imaginara
    semn = 1;
    ///verificam spatiile goale, semnul si daca este i
    while ('0' > a[i] || a[i] > '9')
    {
        if (a[i] == '-')
            semn = -1;
        if (a[i] == 'i')
            poz_i = 2;
        i++;
    }
    /// vedem numarul
    y = 0;
    if ('0' <= a[i] && a[i] <= '9' && i < lung)
        while ('0' <= a[i] && a[i] <= '9' && i < lung)
        {
            y = y * 10 + (a[i] - '0');
            i++;
        }
    y *= semn;
    /// verificam spatiile goale si daca este i pana la capat
    while (('0' > a[i] || a[i] > '9') && a[i] != '+' && a[i] != '-')
    {
        if (a[i] == 'i')
            poz_i = 2;
        i++;
    }

    /// x - parte reala
    /// y - parte imaginara
    if (poz_i == 1)
    {
        i = x;
        x = y;
        y = i;
    }

    this->re = x;
    this->im = y;
    //Set_Re(x);
    //Set_Im(y);
}
*/

void Complex::Citire()
{
    double x;
    std::cout << "Partea reala : ";
    std::cin >> x;
    this->re = x;
    std::cout << "Partea imaginara : ";
    std::cin >> x;
    this->im = x;
}

void Complex::Afisare()
{
    double x = Get_Re();
    double y = Get_Im();
    if (x != 0)
    {
        std::cout << x;
        if (y > 0)
            std::cout << "+";
    }
    if (y != 0)
        std::cout << y << "*i";
    if (x == 0 && y == 0)
        std::cout << "0";
    std::cout << "\n";
}

Complex operator +(Complex &z1, Complex &z2)
{
    Complex z;
    z.re = z1.Get_Re() + z2.Get_Re();
    z.im = z1.Get_Im() + z2.Get_Im();
    return z;
}

Complex operator +(Complex &z1, double x)
{
    z1.re = z1.re + x;
    return z1;
}

Complex operator +(double x, Complex &z1)
{
    z1.re = z1.re + x;
    return z1;
}

Complex operator +(Complex z1)
{
    return z1;
}

Complex operator -(Complex z1, Complex z2)
{
    Complex z;
    z.re = z1.re - z2.re;
    z.im = z1.im - z2.im;
    return z;
}

Complex operator -(Complex &z1, double x)
{
    z1.re = z1.re - x;
    return z1;
}

Complex operator -(double x, Complex &z1)
{
    z1.re = z1.re - x;
    return z1;
}

Complex operator -(Complex &z1)
{
    Complex z;
    z.re = z1.re * (-1);
    z.im = z1.im * (-1);
    return z;
}

Complex operator *(Complex &z1, Complex &z2)
{
    Complex z;
    /**
    z1 = a + b*i
    z2 = c + d*i
    z = z1 * z2 = (a*c - b*d) + (a*d*i + b*c*i);
    */
    double a, b, c, d;
    a = z1.re;
    b = z1.im;
    c = z2.re;
    d = z2.im;
    z.re = (a*c - b*d);
    z.im = (a*d + b*c);
    return z;
}

Complex operator *(Complex &z1, double x)
{
    z1.re = z1.re * x;
    z1.im = z1.im * x;
    return z1;
}

Complex operator *(double x, Complex &z1)
{
    z1.re = z1.re * x;
    z1.im = z1.im * x;
    return z1;
}

Complex operator /(Complex &z1, Complex &z2)
{
    Complex z;
    double a1, a2, b1, b2, x, y, q;
    a1 = z1.re;
    b1 = z1.im;
    a2 = z2.re;
    b2 = z2.im;
    x = (a1*a2 + b1*b2);
    y = (a2*b1 - a1*b2);
    q = (a2*a2 + b2*b2);
    z.re = x / q;
    z.im = y / q;
    return z;
}

Complex operator /(Complex &z1, double x)
{
    z1.re = z1.re / x;
    z1.im = z1.im / x;
    return z1;
}

Complex operator /(double x, Complex &z1)
{
    z1.re = z1.re / x;
    z1.im = z1.im / x;
    return z1;
}

Complex& operator +=(Complex &z1, const Complex &z2)
{
    z1.re += z2.re;
    return z1;
}

Complex& operator +=(Complex &z1, double x)
{
    z1.re += x;
    return z1;
}

Complex& operator -=(Complex &z1, const Complex &z2)
{
    z1.re -= z2.re;
    return z1;
}

Complex& operator -=(Complex &z1, double x)
{
    z1.re -= x;
    return z1;
}

Complex& operator *=(Complex &z1, const Complex &z2)
{
    double a, b, c, d;
    a = z1.re;
    b = z1.im;
    c = z2.re;
    d = z2.im;
    z1.re = (a*c - b*d);
    z1.im = (a*d + b*c);
    return z1;
}

Complex& operator *=(Complex &z1, double x)
{
    z1.re *= x;
    z1.im *= x;
    return z1;
}

Complex& operator /=(Complex &z1, const Complex &z2)
{
    double a1, a2, b1, b2, x, y, q;
    a1 = z1.re;
    b1 = z1.im;
    a2 = z2.re;
    b2 = z2.im;
    x = (a1*a2 + b1*b2);
    y = (a2*b1 - a1*b2);
    q = (a2*a2 + b2*b2);
    z1.re = x / q;
    z1.im = y / q;
    return z1;
}

Complex& operator /=(Complex &z1, double x)
{
    z1.re /= x;
    z1.im /= x;
    return z1;
}

Complex& operator ^(Complex &z1, double n)
{
    double a, b, c, d, x, y;
    a = c = z1.re;
    b = d = z1.im;
    for (int i = 1; i < n; i++)
    {
        x = (a*c - b*d);
        y = (a*d + b*c);
        a = x;
        b = y;
    }
    z1.re = x;
    z1.im = y;
    return z1;
}

bool operator ==(Complex &z1, Complex &z2)
{
    return ((z1.re == z2.re) && (z1.im == z2.im));
}

bool operator ==(Complex &z1, double x)
{
    return (z1.re == x);
}

bool operator ==(double x, Complex &z1)
{
    return (z1.re == x);
}

bool operator !=(Complex &z1, Complex &z2)
{
    return ((z1.re == z2.re) && (z1.im == z2.im));
}

bool operator !=(Complex &z1, double x)
{
    return (z1.re == x);
}

bool operator !=(double x, Complex &z1)
{
    return (z1.re == x);
}

double abs(Complex &z1)
{
    return(sqrt( (z1.re * z1.re) + (z1.im * z1.im)));
}

Complex sqrt(Complex &z1)
{   /// ?????
    Complex z;
    z.re = sqrt(z1.re);
    z.im = sqrt(z1.im);
    return z;
}

