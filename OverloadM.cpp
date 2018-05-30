#include "CompHeader.h"
//Перегрузки для структур RECORD & COMP
//ввод из консоли
std::istream& operator>>(std::istream& in, COMP& a){
	std::cout << "Введите марку процессора: ";
	in >> a.ProcName;
	std::cout << "Введите тип процессора(хар-ки): ";
	in >> a.ProcType; 
	std::cout << "Введите частоту процессора: ";
	in >> a.ClockSpeed; 
	std::cout << "Введите название видеокарты: ";
	in >> a.Graphics;
	std::cout << "Введите объем видеокарты: ";
	in >> a.GraphicVolume;
	std::cout << "Введите объем ОЗУ: ";
	in >> a.RAM; 
	std::cout << "Введите объем жесткого диска: "; 
	in >> a.Storage; 
	return in;
}
std::istream& operator>>(std::istream& in, RECORD& a){
	std::cin >> a.CompInfo;
	std::cout << "Введите цену: ";
	in >> a.CompCost;
	std::cout << "Введите количество компьютеров на складе: ";
	in >> a.CompInStock;
	return in;
}

//ввод из файла
std::ifstream& operator>>(std::ifstream& in, COMP& a){
	in >> a.ProcName >> a.ProcType  >> a.ClockSpeed >> a.Graphics >> a.GraphicVolume >> a.RAM >> a.Storage;
	return in;
}
std::ifstream& operator>>(std::ifstream& in, RECORD& a){
	in >> a.CompCost >> a.CompInStock;
	in >> a.CompInfo;
	return in;
}

//вывод в консоль

std::ostream& operator<<(std::ostream& out, COMP a){
	out << std::setw(16) << a.ProcName << "|" << std::setw(19) <<
   		a.ProcType << "|" << std::setw(9) << a.ClockSpeed <<
	       	"|" << std::setw(24) << a.Graphics << "|" <<
	       	std::setw(10) << a.GraphicVolume << "|" << 
		std::setw(5) <<	a.RAM << "|" << std::setw(17) << 
		a.Storage << "|\n";
	return out;
}
std::ostream& operator<<(std::ostream& out, RECORD a){
	out << std::setw(6) <<a.CompCost << "|" << std::setw(6) << a.CompInStock<< "|" << a.CompInfo;
	return out;
}
//вывод в файл
std::ofstream& operator<<(std::ofstream& out, COMP a){
	out << std::setw(16) << a.ProcName << "|" << std::setw(19) << a.ProcType << "|" << std::setw(9) << a.ClockSpeed << "|" << std::setw(24) << a.Graphics << "|" << std::setw(10) << a.GraphicVolume << "|" << std::setw(5) << a.RAM << "|" << std::setw(17) << a.Storage << "|\n";
	return out;
}

std::ofstream& operator<<(std::ofstream& out, RECORD a){
	out << std::setw(6) <<a.CompCost << "|" << std::setw(6) << a.CompInStock << "|"; 
	out << a.CompInfo;
	return out;
}


// ПЕРЕГРУЗКИ операторов сравнения
bool operator<(COMP& a, COMP& b){
	if (a.ProcType< b.ProcType)
		return true;
	else if (a.ProcType == b.ProcType && a.ClockSpeed < b.ClockSpeed)
		return true;
	return false;
}

bool operator==(COMP& a, COMP& b){
	return a.ProcName == b.ProcName;
}

bool operator<(RECORD& a, RECORD& b){
	if (a.CompInfo.ProcName < b.CompInfo.ProcName)
		return true;
	else if (a.CompInfo.ProcName == b.CompInfo.ProcName &&
			a.CompInfo.ProcType < b.CompInfo.ProcType)
		return true;
	return false;
}
