#include "stdafx.h"

template<typename T> bool isKindOf(T obj){return true;}
template<typename T> bool isKindOf(void* obj){return false;}
