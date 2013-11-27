#ifndef FLATTEXTDATABASE_H
#define FLATTEXTDATABASE_H
#include <pthread.h>
#include <vector>
#include <string>

struct order{
	long orderID;
	char owner[32];
	long amount;
};


class FlatTextDatabase
{
public:
	static FlatTextDatabase* getInstance();
	static void releaseDatabase();
	void readRecord(const std::string& filename);
	std::vector<order> searchDatabaseByOrderID(long orderID);
	bool insertNewRecord(order*  o);
	bool isOpen(){return m_isOpen;}
    std::vector<order> getData() {return m_data;}
private:
	FlatTextDatabase();
	static pthread_mutex_t m_mutex;
	static FlatTextDatabase* m_instance;
	bool m_isOpen;
	std::string m_filename;
	std::vector<order> m_data;

};

#endif