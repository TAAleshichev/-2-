#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Setinterface {
public: 
	virtual void additems(int s)=0;
	virtual void definesepsale(bool k) = 0;
};

template <class T>

class Offurniture {
private:
	T ID;
protected:
	char *name;
	char *country;
	T cost;
public:
	Offurniture();
	Offurniture(char *n);
	Offurniture(char *n, T a, char *co, T c);
	Offurniture(char *n, char *co, T c);
	void print()const;
	Offurniture(const Offurniture &m);
	void input(char *n, T a, char *co, T c);
	Offurniture &copy(const Offurniture &m);
	Offurniture sum(Offurniture b);
	bool comp(Offurniture b);
	~Offurniture();
	Offurniture operator +(const Offurniture m);
	Offurniture operator +(T m);
	Offurniture operator -(const Offurniture m);
	Offurniture operator -(T m);
	Offurniture operator =(const Offurniture m);
	Offurniture operator =(T m);
	bool operator <(Offurniture m);
	bool operator <(T m);
	bool operator >(Offurniture m);
	bool operator >(T m);
	bool operator ==(Offurniture m);
	bool operator ==(T m);
};

class Setofitems : public Offurniture<double>, virtual public Setinterface {
private:
	Offurniture::name;
	Offurniture::country;
	Offurniture::cost;
	int amountofitems = 0;
	bool partsale = 0;
public:
	void print();
	Setofitems(char* n, char* co, double c, int aoi, bool ps);
	Setofitems();
	Setofitems(const Setofitems& m);
	Setofitems &copy(Setofitems &m);
	void additems(int s) {
		amountofitems += s;
	};
	void definesepsale(bool k) {
		partsale = k;
	};
	Setofitems summary(Setofitems b);
	void input(char* n, char* co, double c, int aoi, bool ps);
	
};

Setofitems Setofitems::summary(const Setofitems b) {
	Setofitems h;
	h.cost = cost + b.cost;
	strcpy(h.name, "-");
	strcpy(h.country, "-");
	h.amountofitems = amountofitems + b.amountofitems;
	h.partsale = partsale + b.partsale;
	return h;
}


template <class T>
bool Offurniture<T>::comp(Offurniture<T> b) {
	return (cost > b.cost);
}

template <class T>
Offurniture<T> &Offurniture<T>::copy(const Offurniture<T> &m) {
	if (&m != this) {
		delete[]name;
		delete[]country;
		name = new char[strlen(m.name) + 1];
		strcpy(name, m.name);
		ID = m.ID;
		country = new char[strlen(m.country) + 1];
		strcpy(country, m.country);
		cost = m.cost;
	}
	return(*this);
}

template <class T>
void Offurniture<T>::input(char *n, T a, char *co, T c) {
	strcpy(name, n);
	ID = a;
	strcpy(country, co);
	cost = c;
}

template <class T>
Offurniture<T>::Offurniture<T>() {
	name = new char[3];
	strcpy(name, "-");
	ID = 0;
	country = new char[3];
	strcpy(country, "-");
	cost = 0;
}

template <class T>
Offurniture<T>::Offurniture<T>(char* n) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	ID = 0;
	country = new char[2];
	strcpy(country, "-");
	cost = 0;
}

template <class T>
Offurniture<T>::~Offurniture<T>() {
	delete[]name;
	delete[]country;
}

template <class T>
Offurniture<T> Offurniture<T>::sum(const Offurniture<T> b) {
	Offurniture h;
	h.cost = cost + b.cost;
	strcpy(h.name, "-");
	strcpy(h.country, "-");
	return h;
}



// Ïåðåãðóçêà îïåðàòîðîâ

template <class T>
Offurniture<T> Offurniture<T>::operator +(const Offurniture<T> m) {
	Offurniture h;
	h.cost = cost + m.cost;
	strcpy(h.name, "-");
	strcpy(h.country, "-");
	return h;
}

template <class T>
Offurniture<T> Offurniture<T>::operator +(T m) {
	cost = cost + m;
	return(*this);
}

template <class T>
Offurniture<T> Offurniture<T>::operator -(const Offurniture<T> m) {
	Offurniture h;
	h.cost = cost - m.cost;
	strcpy(h.name, "-");
	strcpy(h.country, "-");
	return h;
}

template <class T>
Offurniture<T> Offurniture<T>::operator -(T m) {
	cost = cost - m;
	return(*this);
}

template <class T>
Offurniture<T> Offurniture<T>::operator =(const Offurniture<T> m) {
	strcpy(name, m.name);
	ID = m.ID;
	strcpy(country, m.country);
	cost = m.cost;
	return(*this);
}


template <class T>
Offurniture<T> Offurniture<T>::operator =(T m) {
	cost =  m;
	return(*this);
}

template <class T>
bool Offurniture<T>::operator <(const Offurniture<T> m) {
	return(cost<m.cost);
}

template <class T>
bool Offurniture<T>::operator <(T m) {
	return(cost<m);
}

template <class T>
bool Offurniture<T>::operator >(const Offurniture<T> m) {
	return(cost>m.cost);
}

template <class T>
bool Offurniture<T>::operator >(T m) {
	return(cost>m);
}

template <class T>
bool Offurniture<T>::operator ==(const Offurniture<T> m) {
	return(cost == m.cost);
}

template <class T>
bool Offurniture<T>::operator ==(T m) {
	return(cost == m);
}

