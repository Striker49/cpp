#pragma once

class Base
{
	private:
	public:
	virtual ~Base();
	Base *generate();
	void identify(Base *p);
	void identify(Base &p);
};