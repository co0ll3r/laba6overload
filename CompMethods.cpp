#include "CompHeader.h"

void swap(workComputers& first, workComputers& second){
	std::swap(first.size, second.size);
	std::swap(first.CapabilitiesComp, second.CapabilitiesComp);
}
workComputers::workComputers(const workComputers& copy) : workComputers(copy.size){
	std::copy(copy.CapabilitiesComp, copy.CapabilitiesComp + size, CapabilitiesComp);
}

workComputers& workComputers::operator=(workComputers copy){
	if(&copy != this)
		swap(*this, copy);
	return *this;
}

void workComputers::testCopyOperator(){
	workComputers eg;
	if (true){
		workComputers eg2;
		eg2 = *this;
		std::cout << "второй объект присваиваем первому:\n";
		eg = eg2;
		std::cout << "вывод второго объекта:\n";
		std::cout << eg2;
	}
	std::cout << "очистка второго объекта\n";
	eg = *this;
	std::cout << "вывод первого объекта:\n";
	std::cout << eg;
}

void workComputers::testCopyConstructor(){
	workComputers eg(*this);
	std::cout << "вывод первого объекта:\n";
	std::cout << eg;
	std::cout << "создаем второй объект, с помощью конструтора:\n";
	workComputers eg2(eg);
	std::cout << "вывод второго объекта:\n";
	std::cout << eg2;
}


void workComputers::InputFromFile(){
       std::string file;
       std::cout << "Введите имя файла для чтения\n";
       std::cin >> file;
       std::ifstream fin;
       fin.open(file);
       if (fin.fail()){
               std::cout << file << " не удалось создать файл\n";
               return;
       }
       RECORD ab;      
       RECORD* CopyCapComp;
       int i = -1;
       char end = '1';
       while(end != '\0'){
               if (fin.fail()) 
                       break;
               i++;
               fin >> ab >> end;
               CopyCapComp = new RECORD[i + 1];
               for (int j = 0; j < i; j++)
                       if (CapabilitiesComp != NULL)
                               CopyCapComp[j] = CapabilitiesComp[j];
               CopyCapComp[i] = ab;
               if (CapabilitiesComp != NULL)
                       delete [] CapabilitiesComp;
               CapabilitiesComp = CopyCapComp;
               CopyCapComp = NULL;
       }
       size = ++i;
}

void workComputers::OutputInFile(){
	std::string file;
	std::cout << "Введите имя файла для сохранения\n";
	std::cin >> file;
	std::ofstream fout;
	fout.open(file);
	if (fout.fail()){
		std::cout << file << " не удалось открыть файл\n";
		return;
	}
	fout << std::setfill('-') << std::setw(129) << "\n" <<
	     "|Номер| Цена | Кол. |                 Процессор                    |              Видеокарта           | ОЗУ | Размер жесткого |\n" <<
             "|     |      |      |----------------------------------------------|-----------------------------------|     |                 |\n" << 
	     "|     |(Руб.)|(штук)|    Название    |        Тип        | Частота |        Название        | Объём Гб |  Гб |      (Гб)       |\n" <<
	             std::setw(129) << "\n"; 
	for (int i = 0; i < size; i++){
		fout << std::setfill(' ') << "|" << std::setw(5) << i + 1 << "|";
 		fout << CapabilitiesComp[i];
		fout << std::setfill('-') << std::setw(129) << "\n"; 
	}
}

void workComputers::Delete_comp(){
	if (CapabilitiesComp == NULL)
	{
		std::cout << "Загрузите данные(массив элементов), т.к. массив пуст";
		return;	
	}
	int n;
	char ch;
	std::cout << *this;
	std::cout << "Введите номер строки для удаления: ";
	std::cin >> n;
	if (n < 1 || n > size){
		std::cout << " нет такой строки\n";
		return;
	}
	n--;
	std::cout << " удалить строку(press y):";
	std::cin >> ch;
	if (ch == 'y' || ch == 'Y'){
		RECORD* CopyCapComp = new RECORD[size - 1];
		int i, j;
		for (i = 0; i < n; i++)
			CopyCapComp[i] = CapabilitiesComp[i];
		for (i = n + 1, j = n; i < size; i++, j++)
			CopyCapComp[j] = CapabilitiesComp[i];
		if (CapabilitiesComp != NULL)
			delete [] CapabilitiesComp;
		CapabilitiesComp = CopyCapComp;
		CopyCapComp = NULL;
		size--;
	}
}

void workComputers::swapElementsInMassive(unsigned index){
	RECORD temp = CapabilitiesComp[index];
	CapabilitiesComp[index] = CapabilitiesComp[index - 1];
	CapabilitiesComp[index - 1] = temp;
}

void workComputers::SortProcTypeAndClock(){
	std::cout << "Сортировка по типу процессора и частоте: \n";
	unsigned n = size; 
	bool flag;
	do{
		flag = false;
		for (unsigned i = 1; i < n; i++)
		{
			if (CapabilitiesComp[i].CompInfo < CapabilitiesComp[i - 1].CompInfo){
				swapElementsInMassive(i);
				flag = true;
			}
		}
		n--;
	} while (flag);
	std::cout << *this;
}

void workComputers::SortProcName(){
	std::cout << "Сортировка по названию процессора: \n";
	unsigned n = size; 
	bool flag;
	do{
		flag = false;
		for (unsigned i = 1; i < n; i++)
		{
			if (CapabilitiesComp[i] < CapabilitiesComp[i - 1])
			{
				swapElementsInMassive(i);
				flag = true;
			}
		}
		n--;
	} while (flag);
	std::cout << *this;
}

void workComputers::SortPrice(){
	std::cout << "Сортировка по цене: \n";
	bool flag;
	unsigned n = size; 
	do{
		flag = false;
		for (unsigned i = 1; i < n; i++)
		{
			if (CapabilitiesComp[i - 1].CompCost > CapabilitiesComp[i].CompCost){
				swapElementsInMassive(i);
				flag = true;
			}
		}
		n--;
	} while(flag);
	std::cout << *this;
}
