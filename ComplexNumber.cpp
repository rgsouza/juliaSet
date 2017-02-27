#include "ComplexNumber.h"



ComplexNumber::ComplexNumber( double a, double b ) : _r(a), _i(b)
{
}



double ComplexNumber::magnitude2()
{
	return _r * _r + _i * _i;
}



double ComplexNumber::getI()
{
	return _i;
}



double ComplexNumber::getR()
{
	return _r;
}



ComplexNumber ComplexNumber::operator *( const ComplexNumber& a )
{
	return ComplexNumber( _r * a._r - _i * a._i, _i * a._r + _r * a._i );
}



ComplexNumber ComplexNumber::operator+( const ComplexNumber& a )
{
	return ComplexNumber( _r  + a._r, _i + a._i );
}



ComplexNumber::~ComplexNumber()
{
}
