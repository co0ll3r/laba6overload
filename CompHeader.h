#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <set>
#include <algorithm>
#pragma once

class Perechen;
class workComputers;
class aggregate;

struct COMP{
	std::string ProcName; // Brand name
	std::string ProcType; // Specification
	std::string Graphics; // Graphic Card
	double GraphicVolume;
	double ClockSpeed;
	double RAM;
	double Storage;
	
	/* overloads*/
	friend std::istream& operator>>(std::istream&, COMP&);
	friend std::ostream& operator<<(std::ostream&, COMP);
	friend std::ifstream& operator>>(std::ifstream&, COMP&);
	friend std::ofstream& operator<<(std::ofstream&, COMP);
};

struct RECORD{
	COMP CompInfo;
	double CompCost;
	int CompInStock;
	
	/* overloads*/
	friend std::istream& operator>>(std::istream&, RECORD&);
	friend std::ostream& operator<<(std::ostream&, RECORD);
	friend std::ifstream& operator>>(std::ifstream&, RECORD&);
	friend std::ofstream& operator<<(std::ofstream&, RECORD);
};

struct BrandPerech{
	std::string ProcName;
	int Count;
};

struct TypeProcPerech{
	std::string ProcType;
	int Count;
};

struct VideocardsPerech{
 	double GraphicVolume;
	int Count;
}; 

class workComputers {
	public:
		/*Constructors*/
		workComputers(int size = 0) : size(size), CapabilitiesComp(size ? new RECORD[size] : nullptr) {}
		~workComputers() { delete [] CapabilitiesComp; }
		workComputers(const workComputers&);

		/* overloads*/
		workComputers& operator=(workComputers);
//		friend std::istream& operator>>(std::istream&, workComputers);
//		friend std::ostream& operator<<(std::ostream&, workComputers);
		
		/* METHODS*/
		friend void swap(workComputers&, workComputers&);
		virtual void testCopyOperator();
		virtual void testCopyConstructor();

		void InputFromFile();
		virtual void OutputInFile();
		void Add_comp();
		void Delete_comp();
 		virtual	void showInfo();
		void swapElementsInMassive(unsigned);
		virtual	void SortProcTypeAndClock();
		void SortProcName();
		void SortPrice();

		friend void makePerechen1(workComputers, Perechen&);
		friend void makePerechen2(workComputers,Perechen&);
		friend void makePerechen3(workComputers, Perechen&);
	protected:
		int size;
		RECORD* CapabilitiesComp;
};

class SearchComp : public workComputers{
	public:
		// constructors
		SearchComp(int size = 0) : size(size), SearchResult(size ? new RECORD[size] : nullptr) {}
		~SearchComp(){ delete [] SearchResult; }
		SearchComp(const SearchComp&);
		SearchComp& operator=(SearchComp);
		friend void swap(SearchComp&, SearchComp&);

		/* METHODS */
		virtual void testCopyConstructor();
		virtual void testCopyOperator();

		void SearchPrice();
		void SearchHddVolume();
		void SearchBrandTypeRamETC();
		void SortRAM();
		virtual void OutputInFile();
		virtual void SortProcTypeAndClock();
		virtual void showInfo();
		void swapElementsInSearch(unsigned);
	private:
		int size;
		RECORD* SearchResult;
};

class Perechen : public SearchComp{
	public:
		/* Constructors */
		Perechen(int sB = 0, int sP = 0, int sV = 0) : pBrandlen(sB), pProclen(sP), pVideolen(sV), perechenBrands(pBrandlen ? new BrandPerech[pBrandlen] : nullptr), perechenProcTypes(pProclen? new TypeProcPerech[pProclen] : nullptr), perechenVideocardVolume(pVideolen ? new VideocardsPerech[pVideolen] : nullptr) {}
		~Perechen() { delete [] perechenBrands; delete [] perechenProcTypes; delete [] perechenVideocardVolume;}
		Perechen(const Perechen&); 
		Perechen& operator=(Perechen); 
		friend void swap(Perechen&, Perechen&);
		
		/* Methods */
		virtual void testCopyConstructor();
		virtual void testCopyOperator();

		void showFirstPerech();
		void showSecondPerech();
		void showThirdPerech();
		void sortProcTypeFirstPerech();
		void sortCountSecondPerech();
		void sortVideoVolumeThirdPerech();
		void saveFirstPerech();
		void saveSecondPerech(); 
		void saveThirdPerech();

		friend void makePerechen1(workComputers, Perechen&);
		friend void makePerechen2(workComputers, Perechen&);
		friend void makePerechen3(workComputers, Perechen&);
	private:
		int pBrandlen, pProclen, pVideolen;
		BrandPerech* perechenBrands;
		TypeProcPerech* perechenProcTypes;
		VideocardsPerech* perechenVideocardVolume ;
};
