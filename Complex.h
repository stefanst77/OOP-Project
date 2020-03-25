#ifndef COMPLEX_H
#define COMPLEX_H
#include <bits/stdc++.h>

class Complex
{
    private:
        double re;
        double im;

    public:
        Complex();
        Complex(const Complex &z);

        virtual ~Complex();

        double Get_Re();
        double Get_Im();

        void Set_Re(double x);
        void Set_Im(double x);

        void Citire();
        void Afisare();

        friend Complex operator +(Complex &, Complex &);
        friend Complex operator +(Complex &, double x);
        friend Complex operator +(double x, Complex &);

        friend Complex operator +(Complex z1);

        friend Complex operator -(Complex z1, Complex z2);
        friend Complex operator -(Complex &, double x);
        friend Complex operator -(double x, Complex &);

        friend Complex operator -(Complex &);
        /// opus (ex: z = a+b*i, -z = (-1)*a + (-1)*b*i)

        friend Complex operator *(Complex &, Complex &);
        friend Complex operator *(Complex &, double x);
        friend Complex operator *(double x, Complex &);

        friend Complex operator /(Complex &, Complex &);
        friend Complex operator /(Complex &, double x);
        friend Complex operator /(double x, Complex &);

        friend Complex& operator +=(Complex &z1, const Complex &z2);
        friend Complex& operator +=(Complex &z1, double x);

        friend Complex& operator -=(Complex &z1, const Complex &z2);
        friend Complex& operator -=(Complex &z1, double x);

        friend Complex& operator *=(Complex &z1, const Complex &z2);
        friend Complex& operator *=(Complex &z1, double x);

        friend Complex& operator /=(Complex &z1, const Complex &z2);
        friend Complex& operator /=(Complex &z1, double x);

        friend Complex& operator ^(Complex &z1, double n);

        friend bool operator ==(Complex &, Complex &);
        friend bool operator ==(Complex &, double x);
        friend bool operator ==(double x, Complex &);

        friend bool operator !=(Complex &, Complex &);
        friend bool operator !=(Complex &, double x);
        friend bool operator !=(double x, Complex &);

        friend double abs(Complex &);

        friend Complex sqrt(Complex &);
        /// ?????

    protected:
};

#endif // COMPLEX_H
