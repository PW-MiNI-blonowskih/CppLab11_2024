#pragma once
#include <iostream>
#include <string>

class slowko
{
	std::string ang;
	std::string pol;

public:
	slowko() = default;
	slowko(std::string pol, std::string ang);

	friend bool operator==(const slowko &s1, const slowko &s2);

	friend std::ostream &operator<<(std::ostream &out, const slowko &s);
	friend std::istream &operator>>(std::istream &in, slowko &s);

	friend class slownik;
	friend class Ang_Pol; // funktor
	friend class Pol_Ang; // funktor
};
