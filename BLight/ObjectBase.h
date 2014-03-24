#pragma once
#include "stdafx.h"
#include <utility>
#include <map>
#include "CustomPoint.h"
#include "CustomPolygon.h"
#include "CustomShape.h"

using namespace std;

class ObjectBase
{
public:
	ObjectBase(void);
	ObjectBase(int, string);
	~ObjectBase(void);

	static int count;

	operator string();
	
	int getId(){return id;}
	void setId(int val){id = val;}

	string getName(){return name;}
	void setName(string val){name = val;}
		
	// Ph
	void setShape(CustomShape*);
	CustomShape* getShape();

	void setDensity(float);
	void setFriction(float);
	void setRestitution(float);

	CustomPoint& getPosition();
	float getRotation();
	
	void applyForce(const CustomPoint&);
	void applyLinearImpulse(const CustomPoint&);
	void setLinearDamping(float);
	void setLinearVelocity(const CustomPoint&);

	void setSensor(bool);

	CustomPoint& getGlobalCenter();
	bool contains(const CustomPoint&);
	// end Ph

	int* getEnergyProp(){return &energy;}
	int getEnergy(){return energy;}
	void setEnergy(int val){energy = val;}

protected:
	void init(int, string);
	
	int id;
	string name;
	
	int energy;

	CustomPoint position;
	CustomPoint globalCenter;

	CustomShape* shape;
};

