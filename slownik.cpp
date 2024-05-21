#include <random>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "slownik.h"
#include <sstream>

class Ang_Pol
{
public:
	bool operator()(const slowko &a, const slowko &b) const
	{
		return a.ang < b.ang;
	}
};

class Pol_Ang
{
public:
	bool operator()(const slowko &a, const slowko &b) const
	{
		return a.pol < b.pol;
	}
};

//------------------------------------------------------
slownik::slownik(const std::initializer_list<slowko> &init) : List{init}
{
}

//------------------------------------------------------
bool slownik::slowka_zpliku(std::string nazwa_pliku)
{
	std::ifstream file{nazwa_pliku};
	if (!file)
		return false;

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string ang, pol;

		if (iss >> ang >> pol)
			List.push_back(slowko{pol, ang});
	}

	jak_posortowany == slownik::klucz_slownika::BRAK;

	return true;
}
//------------------------------------------------------
void slownik::sortowanie()
{
	if (jak_posortowany == slownik::klucz_slownika::ANG_POL)
		List.sort(Ang_Pol());

	if (jak_posortowany == slownik::klucz_slownika::POL_ANG)
		List.sort(Pol_Ang());
}

//------------------------------------------------------
void slownik::wstaw()
{
	std::string ang, pol;
	std::cout << "Podaj slowko angielskie: \n";
	std::cin >> ang;
	std::cout << "Podaj slowko polskie\n";
	std::cin >> pol;

	slowko s{pol, ang};

	switch (jak_posortowany)
	{
	case slownik::klucz_slownika::BRAK:
		List.push_back(s);
		break;
	case slownik::klucz_slownika::ANG_POL:
	{
		Ang_Pol func{};
		std::list<slowko>::iterator it{List.begin()};
		while (func(*it, s))
		{
			it++;
		}
		List.insert(it, s);

		break;
	}
	case slownik::klucz_slownika::POL_ANG:
	{
		Pol_Ang func{};
		std::list<slowko>::iterator it{List.begin()};
		while (func(*it, s))
		{
			it++;
		}
		List.insert(it, s);

		break;
	}
	default:
		break;
	}
}
//------------------------------------------------------
bool slownik::znajdz_slowko(slowko s) const
{
	for (const slowko &word : List)
	{
		if (s == word)
		{
			return true;
		}
	}
	return false;
}
//------------------------------------------------------
void slownik::test() const
{
	int a{1};
	int b{static_cast<int>(List.size())};
	std::string s_ang;

	std::srand(std::time(nullptr));

	int random_index = a + std::rand() % (b - a + 1);

	std::list<slowko>::const_iterator it = List.begin();
	for (int index{0}; index < random_index - 1; index++)
	{
		it++;
	}

	std::cout << std::setw(4) << std::left << random_index << it->pol << std::endl;
	std::cout << "Podaj opowiedz: \n";
	std::cin >> s_ang;

	slowko s{it->pol, s_ang};

	if (znajdz_slowko(s))
	{
		std::cout << "Correct answer!\n"
				  << std::endl;
	}
	else
	{
		std::cout << "Wrong answer!\n"
				  << std::endl;
	}
}
//------------------------------------------------------
bool slownik::zapisz_slowka() const
{
	std::string path;
	std::cin >> path;

	std::ifstream f{path};
	if (f)
	{
		f.close();
		return false;
	}

	std::ofstream file{path};
	file << *this;

	return true;
}
//------------------------------------------------------
std::ostream &operator<<(std::ostream &out, const slownik &S)
{
	int index{1};
	for (const slowko &s : S.List)
	{
		if (&out == &std::cout)
			out << std::setw(8) << std::left << index;

		out << s;
		index++;
	}

	return out;
}
//------------------------------------------------------