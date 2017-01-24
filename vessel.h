#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <cstdlib>

using namespace std;

class aircraft
{
public:
	aircraft()
		{next = NULL;}
private:
	double fuelStatus,
		repairStatus,
		ammoStatus;
	aircraft *next;
};

///==========================================================

class vessel
{
public:
	vessel()
		{next = NULL;}
	vessel(string n, int t, double r, double s)
		{
			vesselName = n;
			type = t;
			fuelStatus = 100.0;
			damageStatus = 100.0;
			ammoStatus = 100.0;
			next = NULL;

			if (type == 1)
				relative = -1.0;
			else
				relative = r;

			speed = s;
			maxSpeed = 30;
			
		}
	void setfuelStatus(double fuel)
		{fuelStatus = fuel;}

	double getFuelStatus()
		{return fuelStatus;}

	void setName(string n)
		{vesselName = n;}

	string getVesselName()
		{return vesselName;}

	void setType(int t)
		{type = t;}

	int getType()
		{return type;}

	void setDamage(double d) ///hehe
		{damageStatus = d;}

	double getDamage()
		{return damageStatus;}

	void setAmmo(double a)
		{ammoStatus = a;}

	double getAmmo()
		{return ammoStatus;}

	void setCheading(double ch)
		{carrierHeading = ch;}

	double getCheading()
		{return carrierHeading;}

	void setRheading(double rh)
		{relative = rh;}

	double getRheading()
		{return relative;}

	void setStandoff(double s)
		{standoffDist = s;}

	double getStandoff()
		{return standoffDist;}

	void setSpeed(double s)
		{speed = s;}

	double getSpeed()
		{return speed;}

	void setFrate(double fr)
		{fuelRate = fr;}

	double getFrate()
		{return fuelRate;}

	void setNext(vessel *n)
		{next = n;}

	vessel *getNext()
		{return next;}

protected:
	string vesselName;
	int type;
	double fuelStatus,
		damageStatus,
		ammoStatus,
		carrierHeading,
		relative,
		standoffDist,
		speed,
		maxSpeed,
		fuelRate;

	vessel *next;
};

///==========================================================

class destroyer: public virtual vessel
{
public:
	destroyer(string n, double r, double s)
	{
		vesselName = n;
		type = 2;
		fuelStatus = 100.0;
		damageStatus = 100.0;
		ammoStatus = 100.0;
		next = NULL;

		if (type == 1)
			relative = -1.0;
		else
			relative = r;

		speed = s;
		maxSpeed = 30;	
	}
private:
	bool LAMPSenabled;
	bool heloPresent;

};

///==========================================================

class frigate: public virtual vessel
{
public:
	frigate(string n, double r, double s)
	{
		vesselName = n;
		type = 3;
		fuelStatus = 100.0;
		damageStatus = 100.0;
		ammoStatus = 100.0;
		next = NULL;

		if (type == 1)
			relative = -1.0;
		else
			relative = r;

		speed = s;
		maxSpeed = 30;	
	}
private:
	bool LAMPSenabled;
	bool heloPresent;
	
};

///==========================================================

class carrier: public virtual vessel
{
public:
	carrier(string n, double r, double s)
	{
		vesselName = n;
		type = 1;
		fuelStatus = 100.0;
		damageStatus = 100.0;
		ammoStatus = 100.0;
		next = NULL;

		if (type == 1)
			relative = -1.0;
		else
			relative = r;

		speed = s;
		maxSpeed = 30;	
	}
private:
	int assignedAircraft;
	aircraft *squadron;
	

};

///==========================================================
