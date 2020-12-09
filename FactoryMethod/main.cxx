/*
 * main.cxx
 * 
 * Copyright 2020  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>

using namespace std;
#define DELETEOBJECT(x) if(x != nullptr) { delete x; x = nullptr;}
class Fruit
{
public:
	Fruit(){}
	virtual ~Fruit(){}
	virtual void FruitType() = 0;
};

class Apple:public Fruit
{
public:
	Apple(){}
	virtual ~Apple() override
	{
	}
	virtual void FruitType() override
	{
		cout << "I am en apple" << endl;
	}
};

class BaseFactory
{
public:
	BaseFactory(){}
	virtual ~BaseFactory()
	{
		DELETEOBJECT(m_fruit);
	}
	virtual Fruit * Produce() = 0;
protected:
	Fruit *m_fruit;
};

class AppleFactory: public BaseFactory
{
public:
	AppleFactory(){}
	virtual ~AppleFactory() override {}
	virtual Fruit * Produce() override
	{
		m_fruit = new Apple();
		return m_fruit;
	}
};

int main(int argc, char **argv)
{
	BaseFactory *tmpFactory = new AppleFactory();
	tmpFactory->Produce()->FruitType();
	return 0;
}

