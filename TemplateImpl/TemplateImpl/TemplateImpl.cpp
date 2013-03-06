// TemplateImpl.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "boost\\scoped_ptr.hpp"

//////////////////////////////////////////////////////////////////////////

#include "Trait.hpp"

class  sInfo 
{
public:
	int  ID;
	float  fPercent;
	sInfo(int a, float b):ID(a),fPercent(b)
	{
		std::cout<<"��ʼ��sInfo"<<std::endl;
	};
	sInfo():ID(0),fPercent(0)
	{
		std::cout<<"��ʼ��sInfo"<<std::endl;
	};
	sInfo & operator +(const sInfo & a)
	{
		std::cout<<"�ӷ�����"<<std::endl;
		sInfo  *Temp=new sInfo;
		Temp->ID = ID + a.ID;
		Temp->fPercent=fPercent+a.fPercent;
		return  *Temp;
	};
	sInfo & operator +=(const sInfo & a)
	{
		std::cout<<"+=����"<<std::endl;
		ID += a.ID;
		fPercent += a.fPercent;
		return  *this;
	};
};

template <>
class Result_Trait<sInfo>
{
public:
	typedef  sInfo  Res_Type;
	static  Res_Type Zero(){ return sInfo(); };
};

template < typename T /*, typename Traits=Result_Trait<T>*/ >
//��Ͳ���
class  Add_Policy
{
public:
	/*typedef  typename Traits::Res_Type  Type;*/
	static  T  AddType(T & a1, const T & a2)
	{
		a1 += a2;
		return  a1;
	};
};


template < typename T, typename Policy=Add_Policy<T>, typename Traits=Result_Trait<T> >
class  Mathimatic
{
public:
	typedef  typename Traits::Res_Type  Type;
		
	static  Type   Add(T a1, T a2 )
	{ 	
		typedef  typename Policy  Poly;
		return  Poly::AddType(a1,a2);
	};
};

class  CVirtualPure
{
public:
	virtual  void  func1()=0;
	virtual  void  func2()=0;
};

class  CVirtualBase:CVirtualPure
{
public:
	virtual  void  func1()
	{ 
		std::cout<<"CVirtualBase�ຯ��func1()"<<std::endl;
		return;
	};
	virtual  void  func2()
	{ 
		std::cout<<"CVirtualBase�ຯ��func2()"<<std::endl;
		return;
	};
};

template <typename  T>
class  CEnumTest 
{
public:
	enum  { YES=0, NO=1 };
};

//�ػ�ʶ��ĳ���ض�����������
template <>
class CEnumTest<int> 
{
public:
	enum  {YES=1,NO=0};
};




int _tmain(int argc, _TCHAR* argv[])
{
	sInfo  a(12,0.8f),b(8,0.2f);

	std::cout<<Mathimatic<sInfo>::Add(a,b).ID<<std::endl;

	CVirtualPure * ptr = NULL ;

	CVirtualBase  * pptr = new CVirtualBase;

	ptr = (CVirtualPure *)pptr;

	ptr->func1();

	if (CEnumTest<sInfo>::YES)
	{
		std::cout<<"��������Ҫ��"<<std::endl;
	}

	std::system("pause");
	return 0;
}

