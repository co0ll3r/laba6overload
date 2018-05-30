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

// перегрузка сравнений 1 перечен
bool operator<(BrandPerech& a, BrandPerech& b){
	return a.ProcName < b.ProcName;
}
bool operator==(BrandPerech& a, BrandPerech& b){
	return a.ProcName == b.ProcName;
}
// 2 перечень 
bool operator<(TypeProcPerech& a, TypeProcPerech& b){
	return a.Count < b.Count;
}
bool operator==(TypeProcPerech& a, TypeProcPerech& b){
	return a.Count == b.Count;
}
// 3 перечень
bool operator<(VideocardsPerech& a, VideocardsPerech& b){
	return a.GraphicVolume < b.GraphicVolume;
}
bool operator==(VideocardsPerech& a, VideocardsPerech& b){
	return a.GraphicVolume == b.GraphicVolume;
}
