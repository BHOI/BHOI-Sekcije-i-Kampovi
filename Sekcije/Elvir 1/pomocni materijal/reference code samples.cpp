int *pok;
pok = &broj;

----------------------------------------------------------------------------------------------------------------

int broj;
int *pok1, *pok2;
pok1 = &broj; // *pok1 je sada isto što i broj
pok2 = pok1; // *pok2 je sada takoder isto što i broj
*pok1 = 8; // U promjenljivu broj se smješta 8
std::cout << *pok1 << ' ' << *pok2 << std::endl; // Ispisuje dvije osmice...
*pok1 = 5; // U promjenljivu broj se smješta 5
std::cout << *pok1 << ' ' << *pok2; // Ispisuje dvije petice...


----------------------------------------------------------------------------------------------------------------

int a(5);
Udvostruci(a);
std::cout << a;

void Udvostruci(int x) {
	x *= 2; // Ovo nece ispravno raditi...
}

----------------------------------------------------------------------------------------------------------------

int a(5);
Udvostruci(&a);
std::cout << a;


void Udvostruci(int *x) {
	*x *= 2;
}

----------------------------------------------------------------------------------------------------------------


void Razmijeni(double x, double y) {
	double pomocna(x); // Ovo takoder nece raditi!
	x = y; y = pomocna;
}

----------------------------------------------------------------------------------------------------------------

void Razmijeni(double *x, double *y) {
	double pomocna(*x);
	*x = *y; *y = pomocna;
}

Razmijeni(&a, &b);

----------------------------------------------------------------------------------------------------------------

int &b = a; // Aliasing
b = 7; // b je fakticki a...
std::cout << a; // Ispisuje 7

----------------------------------------------------------------------------------------------------------------

for(auto x : a) x *= 2;

----------------------------------------------------------------------------------------------------------------

void Problem(double &x) {
	x = 3.25;
}

int a = 2;
Problem(a);

----------------------------------------------------------------------------------------------------------------

int VeciOd(int x, int y) {
	if(x > y) return x;
	else return y;
}

int a(5), b(8);
std::cout << VeciOd(a, b);


----------------------------------------------------------------------------------------------------------------


int VeciOd(int &x, int &y) {
	if(x > y) return x;
	else return y;
}

std::cout << VeciOd(5, 7); // NEISPRAVNO: 5 i 7 nisu l-vrijednosti!

----------------------------------------------------------------------------------------------------------------


int &VeciOd(int &x, int &y) {
	if(x > y) return x;
	else return y;
}

----------------------------------------------------------------------------------------------------------------

int &q(p); // q je referenca na p
int &r(q); // r je takoder referenca na p (a ne na referencu q)

----------------------------------------------------------------------------------------------------------------

int &VeciOd(int &x, int &y) {
	if(x > y) return x;
	else return y;
}

VeciOd(a, b) = 10;
VeciOd(a, b)++;
VeciOd(a, b) += 3;
Udvostruci(VeciOd(a, b));
Razmijeni(VeciOd(a, b), c);

int &v(VeciOd(a, b));
int v1(VeciOd(a, b));

----------------------------------------------------------------------------------------------------------------


int &VeciOd(int &x, int &y) {
	if(x > y) return x;
	else return y;
}

int main()
{
	int a = 1, b = 100;
	int &v(VeciOd(a, b));
	int v1(VeciOd(a, b));

	v1++;

	cout << a << ' ' << b << endl;

	v++;

	cout << a << ' ' << b << endl;

	return 0;
}

----------------------------------------------------------------------------------------------------------------

void Funkcija(int &x, int &y) {
	x += 2; y += 5;
	std::cout << x << " " << y << std::endl;
}

int a(1);
Funkcija(a, a); // Šta ce se ispisati na ekranu???

----------------------------------------------------------------------------------------------------------------

int &VeciOd(int x, int y) {
	if(x > y) return x; // FATALNA GREŠKA: Vracamo referencu na
	else return y; // objekte koji prestaju postojati!!!
}

----------------------------------------------------------------------------------------------------------------

std::cout << VeciOd(5, 7); // NEISPRAVNO: 5 i 7 nisu l-vrijednosti!

----------------------------------------------------------------------------------------------------------------


int a(5);
const int &b(3 * a + 1); // Legalno, iako 3 * a + 1 nije l-vrijednost!
const int &c(10); // Legalno, iako 10 nije l-vrijednost!

//ovo gore je ekvivalentno sa

int a(5);
int bezimena_1(3 * a + 1), bezimena_2(10);
const int &b(bezimena_1), &c(bezimena_2);

----------------------------------------------------------------------------------------------------------------

int a(5);
const int &b(a), &c(a + 0);
a++;
std::cout << b << " " << c << std::endl; // Ispisuje 6 6 a ne 6 5!


----------------------------------------------------------------------------------------------------------------


double Kvadrat(const double &x) {
return x * x;
}

std::cout << Kvadrat(3 * a + 2);


//manje vise ekvivalentno sa

{
const double privremena_bezimena(3 * a + 2);
std::cout << Kvadrat(privremena_bezimena);
}
