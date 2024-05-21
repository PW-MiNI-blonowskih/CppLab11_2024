#pragma once

#include <list>
#include "slowko.h"

class slownik
{
	std::list<slowko> List;

public:
	enum class klucz_slownika
	{
		BRAK,
		POL_ANG,
		ANG_POL
	} jak_posortowany = klucz_slownika::BRAK;

public:
	slownik() = default;
	slownik(const std::initializer_list<slowko> &init);

	bool slowka_zpliku(std::string nazwa_pliku);

	void sortowanie();

	void wstaw();

	bool znajdz_slowko(slowko s) const;
	void test() const;

	bool zapisz_slowka() const;

	friend std::ostream &operator<<(std::ostream &out, const slownik &S);
};
