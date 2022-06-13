
#ifndef _AGE
#define _AGE

struct Age
{
	int _days = 0;
	int _years = 0;
	int _months = 0;

	Age() : _days{0}, _years{0}, _months{0} {};

	Age(int d, int m, int y)
	{
		_days = d;
		_years = y;
		_months = m;
	}

	void addMonth()
	{
		_months++;
		_days = 0;
		if (_months == 11) // En comptant le premier mois a _months = 0
		{
			// Si on arrive au 12e mois on augmente le nombre d'annee et on remet les mois a 0
			_months = 0;
			_years++;
		}
	}

	void addDay()
	{
		_days++;
		// si c'est impair alors c'est un mois de 31 jours et on verifie qu'on est bien au 31e jours
		if ((_months + 1) % 2 != 0 && _days == 31)
		{
			addMonth(); // On passe au mois suivant
		}
		// si c'est pair alors c'est un mois de 30 jours et on verifie qu'on est bien au 30e jours
		else if ((_months + 1) % 2 != 0 && _days == 30)
		{
			addMonth();
		}
	}
};
#endif