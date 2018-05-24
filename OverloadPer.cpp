#include "CompHeader.h"
// перегрузки выводов в консоль
std::ostream& operator<<(std::ostream& out, BrandPerech a){
	out << '|' << std::setw(29) << a.ProcName << '|' << std::setw(24) << a.Count << "|\n";
	return out;
}
std::ostream& operator<<(std::ostream& out, TypeProcPerech a){
	out << '|' << std::setw(24) << a.ProcType<< '|' << std::setw(24) << a.Count << "|\n";
	return out;
}
std::ostream& operator<<(std::ostream& out, VideocardsPerech a){
	out << '|' << std::setw(27) << a.GraphicVolume << '|' << std::setw(24) << a.Count << "|\n";
	return out;
}
// перегрузки выводов в файл
std::ofstream& operator<<(std::ofstream& out, BrandPerech a){
	out << '|' << std::setw(29) << a.ProcName << '|' << std::setw(24) << a.Count << "|\n";
	return out;
}
std::ofstream& operator<<(std::ofstream& out, TypeProcPerech a){
	out << '|' << std::setw(24) << a.ProcType<< '|' << std::setw(24) << a.Count << "|\n";
	return out;
}

std::ofstream& operator<<(std::ofstream& out, VideocardsPerech a){
	out << '|' << std::setw(27) << a.GraphicVolume << '|' << std::setw(24) << a.Count << "|\n";
	return out;
}

std::ofstream& operator<<(std::ofstream& out, Perechen a){
	out << a.perechenBrands;
	out << a.perechenProcTypes;
	out << a.perechenVideocardVolume;
	return out;
}
