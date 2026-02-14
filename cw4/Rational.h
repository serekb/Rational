#pragma once
#include <iostream>
using namespace std;
class Rational
{
private:
    int m_Numerat;
    int m_Denominat;
public:
    explicit Rational( int num = 0, int denom = 1 ); 
    Rational( const Rational& u );
    virtual ~Rational();

    Rational& operator = ( const Rational& u );

    int getNumerat() const;
    int getDenominat() const;
    void setNumerat( int l );
    void setDenominat( int m );
    void setRational( int num, int denom );
    void setRational( const Rational& u );

    friend const Rational operator + ( const Rational& u1, const Rational& u2 );
    friend const Rational operator - ( const Rational& u1, const Rational& u2 );
    friend const Rational operator * ( const Rational& u1, const Rational& u2 );
    friend const Rational operator / ( const Rational& u1, const Rational& u2 );

    Rational& operator += ( const Rational& u );
    Rational& operator -= ( const Rational& u );
    Rational& operator *= ( const Rational& u );
    Rational& operator /= ( const Rational& u );

    double Value() const;

    friend istream& operator >> ( istream& in, Rational& u );
    friend ostream& operator << ( ostream& out, const Rational& u );

private:
    int NWD() const;
    void shorten();
    //konstruktor 0/1
    // konstruktor kopiujacy
    //podstawienie
    //settery(skracanie ulamka jesli trzeba) // inline
    // i gettey do obu // inline
    //Setrational na podstwie licznik/minaownik lub const ulamek&  ustawia licznik manualnie i mianownik przez setter
    //funkjca prywatna skracania i NWD do skracania
    // dzialania na ulamkach (+, -, *, /) // friendy wywolujace += itd.
    //operatory =+, -=, *=, /= 
    // we x bialy znak y /wy x/y
    //cast na double Value()

};
//INLINE FUNCTIONS
inline int Rational::getNumerat() const
{
    return m_Numerat;
}
inline int Rational::getDenominat() const
{
    return m_Denominat;
}
inline void Rational::setNumerat( int l )
{
    m_Numerat = l;
}
inline void Rational::setDenominat( int m )
{
    if( m == 0 )
    {
        cerr << "ERROR determinant=0 mianownik\n";
        return;
    }
    m_Denominat = m;
    shorten();
}
inline int Rational::NWD() const
{
    int a = abs( getNumerat() );
    int b = abs( getDenominat() );
    if( a == 0 )
        return 1;
    while( a != b ) 
    {
        if( a>b )
            a = a-b;
        if( b>a )
            b = b-a;
    }
    return a;
}
inline void Rational::shorten()
{
    int x = NWD();
    m_Numerat /= x;
    m_Denominat /= x;
}
inline double Rational::Value() const
{
    return static_cast<double>(m_Numerat)/m_Denominat;
}
inline void Rational::setRational( int num, int denom )
{
    m_Numerat = num;
    setDenominat( denom );
    shorten();
}
inline void Rational::setRational( const Rational& u )
{
    setRational( u.getNumerat(), u.getDenominat() );
}

