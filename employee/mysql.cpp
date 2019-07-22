#include <stdlib.h>
#include <iostream>
#include<string.h>
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;
int main(void)
{
string name,add,em;
int cont;
cout << endl;
cout << "...'Welcome to Registration'..." << endl;

try {
  sql::Driver *driver;
  sql::Connection *con;
 sql::PreparedStatement  *prep_stmt;  
sql::Statement *show_stmt;
//sql::PreparedStatement *ps;  
sql ::ResultSet *res;
  /* Create a connection */
  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
  /* Connect to the MySQL test database */
  con->setSchema("project");

 prep_stmt = con->prepareStatement("INSERT INTO employee(name, address,email,contact) VALUES (?, ?, ?, ?)");

	cout<<"Enter Your Name";
	cin>>name;
	cout<<"Enter Your Address";
	cin>>add;
	cout<<"Enter your Email";
	cin>>em;
	cout<<"Enter Your Contact number";
	cin>>cont;
prep_stmt->setString(1,name);

prep_stmt->setString(2,add);
prep_stmt->setString(3,em);
prep_stmt->setInt(4,cont);
prep_stmt->executeQuery();
show_stmt = con->createStatement();

res = show_stmt->executeQuery("SELECT * FROM employee;");

while(res->next()){
cout<<res->getString(1)<<"\t"<<res->getString(2)<<"\t"<<res->getString(3)<<"\t"<<res->getInt(4)<<endl;
}


   

      //cout << res-> getString("username")<<"\t"<<res->getString("password") << endl;
  
  
  delete prep_stmt;
  delete con;

} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line "<< __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

cout << endl;

return 0;
}
