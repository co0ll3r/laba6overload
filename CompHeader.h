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

class COMP{
public:
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

class RECORD{
public:
	COMP CompInfo;
	double CompCost;
	int CompInStock;
	
	/* overloads*/
	friend std::istream& operator>>(std::istream&, RECORD&);
	friend std::ostream& operator<<(std::ostream&, RECORD);
	friend std::ifstream& operator>>(std::ifstream&, RECORD&);
	friend std::ofstream& operator<<(std::ofstream&, RECORD);
};

class BrandPerech{
public:
	std::string ProcName;
	int Count;

	/* overloads*/
	friend std::ostream& operator<<(std::ostream&, BrandPerech);
	friend std::ofstream& operator<<(std::ofstream&, BrandPerech);
};

class TypeProcPerech{
public:
	std::string ProcType;
	int Count;

	/* overloads*/
	friend std::ostream& operator<<(std::ostream&, TypeProcPerech);
	friend std::ofstream& operator<<(std::ofstream&, TypeProcPerech);
};

class VideocardsPerech{
public:
 	double GraphicVolume;
	int Count;

	/* overloads*/
	friend std::ostream& operator<<(std::ostream&, VideocardsPerech);
	friend std::ofstream& operator<<(std::ofstream&, VideocardsPerech);
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

		/*overloads*/
		Perechen& operator=(Perechen); 
		friend std::ofstream& operator<<(std::ofstream&, Perechen);
		friend std::ostream& operator<<(std::ostream&, Perechen);
		
		/* Methods */
		friend void swap(Perechen&, Perechen&);
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
//		friend void saveAllPerech(Perechen);

		friend void makePerechen1(workComputers, Perechen&);
		friend void makePerechen2(workComputers, Perechen&);
		friend void makePerechen3(workComputers, Perechen&);
	private:
		int pBrandlen, pProclen, pVideolen;
		BrandPerech* perechenBrands;
		TypeProcPerech* perechenProcTypes;
		VideocardsPerech* perechenVideocardVolume ;
};
