#include "Rational.h"
Rational::Rational( int num, int denom )
{
    setRational( num,denom );
}
Rational::Rational( const Rational& u )
{
    *this = u;
}
Rational& Rational::operator = ( const Rational& u )
{
    setNumerat( u.getNumerat() );
    setDenominat( u.getDenominat() );
    shorten();
    return *this;
}
Rational::~Rational()
{

}

const Rational operator + ( const Rational& u1, const Rational& u2 )
{
    Rational res( u1 );
    return res+=u2;
}
const Rational operator - ( const Rational& u1, const Rational& u2 )
{ 
    Rational res( u1 );
    return res-=u2;
}

const Rational operator * ( const Rational& u1, const Rational& u2 )
{
    Rational res( u1 );
    return res*=u2;
}
const Rational operator / ( const Rational& u1, const Rational& u2 )
{
    Rational res( u1 );
    return res/=u2;
}

Rational& Rational::operator += ( const Rational& u )
{
    int denom = m_Denominat* u.getDenominat();
    int numer = getNumerat()*u.getDenominat() + u.getNumerat() * getDenominat();
    Rational res = Rational( numer,denom );
    *this = res;
    shorten();
    return *this;
}
Rational& Rational::operator -= ( const Rational& u )
{
    int denom = m_Denominat * u.getDenominat();
    int numer = m_Numerat * u.getDenominat();
    numer -= u.getNumerat() * getDenominat();
    Rational res = Rational(numer, denom);
    res.shorten();
    *this = res;
    return *this;
}
Rational& Rational::operator *= ( const Rational& u )
{
    m_Numerat *= u.getNumerat();
    m_Denominat *= u.getDenominat();
    shorten();
    return *this;
}
Rational& Rational::operator /= ( const Rational& u )
{
    if(u.getNumerat() == 0)
    {
        cerr << "ERROR dzielenie przez zero\n";
        return *this;//blad
    }
    m_Numerat *= u.getDenominat();
    m_Denominat *= u.getNumerat();
    shorten();
    return *this;
}

istream& operator >> ( istream& in, Rational& u )
{
    int temp;
    in >> temp; u.setNumerat( temp );
    in >> temp; u.setDenominat( temp );
    return in;
}
ostream& operator << ( ostream& out, const Rational& v )
{
    out << v.getNumerat() << '/' << v.getDenominat() << endl;
    return out;
}
