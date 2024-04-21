#include <iostream>
#include <string>
using namespace std;
#include "Food.h"

Food::Food() {
	m_name = "";
	m_type = "";
}

Food::Food(string name, int type) {
	m_name = name;
	m_type = type;
}

Food::SetName(string name) {
	m_name = name;
}

Food::SetType(int type) {
	m_type = type;
}

Food::GetName() {
	return m_name;
}

Food::GetType{
	return m_type;
}