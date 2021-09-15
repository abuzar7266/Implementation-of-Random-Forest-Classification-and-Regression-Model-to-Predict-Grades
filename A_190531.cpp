#include "A_190531.h"
template<typename TypeValue>
Data<TypeValue>::Data()
{
	Next = NULL;
}

template<typename TypeValue>
Data<TypeValue>::Data(TypeValue info)
{
	data = info;
	Next = NULL;
}
template<typename TypeValue>
TypeValue Data<TypeValue>::getWarning()
{
	TypeValue Course = "";
	int x = 0;
	int count = 0;
	while (x < 10)
	{
		if (x == 9 && data[count] != ',' && data[count] != '\0' && data[count] != ' ')
		{
			Course = Course + data[count];
		}
		if (data[count] == ',' || data[count] == '\0')
		{
			x++;
		}
		count++;
	}
	return Course;
}
template<typename TypeValue>
int Data<TypeValue>::getColumn()
{
	int x = 0;
	int count = 0;
	while (data[count] != '\0')
	{
		if (data[count] == ',')
		{
			x++;
		}
		count++;
	}
	return x;
}
template<typename TypeValue>
TypeValue Data<TypeValue>::getAt(int x)
{
	int Limit = 0;
	int Length = 0;
	while (data[Length] != '\0')
	{
		if (data[Length] == ',')
		{
			Limit++;
		}
		Length++;
	}
	TypeValue DataCol = "";
	if (x < Limit + 1)
	{
		int xcount = 0;
		int count = 0;
		while (xcount < x)
		{
			if (data[count] == ',' || data[count] == '\0')
			{
				xcount++;
			}
			count++;
		}
		while (xcount < x + 1)
		{
			if (data[count] != ',' && data[count] != '\0')
				DataCol = DataCol + data[count];
			if (data[count] == ',' || data[count] == '\0')
			{
				xcount++;
			}
			count++;
		}
	}
	return DataCol;
}
template<typename TypeValue>
TypeValue Data<TypeValue>::getGrade()
{
	TypeValue Grade = "";
	int x = 0;
	int count = 0;
	while (x < 6)
	{
		if (x == 5 && data[count] != ',')
		{
			Grade = Grade + data[count];
		}
		if (data[count] == ',')
		{
			x++;
		}
		count++;
	}
	return Grade;
}
template<typename TypeValue>
TypeValue Data<TypeValue>::getCGPA()
{
	TypeValue Course = "";
	int x = 0;
	int count = 0;
	while (x < 9)
	{
		if (x == 8 && data[count] != ',')
		{
			Course = Course + data[count];
		}
		if (data[count] == ',' || data[count] == '\0')
		{
			x++;
		}
		count++;
	}
	return Course;
}
template<typename TypeValue>
bool Data<TypeValue>::CheckSem(TypeValue Sem)
{
	TypeValue Course = "";
	int x = 0;
	int count = 0;
	while (x < 2)
	{
		if (x == 1 && data[count] != ',')
		{
			Course = Course + data[count];
		}
		if (data[count] == ',' || data[count] == '\0')
		{
			x++;
		}
		count++;
	}
	if (Course == Sem)
		return true;
	else
		return false;
}
template<typename TypeValue>
TypeValue Data<TypeValue>::getCourse()
{
	TypeValue Course = "";
	int x = 0;
	int count = 0;
	while (x < 3)
	{
		if (x == 2 && data[count] != ',')
		{
			Course = Course + data[count];
		}
		if (data[count] == ',')
		{
			x++;
		}
		count++;
	}
	return Course;
}

