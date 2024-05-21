
#include <iomanip>
#include "slowko.h"

//----------------------------------------------------
slowko::slowko(std::string pol, std::string ang) : pol(pol), ang(ang) {}

//---------------------------------------------------
bool operator==(const slowko &s1, const slowko &s2)
{
	return (s1.pol == s2.pol && s1.ang == s2.ang);
}
//---------------------------------------------------
std::ostream &operator<<(std::ostream &out, const slowko &s)
{
	out << std::setw(30) << std::left << s.ang;
	out << std::setw(30) << std::left << s.pol;
	return out << std::endl;
}
//---------------------------------------------------
std::istream &operator>>(std::istream &in, slowko &s)
{
	// wypisz prompt tylko gdy czytamy z klawiatury
	if (&in == &std::cin)
		std::cout << "Podaj slowo ANGIELSKIE : ";

	in >> s.ang;

	// wypisz prompt tylko gdy czytamy z klawiatury
	if (&in == &std::cin)
		std::cout << "Podaj slowo POLSKIE : ";

	in >> s.pol;

	return in;
}
//---------------------------------------------------