template <class T>
Offurniture<T>::Offurniture<T>(const Offurniture<T> &m) {
	name = new char[strlen(m.name) + 1];
	strcpy(name, m.name);
	ID = m.ID;
	country = new char[strlen(m.country) + 1];
	strcpy(country, m.country);
	cost = m.cost;
}

template <class T>
Offurniture<T>::Offurniture<T>(char *n, T a, char *co, T c) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	ID = a;
	country = new char[strlen(co) + 1];
	strcpy(country, co);
	cost = c;
}

template <class T>
Offurniture<T>::Offurniture<T>(char *n, char *co, T c) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	country = new char[strlen(co) + 1];
	strcpy(country, co);
	cost = c;
}

template <class T>
void Offurniture<T>::print()const {
	if (name!="") cout << "Íàçâàíèå ïðåäìåòà ìåáåëè: " << name << endl;
	if (ID >= 0) cout << "ID ïðåäìåòà ìåáåëè:" << ID << endl;
	if (country != "") cout << "Ñòðàíà-ïðîèçâîäèòåëü: " << country << endl;
	if (cost >= 0) cout << "Ñòîèìîñòü ïðåäìåòà ìåáåëè(â ðóáëÿõ) :" << cost << endl;
}

void Setofitems::print() {
	Offurniture<double>::print();
	cout << "×èñëî ïðåäìåòîâ ìåáåëè â íàáîðå: " << amountofitems << endl;
	if (partsale) cout << "Ïîêóïêà îòäåëüíûõ ýëåìåíòîâ íàáîðà âîçìîæíà" << endl;
	else cout << "Ïîêóïêà îòäåëüíûõ ýëåìåíòîâ íàáîðà íåâîçìîæíà" << endl;
}

Setofitems::Setofitems(char *n, char *co, double c, int aoi, bool ps):Offurniture<double>(n, co, c){
	amountofitems = aoi;
	partsale = ps;
}

Setofitems::Setofitems() : Offurniture<double>(){
	amountofitems = 0;
	partsale = 0;
}

Setofitems::Setofitems(const Setofitems& m) {
	name = new char[strlen(m.name) + 1];
	strcpy(name, m.name);
	amountofitems = m.amountofitems;
	partsale = m.partsale;
	country = new char[strlen(m.country) + 1];
	strcpy(country, m.country);
	cost = m.cost;
}


Setofitems& Setofitems::copy(Setofitems& m) {
	if (&m != this) {
		delete[]name;
		delete[]country;
		name = new char[strlen(m.name) + 1];
		strcpy(name, m.name);
		country = new char[strlen(m.country) + 1];
		strcpy(country, m.country);
		cost = m.cost;
		amountofitems = m.amountofitems;
		partsale = m.partsale;
	}
	return(*this);
}



void Setofitems::input(char* n, char* co, double c, int aoi, bool ps) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	amountofitems = aoi;
	partsale = ps;
	country = new char[strlen(co) + 1];
	strcpy(country, co);
	cost = c;
}





int main()
{
	setlocale(LC_ALL, "russian");
	Setofitems set1("Êîìïëåêò ìåáåëè NOVA S", "Ðîññèÿ", 100000, 7, 1);
	cout << "Îáúåêò set1 Ïðîèçâîäíîãî êëàññà Setofitems" << endl;
	set1.print();
	cout << endl;
	Setofitems set2("Êîìïëåêò ìåáåëè Ñóïåðýêîíîì", "Ðîññèÿ", 100, 150, 0);
	cout << "Îáúåêò set2 Ïðîèçâîäíîãî êëàññà Setofitems" << endl;
	set2.print();
	cout << endl;
	cout << "Èñïîëüçîâàíèå ôóíêöèè îïðåäåëåíèÿ âîçìîæíîñòè ðàçäåëüíîé ïðîäàæè ïðåäìåòîâ definesepsale íà îáúåêòå set1 (ìåíÿåì çíà÷åíèå íà 0):" << endl;
	set1.definesepsale(0);
	set1.print();
	cout << endl;
	cout << "Îáúåêò set5 ñ ïàðàìåòðàìè ïî óìîë÷àíèþ, íà êîòîðîì áûëà èñïîëüçîâàíà ôóíêöèÿ äîáàâëåíèÿ ïðåäìåòîâ additems (äîáàâëåíî 15 ïðåäìåòîâ):" << endl;
	Setofitems set5;
	set5.additems(15);
	set5.print();
	cout << endl;
	if (set1 > 100) cout << "set1 áîëüøå 100 ïî ñòîèìîñòè ñîãëàñíî îïåðàòîðó ñðàâíåíèÿ áàçîâîãî êëàññà" << endl;
	else cout << "set1 ìåíüøå 100 ïî ñòîèìîñòè ñîãëàñíî îïåðàòîðó ñðàâíåíèÿ áàçîâîãî êëàññà" << endl;
	cout << endl;
	cout << "Îáúåêò set4, ÿâëÿþùèéñÿ ñóììîé îáúåêòîâ set2 è set5, íî ñ òðåìÿ äîïîëíèòåëüíûìè ïðåäìåòàìè è îïöèåé ïîêóïêè îòäåëüíûõ ïðåäìåòîâ:" << endl;
	Setofitems set4;
	set4.copy(set2.summary(set5));
	set4.additems(3);
	set4.definesepsale(1);
	set4.print();
	system("pause");
	return 0;
}