template<class Type>
LinkedList<Type>::LinkedList()
{
	Length = 0;
	Head = NULL;
}
template<class Type>
Type LinkedList<Type>::getGrade(Type Course)
{
	Type Grade = "";
	if (Head != NULL)
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			if (Curr->getCourse() == Course)
			{
				Grade = Curr->getGrade();
				break;
			}
			Curr = Curr->Next;
		}
	}
	return Grade;
}
template<class Type>
Type LinkedList<Type>::CGPA_Performance(Type Sem)
{
	Type CGPA = GetGPA(Sem);
	Type Performance = "";
	if (CGPA >= "3.67")
	{
		Performance = "Excellent";
	}
	else if (CGPA >= "2.67")
	{
		Performance = "Good";
	}
	else if (CGPA >= "1.67")
	{
		Performance = "Average";
	}
	else if (CGPA >= "1.00")
	{
		Performance = "Bad";
	}
	else if (CGPA >= "0.00" && CGPA < "1.00")
	{
		Performance = "Worst";
	}
	else
	{
		Performance = "Unknown";
	}
	return Performance;
}
template<class Type>
Type LinkedList<Type>::Grade_Performance(Type Course)
{
	Type Performance = "";
	Type Grade = getGrade(Course);
	if (Grade == "A+" || Grade == "A" || Grade == "A-")
	{
		Performance = "Excellent";
	}
	else if (Grade == "B+" || Grade == "B" || Grade == "B-")
	{
		Performance = "Good";
	}
	else if (Grade == "C+" || Grade == "C" || Grade == "C-")
	{
		Performance = "Average";
	}
	else if (Grade == "D" || Grade == "D+")
	{
		Performance = "Bad";
	}
	else if (Grade == "FA" || Grade == "F" || Grade == "W")
	{
		Performance = "Worst";
	}
	else
	{
		Performance = "Unknown";
	}
	return Performance;
}
template<class Type>
void LinkedList<Type>::Remove(Type Course)
{
	//cout << Course << endl;
	if (Length > 0 && Head != NULL)
	{
		if (Length == 1)
		{
			if (Head->getCourse() == Course)
			{
				delete Head;
				Head = NULL;
				Length--;
			}
		}
		else
		{
			if (Head->getCourse() == Course)
			{
				Data<Type>* Curr = Head;
				Head = Head->Next;
				delete Curr;
				Length--;
			}
			else
			{
				Data<Type>* Curr = Head;
				Data<Type>* Prev = NULL;
				bool Found = true;
				while (Curr != NULL)
				{
					if (Curr->getCourse() == Course)
					{
						Prev->Next = Curr->Next;
						delete Curr;
						Length--;
						break;
					}
					Prev = Curr;
					Curr = Curr->Next;
				}
			}
		}
	}
}
template<class Type>
bool LinkedList<Type>::SearchGrade(Type Course)
{
	bool Found = false;
	if (Head != NULL)
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			Type Code = Curr->getCourse();
			if (Code == Course)
			{
				Found = true;
			}
			Curr = Curr->Next;
		}
	}
	return Found;
}
template<class Type>
bool LinkedList<Type>::VerifyGrade(Type Course, Type Grade)
{
	bool Found = false;
	if (Head != NULL && SearchGrade(Course))
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			Type Code = Curr->getCourse();
			Type GradeCode = Curr->getGrade();
			if (Code == Course && GradeCode == Grade)
			{
				Found = true;
			}
			Curr = Curr->Next;
		}
	}
	if (!SearchGrade(Course))
	{
		Found = true;
	}
	return Found;
}
template<class Type>
bool LinkedList<Type>::SearchCourse(Type Code, int Det)
{
	bool Found = false;
	if (Head != NULL)
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			Type DataNode = Curr->data;
			Type CourseCode = "";
			Type Semester = "";
			int count = 0;
			while (DataNode[count] != ',')
			{
				count++;
			}
			count++;
			while (DataNode[count] != ',')
			{
				Semester = Semester + DataNode[count];
				count++;
			}
			count++;
			while (DataNode[count] != ',')
			{
				CourseCode = CourseCode + DataNode[count];
				count++;
			}
			count++;
			CourseCode = Curr->getCourse();
			if (Code == CourseCode && Semester != "Unknown" && Det == 0)
			{
				Found = true;
				break;
			}
			if (Code == CourseCode && Det == 1)
			{
				Found = true;
				break;
			}
			Curr = Curr->Next;
		}
	}
	return Found;
}
template<class Type>
Type LinkedList<Type>::GetGPA(Type Sem)
{
	Type CGPA = "?";
	if (Length > 0 && Head != NULL)
	{
		Data<Type>* N1 = Head;
		while (N1 != NULL)
		{
			if (N1->CheckSem(Sem))
			{
				CGPA = N1->getCGPA();
				break;
			}
			N1 = N1->Next;
		}
	}
	return CGPA;
}
template<class Type>
void LinkedList<Type>::Sort()
{
	if (Head != NULL)
	{
		Data<Type>* N1 = Head;
		while (N1 != NULL)
		{
			Data<Type>* N2 = Head;
			Type N1Data = N1->getCourse();
			while (N2 != NULL)
			{
				if (N1Data < N2->getCourse())
				{
					Type Temp = N1->data;
					N1->data = N2->data;
					N2->data = Temp;
				}
				N2 = N2->Next;
			}
			N1 = N1->Next;
		}
	}
}
template<class Type>
Type LinkedList<Type>::getWarning(Type Sem)
{
	Type Warning = "?";
	if (Length > 0 && Head != NULL)
	{
		Data<Type>* N1 = Head;
		while (N1 != NULL)
		{
			if (N1->CheckSem(Sem))
			{
				Warning = N1->getWarning();
				break;
			}
			N1 = N1->Next;
		}
	}
	return Warning;
}
template<class Type>
int LinkedList<Type>::Element_Match(Type Str)
{
	int x = 0;
	if (Head != NULL)
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			if (Curr->data == Str)
			{
				x++;
			}
			Curr = Curr->Next;
		}
	}
	return x;
}
template<class Type>
Type LinkedList<Type>::Warning_Performance(Type Sem)
{
	Type Warning = getWarning(Sem);
	Type Performance = "";
	if (Warning >= "2")
		Performance = "Worst";
	else if (Warning == "1")
		Performance = "Average";
	else if (Warning == "0")
		Performance = "Excellent";
	return Performance;
}
template<class Type>
bool LinkedList<Type>::SearchInsert(Type Sem, Type Course)
{
	if (Head != NULL)
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			if (Curr->CheckSem(Sem) && Curr->getCourse() == Course)
			{
				return true;
			}
			Curr = Curr->Next;
		}
	}
	return false;
}
template<class Type>
void LinkedList<Type>::insert(Type val)
{
	Data<Type>* Node = new Data<Type>(val);
	if (Head == NULL)
	{
		Head = Node;
		Length = 1;
	}
	else
	{
		Data<Type>* Curr = Head;
		while (Curr->Next != NULL)
		{
			Curr = Curr->Next;
		}
		Curr->Next = Node;
		Length++;
	}
}
template<class Type>
Type& LinkedList<Type>::get(int Index)
{
	Type Datas;
	if (Head != NULL)
	{
		Data<Type>* Curr = Head;
		int count = 0;
		while (count != Index)
		{
			Curr = Curr->Next;
			count++;
		}
		return Curr->data;
	}
	else
		return Datas;
}
template<class Type>
bool LinkedList<Type>::VerifyUnique(Type Str)
{
	if (Head != NULL)
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			if (Curr->data == Str)
			{
				return true;
			}
			Curr = Curr->Next;
		}
	}
	return false;
}
template<class Type>
LinkedList<Type>* LinkedList<Type>::Partitioning(Type Labels, int f)
{
	LinkedList<Type>* Partition = new LinkedList<Type>;
	if (Head != NULL)
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			if (Curr->getAt(f) == Labels)
			{
				Partition->insert(Curr->getAt(Curr->getColumn()));
			}
			Curr = Curr->Next;
		}
	}
	return Partition;
}
template<class Type>
LinkedList<Type>* LinkedList<Type>::Partitioning_2(Type Labels, int f)
{
	LinkedList<Type>* Partition = new LinkedList<Type>;
	if (Head != NULL)
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			if (Curr->getAt(f) == Labels)
			{
				Partition->insert(Curr->data);
			}
			Curr = Curr->Next;
		}
	}
	return Partition;
}
template<class Type>
int LinkedList<Type>::getCount()
{
	return Head->getColumn();
}
template<class Type>
void LinkedList<Type>::Remove_At_End()
{
	if (Head != NULL)
	{
		if (Head->Next == NULL)
		{
			delete Head;
			Head = NULL;
			Length--;
		}
		else
		{
			Data<Type>* Curr = Head;
			while (Curr->Next->Next != NULL)
			{
				Curr = Curr->Next;
			}
			delete Curr->Next;
			Curr->Next = NULL;
			Length--;
		}
	}
}
template<class Type>
void LinkedList<Type>::Clear()
{
	while (Length > 0)
	{
		Remove_At_End();
	}
}
template<class Type>
void LinkedList<Type>::Sort_Data()
{
	if (Head != NULL)
	{
		Data<Type>* N1 = Head;
		while (N1 != NULL)
		{
			Data<Type>* N2 = Head;
			while (N2 != NULL)
			{
				if (N1->data < N2->data)
				{
					Type Temp = N1->data;
					N1->data = N2->data;
					N2->data = Temp;
				}
				N2 = N2->Next;
			}
			N1 = N1->Next;
		}
	}
}
template<class Type>
int LinkedList<Type>::getColumn()
{
	return Head->getColumn();
}
template<class Type>
void LinkedList<Type>::display()
{
	if (Length > 0 && Head != NULL)
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			cout << Curr->data << endl;
			Curr = Curr->Next;
		}
	}
}
template<class Type>
int LinkedList<Type>::getLength()
{
	return Length;
}
template<class Type>
void LinkedList<Type>::Replace(Type val)
{
	Data<Type>* Node = new Data<Type>(val);
	Type CourseN = Node->getCourse();
	Data<Type>* Curr = Head;
	while (Curr != NULL)
	{
		if (Curr->getCourse() == CourseN)
		{
			Curr->data = val;
			break;
		}
		Curr = Curr->Next;
	}
	delete Node;
}
template<class Type>
LinkedList<Type>& LinkedList<Type>::getFeatureColumn(int x)
{
	LinkedList<Type>* Feature = new LinkedList<Type>;
	if (Head != NULL)
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			Feature->insert(Curr->getAt(x));
			Curr = Curr->Next;
		}
	}
	return *Feature;
}
template<class Type>
LinkedList<Type>& LinkedList<Type>::getLabelColumn()
{
	LinkedList<Type>* Feature = new LinkedList<Type>;
	if (Head != NULL)
	{
		Data<Type>* Curr = Head;
		while (Curr != NULL)
		{
			Feature->insert(Curr->getAt(Curr->getColumn()));
			Curr = Curr->Next;
		}
	}
	return *Feature;
}



