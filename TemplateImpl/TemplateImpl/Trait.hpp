#include <stdio.h>

template  <typename  T>
class  Result_Trait;

template <>
class  Result_Trait<int>
{
public:
	typedef  int  Res_Type;
	static  Res_Type Zero(){ return 0; };
};

template <>
class  Result_Trait<float>
{
public:
	typedef  float  Res_Type;
	static  Res_Type Zero(){ return 0.0f; };
};

template <>
class  Result_Trait<double>
{
public:
	typedef  double  Res_Type;
	static  Res_Type Zero(){ return 0.0f; };
};

template <>
class  Result_Trait<char>
{
public:
	typedef  char  Res_Type;
	static  Res_Type Zero(){ return 0; };
};






//////////////////////////////////////////////////////////////////////////