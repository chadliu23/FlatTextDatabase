#include "FlatTextDatabase.h"
#include <fstream>
#include <sstream>

using namespace std;

FlatTextDatabase* FlatTextDatabase::m_instance = NULL;

pthread_mutex_t FlatTextDatabase::m_mutex;

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

FlatTextDatabase::FlatTextDatabase()
	: m_isOpen(false)
{

}

FlatTextDatabase* FlatTextDatabase::getInstance()
{
	if(m_instance == NULL)
	{
		pthread_mutex_init(&m_mutex, NULL);
		pthread_mutex_lock(&m_mutex);
		m_instance = new FlatTextDatabase();
		pthread_mutex_unlock(&m_mutex);
	}
	return m_instance;
}

void FlatTextDatabase::releaseDatabase()
{
	if(m_instance != NULL)
	{
		delete m_instance;
		m_instance = NULL;
	}
}

void FlatTextDatabase::readRecord(const std::string& filename)
{
	m_filename = filename;
	string line;
  	ifstream myfile (m_filename);
	if (myfile.is_open())
	{
	    while ( getline (myfile,line) )
	    {
	      vector<string> splited = split(line, ',');
	      if(splited.size() < 3)
	      {
	      	continue;
	      }
	      order o;
	      o.orderID = atol(splited[0].c_str());
	      memcpy(o.owner,splited[1].c_str(),splited[1].size());
	      o.amount = atol(splited[2].c_str());
	      m_data.push_back(o);
	    }
	    myfile.close();
	}
	m_isOpen = true;

}
vector<order> FlatTextDatabase::searchDatabaseByOrderID(long orderID)
{
	vector<order> result;
	for(unsigned i = 0; i < m_data.size(); ++i)
	{
		if(m_data[i].orderID == orderID)
		{
			result.push_back(m_data[i]);
		}

	}
	return result;
}
bool FlatTextDatabase::insertNewRecord(order*  o)
{
	if(!m_isOpen)
	{
		return false;
	}
	m_data.push_back(*o);
	ofstream myfile;
  	myfile.open (m_filename, ios::app);
  	myfile << o->orderID <<"," << o->owner <<"," <<o->amount <<endl;
  	myfile.close();

	return true;
}