template<typename Type>
void Dataset_Deallocate(LinkedList<Type>**& Temp2, int& DataStudents)
{
	for (int i = 0; i < DataStudents; i++)
	{
		Temp2[i]->Clear();
	}
	delete[]Temp2;
}
template<class Type>
LinkedList<Type>& Dataset_Linked(LinkedList<Type>**& Temp2, int DataStudents)
{
	LinkedList<Type>* Final = new LinkedList<Type>;
	Type CourseArr[15] = { "CL118"	,"CL217",	"CS118",	"CS217"	,"EE182",	"EE227",	"EL227",	"MT104",	"MT119"	,"MT224",	"SL101",	"SS101"	,"SS111",	"SS113"	,"SS122" };
	for (int j = 0; j < DataStudents; j++)
	{
		Type Str = "";
		for (int i = 0; i < 15; i++)
		{
			Type CourseCode = CourseArr[i];
			if (CourseCode != "CS201")
			{
				Str = Str + Temp2[j]->Grade_Performance(CourseCode) + ",";
			}
		}
		Str = Str + Temp2[j]->CGPA_Performance("Spring") + "," + Temp2[j]->Warning_Performance("Spring") + "," + Temp2[j]->Grade_Performance("CS201");
		Final->insert(Str);
	}
	return  *Final;
}
template<class Type>
void Read_File(Type Files, LinkedList<Type>**& Temp, int& x, LinkedList<Type>& CourseList)
{
	bool a = false;
	fstream File(Files, ios::in);
	Type line = "?";
	while (line != "")
	{
		getline(File, line);
		if (line == "")
			break;
		else
		{
			if (a)
			{
				string Record = "";
				int Count = 0;
				while (line[Count] != ',')
				{
					Record = Record + line[Count];
					Count++;
				}
				int f = stoi(Record);
				if (x == 0)
				{
					Temp = new LinkedList<Type> * [x + 1];
					Temp[0] = new LinkedList<Type>;
					x = 1;
				}
				if (f == x)
				{
					Data<Type> Node(line);
					Type Nodes = Node.getCourse();
					LinkedList<Type>** New = new LinkedList<Type> * [x + 1];
					for (int i = 0; i < x + 1; i++)
					{
						if (i < x)
							New[i] = Temp[i];
						else
							New[i] = new LinkedList<Type>;
					}
					bool Found = true;
					int CLength = CourseList.getLength();
					for (int i = 0; i < CLength; i++)
					{
						if (CourseList.get(i) == Nodes)
						{
							Found = false;
							break;
						}
					}
					if (Found)
						CourseList.insert(Nodes);
					New[f]->insert(line);
					Temp = New;
					x++;
				}
				else
				{
					Data<Type> Node(line);
					Type Nodes = Node.getCourse();
					//cout << Node.getCourse() << endl;
					if (!Temp[f]->SearchCourse(Nodes, 1))
					{
						bool Found = true;
						int CLength = CourseList.getLength();
						for (int i = 0; i < CLength; i++)
						{
							if (CourseList.get(i) == Nodes)
							{
								Found = false;
								break;
							}
						}
						if (Found)
							CourseList.insert(Nodes);
						Temp[f]->insert(line);
					}
					else
					{
						Temp[f]->Replace(line);
					}
				}
			}
			else
				a = true;
		}
	}
}
template<class Type>
void Get_Student(Type Course, LinkedList<Type>**& Temp, int& DataStudents, int x)
{
	for (int i = 0; i < x; i++)
	{
		if (Temp[i]->SearchCourse(Course))
		{
			DataStudents++;
		}
		else
		{
			Temp[i]->Clear();
			Temp[i] = NULL;
		}
	}
}
template<typename Type>
void Split_Dataset(LinkedList<Type>& Dataset, Type File1, Type File2)
{
	int count = 0;
	fstream File(File1, ios::out || ios::in || ios::app);
	File.clear();
	for (int i = 0; i < (Dataset.getLength() * 0.8); i++)
	{
		int x = Dataset.getColumn();
		for (int j = 0; j < x; j++)
		{
			Data<Type> A;
			A.data = Dataset.get(j);
			if (j < x - 1) 
			{
				File << A.getAt(j) << ",";
			}
			else
			{
				File << A.getAt(j) << endl;
			}
		}
		count++;
	}
	fstream File3(File2, ios::out || ios::in || ios::app);
	File3.clear();
	for (int i = count - 1; i < Dataset.getLength(); i++)
	{
		int x = Dataset.getColumn();
		for (int j = 0; j < x; j++)
		{
			Data<Type> A;
			A.data = Dataset.get(j);
			if (j < x - 1) 
			{
				File3 << A.getAt(j) << ",";
			}
			else
			{
				File3 << A.getAt(j) << endl;
			}
		}
		count++;
	}
}
template<class Type>
LinkedList<Type>& preProcessing(Type& Files)
{
	LinkedList<Type> CourseList;
	LinkedList<Type>** Temp = NULL;
	int x = 0;
	Read_File(Files, Temp, x, CourseList);
	int DataStudents = 0;
	Type CourseCo = "CS201";
	Get_Student(CourseCo, Temp, DataStudents, x);
	LinkedList<Type>** Temp2 = new LinkedList<Type> * [DataStudents];
	int j = 0;
	for (int i = 0; i < x; i++)
	{
		if (Temp[i] != NULL)
		{
			Temp2[j] = Temp[i];
			j++;
		}
	}
	CourseList.Sort_Data();
	int CLength = CourseList.getLength();
	for (int i = 0; i < CLength; i++)
	{
		bool Valid = false;
		Type Course = CourseList.get(i);
		for (int j = 0; j < DataStudents; j++)
		{
			if (!Temp2[j]->VerifyGrade(Course, "UK"))
			{
				Valid = true;
				break;
			}
		}
		if (!Valid)
		{
			for (int j = 0; j < DataStudents; j++)
			{
				Temp2[j]->Remove(Course);
			}
		}
	}
	CourseList.Clear();
	LinkedList<Type> Final = Dataset_Linked(Temp2, DataStudents);
	Dataset_Deallocate(Temp2, DataStudents);
	//string File1 = "./TestFiles/train1Dataset.csv";
	//string File2 = "./TestFiles/test1Dataset.csv";
	//Split_Dataset(Final, File1, File2);
	delete[]Temp;
	return  Final;
}
template<typename Type>
float calculateEntropyOnFeature(LinkedList<Type>& Dataset, int FeatureIndex)
{
	LinkedList<Type> Column = Dataset.getFeatureColumn(FeatureIndex);
	LinkedList<Type> Labels;
	for (int i = 0; i < Column.getLength(); i++)
	{
		Type Col = Column.get(i);
		if (!Labels.VerifyUnique(Column.get(i)))
		{
			Labels.insert(Col);
		}
	}
	float Entropy = 0.0000000000f;
	float* Probability = new float[Labels.getLength()];
	int ColumnLabel = Labels.getLength();
	for (int i = 0; i < ColumnLabel; i++)
	{
		Probability[i] = (Column.Element_Match(Labels.get(i)) / (Column.getLength() * 1.00));
	}
	LinkedList<Type>** Partitions = new LinkedList<Type> * [Labels.getLength()];
	for (int i = 0; i < ColumnLabel; i++)
	{
		Partitions[i] = Dataset.Partitioning(Labels.get(i), FeatureIndex);
	}
	LinkedList<Type>* LabelList = new LinkedList<Type>[ColumnLabel];
	for (int i = 0; i < ColumnLabel; i++)
	{
		for (int j = 0; j < Partitions[i]->getLength(); j++)
		{
			Type Col = Partitions[i]->get(j);
			if (!LabelList[i].VerifyUnique(Col))
			{
				LabelList[i].insert(Col);
			}
		}
	}
	float* ProbabilityLab = new float[ColumnLabel];
	for (int i = 0; i < ColumnLabel; i++)
	{
		int Total = Partitions[i]->getLength();
		for (int j = 0; j < LabelList[i].getLength(); j++)
		{
			float A = Partitions[i]->Element_Match(LabelList[i].get(j)) / (Total * 1.00);
			float P = (A * log2(A));
			Entropy = Entropy + (P * Probability[i]);
		}
	}
	delete[]Probability;
	delete[]ProbabilityLab;
	for (int i = 0; i < ColumnLabel; i++)
	{
		Partitions[i]->Clear();
		delete Partitions[i];
		for (int j = 0; j < LabelList[i].getLength(); j++)
		{
			LabelList[j].Clear();
		}
	}
	delete[]LabelList;
	delete[]Partitions;
	Column.Clear();
	return Entropy * (-1);
}
template<class Type>
void sortLabels(LinkedList<Type>& arr)
{
	LinkedList<Type> Label;
	Type sequence[] = { "Excellent","Good","Average","Bad","Worst","Unknown" };
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < arr.getLength(); i++)
		{
			if (sequence[j] == arr.get(i))
			{
				Label.insert(sequence[j]);
			}
		}
	}
	arr.Clear();
	for (int i = 0; i < Label.getLength(); i++)
	{
		arr.insert(Label.get(i));
	}
	//arr.display();
	Label.Clear();
}
template<class Type>
float calculateTotalEntropy(LinkedList<Type> Dataset)
{
	float Entropy = 0.000000f;
	LinkedList<Type> Column = Dataset.getLabelColumn();
	LinkedList<Type> Labels;
	for (int i = 0; i < Column.getLength(); i++)
	{
		Type Col = Column.get(i);
		if (!Labels.VerifyUnique(Column.get(i)))
		{
			Labels.insert(Col);
		}
	}
	for (int i = 0; i < Labels.getLength(); i++)
	{
		float P = (Column.Element_Match(Labels.get(i)) / (Column.getLength() * 1.00));
		Entropy += P * log2(P);
	}
	return Entropy * (-1);
}
template<typename Type>
LinkedList<Type>& read_csv(Type FilePath)
{
	string line = "";
	LinkedList<Type>* List = new LinkedList<Type>;
	int x = 0;
	fstream File(FilePath, ios::in);
	do {
		getline(File, line);
		if (line == "")
		{
			break;
		}
		else
		{
			if (x != 0)
				List->insert(line);
			else
				x = 1;
		}
	} while (!File.eof());
	//List->display();
	return *List;
}
template<typename T>
void preprintTree(treeNode<T>*& root, LinkedList<T>& Traversal)
{
	if (root->next == NULL)
		return;
	Traversal.insert(root->featureid);
	for (int i = 0; i < root->ChildCount; i++)
	{
		preprintTree((*root).next[i], Traversal);
	}
}
template<typename T>
void postprintTree(treeNode<T>*& root, LinkedList<T>& Traversal)
{
	if (root->next == NULL)
		return;
	for (int i = 0; i < root->ChildCount; i++)
	{
		postprintTree((*root).next[i], Traversal);
	}
	Traversal.insert(root->featureid);
}
template<typename T>
void orderprintTree(treeNode<T>*& root, LinkedList<T>& Traversal)
{
	if (root->next == NULL)
	{
		return;
	}
	int count = -1;
	if (root->ChildCount != 0)
	{
		for (int i = 0; i < (root->ChildCount) - 1; i++)
		{
			orderprintTree((*root).next[i], Traversal);
			count++;
		}
	}
	//cout << root->featureid << ",";
	Traversal.insert(root->featureid);
	if (root->ChildCount != 0)
	{
		for (int i = root->ChildCount - 1; i > count; i--)
		{
			orderprintTree((*root).next[i], Traversal);
		}
	}
}
template<class T>
void Insert_By(treeNode<T>*& root, LinkedList<T> trainDataset, int start, int WindowSize, LinkedList<int> arr, LinkedList<int> arr2)
{
	float Entropy = 0.00000f;
	float Gain = 0.000000f;
	float total = calculateTotalEntropy(trainDataset);
	if (total == 0)
	{
		root->featureid = (trainDataset.getLabelColumn()).get(0);
		return;
	}
	int Featureidx = -1;
	for (int i = start; i < WindowSize + start; i++)
	{
		float E = calculateEntropyOnFeature(trainDataset, i % 17);
		float G = total - E;
		bool replica = false;
		if (Gain < G && !arr2.VerifyUnique(i % 17))
		{
			Gain = G;
			Featureidx = i;
		}
	}
	if (Featureidx >= 0)
	{
		arr2.insert(Featureidx);
		LinkedList<T> Feature = trainDataset.getFeatureColumn(Featureidx);
		LinkedList<T> Label;
		for (int i = 0; i < Feature.getLength(); i++)
		{
			if (!Label.VerifyUnique(Feature.get(i)))
			{
				Label.insert(Feature.get(i));
			}
		}
		sortLabels(Label);
		LinkedList<T>** PartitionList = new LinkedList<T> * [Label.getLength()];
		for (int i = 0; i < Label.getLength(); i++)
		{
			for (int j = 0; j < trainDataset.getLength(); j++)
			{
				PartitionList[i] = trainDataset.Partitioning_2(Label.get(i), Featureidx);
			}
		}
		if (root == NULL)
			root = new treeNode<T>;
		root->featureid = to_string(Featureidx);
		root->next = new treeNode<T> * [6/*Label.getLength()*/];
		T sequence[] = { "Excellent","Good","Average","Bad","Worst","Unknown" };
		root->ChildCount = Label.getLength();
		for (int i = 0; i < 6; i++)
			(*root).next[i] = new treeNode<T>;
		LinkedList<int> arr3;
		//LinkedList<int> arr4;
		int x = 0;
		for (int i = 0; i < Label.getLength();)
		{
			if (Label.get(i) == sequence[x])
			{
				Insert_By((*root).next[x], *PartitionList[i], 0, 17, arr, arr3);
				i++;
			}
			x++;
		}
	}
}



