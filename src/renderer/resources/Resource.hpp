#pragma once
#include <iostream>

class Resource
{
protected:
	std::size_t m_id{ 0 };
	std::string m_filepath;
	bool m_isLoad{ false };

	virtual void setup() {};
public:
	virtual ~Resource() {};
	virtual bool load(const char* filename) = 0;
	virtual void unload() = 0;

	bool isLoaded() const { return m_isLoad; }
	std::size_t getID() const { return m_id; }
	std::string getFilepath() const { return m_filepath; }
};