#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;
template<class TypeValue>
struct Data
{
	TypeValue data;
	Data<TypeValue>* Next;
	Data();
	Data(TypeValue);
	TypeValue getWarning();
	int getColumn();
	TypeValue getAt(int);
	TypeValue getGrade();
	TypeValue getCGPA();
	bool CheckSem(TypeValue);
	TypeValue getCourse();
};
template<class Type>
class LinkedList
{
	int Length;
	Data<Type>* Head;
public:
	LinkedList();

	Type getGrade(Type);
	Type CGPA_Performance(Type);
	Type Grade_Performance(Type);
	void Remove(Type);
	bool SearchGrade(Type Course);
	bool VerifyGrade(Type, Type);
	bool SearchCourse(Type, int Det = 0);
	Type GetGPA(Type);
	void Sort();
	Type getWarning(Type);
	int Element_Match(Type);
	Type Warning_Performance(Type);
	bool SearchInsert(Type, Type );
	void insert(Type);
	Type& get(int);
	bool VerifyUnique(Type);
	LinkedList<Type>* Partitioning(Type, int);
	LinkedList<Type>* Partitioning_2(Type, int);
	int getCount();
	void Remove_At_End();
	void Clear();
	void Sort_Data();
	int getColumn();
	void display();
	int getLength();
	void Replace(Type);
	LinkedList<Type>& getFeatureColumn(int);
	LinkedList<Type>& getLabelColumn();
};
template<typename Type>
void Dataset_Deallocate(LinkedList<Type>**&, int&);
template<class Type>
LinkedList<Type>& Dataset_Linked(LinkedList<Type>**&, int);
template<class Type>
void Read_File(Type Files, LinkedList<Type>**&, int&, LinkedList<Type>&);
template<class Type>
void Get_Student(Type Course, LinkedList<Type>**&, int&, int);
template<class Type>
LinkedList<Type>& preProcessing(Type& Files);
template<typename Type>
float calculateEntropyOnFeature(LinkedList<Type>&, int);
template<class Type>
void sortLabels(LinkedList<Type>&);
template<class Type>
float calculateTotalEntropy(LinkedList<Type>);
template<typename Type>
LinkedList<Type>& read_csv(Type);
template<typename T>
struct treeNode {
	T featureid;
	treeNode **next;
	int ChildCount;
	treeNode(){next = NULL;}
};
template<typename T>
void preprintTree(treeNode<T>*&, LinkedList<T>&);
template<typename T>
void postprintTree(treeNode<T>*&, LinkedList<T>&);
template<typename T>
void orderprintTree(treeNode<T>*&, LinkedList<T>&);
template<class T>
void Insert_By(treeNode<T>*&, LinkedList<T>, int, int, LinkedList<int>, LinkedList<int>);
template <typename T>
struct Tree {
	treeNode<T>* root;
	Tree()
	{
		root = NULL;
	}
	void build_tree(LinkedList<T>, int, int);
	T preOrderTraversal();
	T postOrderTraversal();
	float accuracy(LinkedList<T>);
	T inOrderTraversal();
	void getPrediction(treeNode<T>*, LinkedList<T>, int, T&);
	T predictOne(LinkedList<T>, int);
	LinkedList<T> predictAll(LinkedList<T>);
};
template<typename T>
class Forest
{
	Tree<T>* TForest;
	int NumTree;
	int stepSize;
	int WindowSize;
public:
	Forest(int, int, int);
	void build_forest(LinkedList<T>);
	void PostTraversal();
	LinkedList<T>& predictOne(LinkedList<T>, int);
	LinkedList<LinkedList<T>>& predictAll(LinkedList<T>);
	float accuracy(LinkedList<T>);

};