template<class T>

void Tree<T>::build_tree(LinkedList<T> trainDataset, int start, int WindowSize)
{
	LinkedList<int> arr;
	LinkedList<int> arr2;
	Insert_By(root, trainDataset, start, WindowSize, arr, arr2);
}
template<class T>
T Tree<T>::preOrderTraversal()
{
	T Traversal_Data = "";
	LinkedList<T> Traversal;
	preprintTree(root, Traversal);
	for (int i = 0; i < Traversal.getLength(); i++)
	{
		if (i < Traversal.getLength() - 1)
		{
			Traversal_Data = Traversal_Data + Traversal.get(i) + ",";
		}
		else
		{
			Traversal_Data = Traversal_Data + Traversal.get(i);
		}
	}
	return Traversal_Data;
}
template<class T>
T Tree<T>::postOrderTraversal()
{
	T Traversal_Data = "";
	LinkedList<T> Traversal;
	postprintTree(root, Traversal);
	for (int i = 0; i < Traversal.getLength(); i++)
	{
		if (i < Traversal.getLength() - 1)
		{
			Traversal_Data = Traversal_Data + Traversal.get(i) + ",";
		}
		else
		{
			Traversal_Data = Traversal_Data + Traversal.get(i);
		}
	}
	return Traversal_Data;
}
template<class T>
float Tree<T>::accuracy(LinkedList<T> testDataset)
{
	LinkedList<LinkedList<T>> Prediction = predictAll(testDataset);
	LinkedList<T> Original = testDataset.getLabelColumn();
	float matchCount = 0;
	for (int i = 0; i < Original.getLength(); i++)
	{
		for (int j = 0; j < Prediction.getLength(); j++) {
			if (Original.get(i) == Prediction.get(j))
			{
				matchCount++;
			}
		}
	}
	return ((matchCount * 1.00) / testDataset.getLength());
}
template<class T>
T Tree<T>::inOrderTraversal()
{
	T Traversal_Data = "";
	LinkedList<T> Traversal;
	orderprintTree(root, Traversal);
	for (int i = 0; i < Traversal.getLength(); i++)
	{
		if (i < Traversal.getLength() - 1)
		{
			Traversal_Data = Traversal_Data + Traversal.get(i) + ",";
		}
		else
		{
			Traversal_Data = Traversal_Data + Traversal.get(i);
		}
	}
	return Traversal_Data;
}
template<class T>
void Tree<T>::getPrediction(treeNode<T>* node, LinkedList<T> Student, int rowIndex, T& labe)
{
	if (node->next == NULL)
	{
		if (node->featureid != "")
			labe = node->featureid;
		else
			labe = "Unknown";
		return;
	}
	T data = (Student.getFeatureColumn(stoi(node->featureid))).get(rowIndex);
	int count = -1;
	T sequence[] = { "Excellent","Good","Average","Bad","Worst","Unknown" };
	for (int i = 0; i < 6; i++)
	{
		if (sequence[i] == data)
		{
			count = i;
			break;
		}
	}
	if (count >= 0 && count <= 5)
	{
		treeNode<T>* Node = node->next[count];
		getPrediction(Node, Student, rowIndex, labe);
	}
}
template<class T>
T Tree<T>::predictOne(LinkedList<T> testDataset, int rowIndex)
{
	T predict = "X";
	getPrediction(root, testDataset, rowIndex, predict);
	return predict;
}
template<class T>
LinkedList<T> Tree<T>::predictAll(LinkedList<T> testDataset)
{
	LinkedList<T> Result;
	for (int i = 0; i < testDataset.getLength(); i++)
	{
		Result.insert(predictOne(testDataset, i));
	}
	return Result;
}


