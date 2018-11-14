//#pragma once
//#include <iostream>
//
//
//using namespace std;
//
//
//class Karta {
//public:
//	enum Znak { PIK, TREF, KARO, HERC };
//	enum Broj {
//		K1 =
//		1, K2, K3, K4, K5, K6, K7, K8,
//		K9, K10, ZANDAR = 12, DAMA, KRALJ
//	};
//	Karta(Znak zz, Broj bb) :z(zz), b(bb) {}
//	int vrednost()const {
//		return b == K2 && z == TREF ? 1 :
//			b == K10
//			&& z == KARO ? 2 : b >= 10 ? 1 : 0;
//	}
//	friend bool operator>(const Karta &k1, const
//			Karta &k2) {
//		return k1.b > k2.b;
//	}
//	friend bool operator >>
//		(const Karta &k1, const
//			Karta &k2)
//	{
//		return k1.vrednost() > k2.vrednost();
//	}
//	friend ostream& operator<<(ostream &ot, const Karta &k) {
//		string znakovi[] = { "pik","tref","karo","herc"
//		};
//		string brojevi[] = { "zandar", "dama","kralj"
//		};
//		ot <<
//			"karta(";  if (k.b < 12) ot << k.b;
//			else ot << brojevi[k.b
//				-
//			12];
//			return ot <<
//				", " << znakovi[k.z] << ")";
//	}
//private: Znak z; Broj b;
//};
//
//class Spil {
//	struct Node {
//		Karta k;
//		Node* sled;
//		Node(const Karta &kk) :k(kk), sled(nullptr) {}
//	};
//
//	Node* glava;
//	Node* rep;
//	void premesti(Spil&s) {
//		glava = s.glava; rep = s.rep;
//		s.glava = s.rep = nullptr;
//	};
//	void kopiraj(const Spil& s) {
//		Node* tek = s.glava;
//		while (tek) {
//			*this += tek->k;
//			tek->sled;
//		}
//	
//	
//	};
//	void brisi() {
//		Node* old;
//		while (glava) {
//			old = glava;
//			glava = glava->sled;
//			delete old;
//		}
//	};
//
//
//public:
//	Spil() { glava = rep = nullptr; };
//	Spil(const Spil& s) { kopiraj(s); };
//	Spil(Spil&&s) { premesti(s); };
//	Spil& operator=(const Spil& s) {
//		if (this != &s) { brisi(); kopiraj(s); }
//		return *this;
//	};
//	Spil& operator=(Spil&& s) {
//		if (this != &s) { brisi(); premesti(s); }
//		return *this;
//	};
//	Spil& operator+=(const Karta& k) {
//		Node* novi = new Node(k);
//		if (!glava) glava = rep = novi;
//		else {
//			rep->sled = novi;
//			rep = novi;
//		}
//
//	}
//	Karta operator--() {
//		if (!glava) exit(1);
//		Node* tek = glava;
//		while (glava->sled != rep) tek = tek->sled;
//		Karta k = rep->k;
//		delete rep;
//		rep = tek;
//		return k;
//		
//	};
//	int operator()() const  {
//		int vr = 0;
//		for (Node* tek = glava; tek; tek->sled) vr+=tek->k.vrednost();
//		return vr;
//	}
//	int brojKarata() const  {
//		int broj = 0;
//		for (Node* tek = glava; tek; tek->sled) broj++;
//		return broj;
//	}
//	Karta najveca() const  {
//		if (!glava) exit(3);
//		int vr = 0;
//		Karta ka=glava->k;
//		for (Node* tek = glava; tek; tek->sled) 
//			if (tek->k.vrednost() > vr){
//				vr = tek->k.vrednost;
//				ka = tek->k;
//			}
//		return ka;
//
//
//	}
//	friend bool operator>(const Spil& s1, const Spil& s2) {
//		if (s1() > s2()) return true;
//		return false;
//	}
//	friend bool operator>>(const Spil& s1, const Spil& s2) {
//		if (s1.najveca().vrednost() > s2.najveca().vrednost()) return true;
//		return false;
//	}
//	friend ostream& operator << (ostream &it, const  Spil & s) {
//		it << "spil (" << s.brojKarata() << ')' << endl;
//		for (Spil::Node* tek; tek;tek->sled)
//			it << tek->k << endl;
//		return it;
//	}
//	~Spil() { brisi(); };
//
//};