template<class T>
Forest<T>::Forest(int NTrees, int WindowSiz, int stepSiz)
{
	this->TForest = new Tree<T>[NTrees];
	this->NumTree = NTrees;
	this->WindowSize = WindowSiz;
	this->stepSize = stepSiz;
}
template<class T>
void Forest<T>::build_forest(LinkedList<T> trainDataset)
{
	int start = 0;
	int WSize = WindowSize;
	for (int i = 0; i < NumTree; i++)
	{
		TForest[i].build_tree(trainDataset, start, WindowSize);
		start = start + stepSize;
	}
}
template<class T>
void Forest<T>::PostTraversal()
{
	for (int i = 0; i < NumTree; i++)
	{
		cout << TForest[i].inOrderTraversal() << endl;
	}
}
template<class T>
LinkedList<T>& Forest<T>::predictOne(LinkedList<T> testDataset, int rowIndex)
{
	LinkedList<T> Data;
	for (int i = 0; i < NumTree; i++)
	{
		Data.insert(TForest[i].predictOne(testDataset, rowIndex));
	}
	LinkedList<T> Labels;
	for (int i = 0; i < Data.getLength(); i++)
	{
		T dataFile = Data.get(i);
		if (!Labels.VerifyUnique(dataFile))
		{
			Labels.insert(dataFile);
		}
	}
	sortLabels(Labels);
	int* arr = new int[Labels.getLength()];
	for (int i = 0; i < Labels.getLength(); i++)
	{
		arr[i] = 0;
		for (int j = 0; j < Data.getLength(); j++)
		{
			if (Labels.get(i) == Data.get(j))
			{
				arr[i]++;
			}
		}
	}

	int LargestOccur = -1;
	for (int i = 0; i < Labels.getLength(); i++)
	{
		if (LargestOccur < arr[i])
		{
			LargestOccur = arr[i];
		}
	}
	LinkedList<T> Data2;
	for (int i = 0; i < Labels.getLength(); i++)
	{
		if (LargestOccur == arr[i])
		{
			Data2.insert(Labels.get(i));
			break;
		}
	}
	Data.Clear();
	Labels.Clear();
	return Data2;
}
template<class T>
LinkedList<LinkedList<T>>& Forest<T>::predictAll(LinkedList<T> testDataset)
{
	LinkedList<LinkedList<T>> Predict;
	for (int i = 0; i < testDataset.getLength(); i++)
	{
		Predict.insert(predictOne(testDataset, i));
	}
	return Predict;
}
template<class T>
float Forest<T>::accuracy(LinkedList<T> testDataset)
{
	LinkedList<LinkedList<T>> Prediction = predictAll(testDataset);
	LinkedList<T> Original = testDataset.getLabelColumn();
	float matchCount = 0;
	for (int i = 0; i < Original.getLength(); i++)
	{
		if (Original.get(i) == Prediction.get(i).get(0))
		{
			matchCount++;
		}
	}
	return ((matchCount * 1.00) / testDataset.getLength());
}