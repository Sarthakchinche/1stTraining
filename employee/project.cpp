#include <stdlib.h>
#include <iostream>
#include <cppconn/prepared_statement.h>

#include </usr/include/mysql_connection.h>
#include </usr/include/cppconn/driver.h>
#include </usr/include/cppconn/exception.h>
#include </usr/include/cppconn/resultset.h>
#include </usr/include/cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;
class REGISTER
{ 
public:
  sql::Driver *driver;
  sql::Connection *con;
  sql::PreparedStatement *ps;
  sql::ResultSet *res;
  sql::Statement *show_st;

public:
 int id, salary, no;
 string dname,name,email ,designation,pass;

void INSERT()
{
try{

  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
  con->setSchema("EmployeeManagement");
}
catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  
}

 
 ps = con->prepareStatement("INSERT INTO employee(emp_id,emp_name,dep_name,email_id,emp_salary,cont_no,designation,password) VALUES (?,?,?,?,?,?,?,?)");

cout<<"Enter id of your Employee"<<endl;
cin>>id;
ps->setInt(1, id);

cout<<"Enter name of your Employee"<<endl;
cin>>name;
ps->setString(2, name);

cout<<"Enter Department name of your Employee"<<endl;
cin>>dname;
ps->setString(3, dname);

cout<<"Enter Email id of your Employee"<<endl;
cin>>email;
ps->setString(4, email);

cout<<"Enter salary of your Employee"<<endl;
cin>>salary;
ps->setInt(5, salary);

cout<<"Enter Contact no. of your Employee"<<endl;
cin>>no;
ps->setInt(6, no);

cout<<"Enter Designation of your Employee"<<endl;
cin>>designation;
ps->setString(7, designation);

cout<<"Enter Password"<<endl;
cin>>pass;
ps->setString(8, pass);

 ps->executeUpdate();

 cout<<"Record Inserted Successfully"<<endl; 
delete ps;
  delete con;
  delete show_st;

}
};
class login: public REGISTER
{
public:
void SHOW()
{
try{

  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
  con->setSchema("EmployeeManagement");
}
catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  
}

	int ID;
	cout<<"Enter id of your Employee";
	cin>>ID;

	ps=con->prepareStatement("SELECT * FROM employee where emp_id=(?)");
	//res = show_st->executeQuery("SELECT * FROM employee where emp_id=(?)");
	ps->setInt(1,ID);
	res=ps->executeQuery();
	if(res->next()){
cout<<res->getString(1)<<"\t"<<res->getString(2)<<"\t"<<res->getString(3)<<"\t"<<res->getInt(4)<<"\t"<<res->getInt(5)<<"\t"<<res->getInt(6)<<"\t"<<res->getInt(7)<<endl;

 delete ps;
  delete con;
  delete show_st;
}

}
void Valid(){
try{

  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
  con->setSchema("EmployeeManagement");
}
catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  
}

int ID,ID1,lo,ch,AID;
string PASS,PASS1,APASS;
login e;
cout<<"To Login as Admin press 1"<<endl;
cout<<"To Login as Employee press 2"<<endl;
cin>>lo;
switch(lo){
	case 1:
	cout<<"Hello Admin"<<endl;
	cout<<"Enter your id"<<endl;
	cin>>AID;
	cout<<"Enter your Password";
	cin>>APASS;
	if(AID==1400 && APASS=="cisadmin@123"){
cout<<"Welcome To EMPLOYEE MANAGEMENT SYSTEM"<<endl;
cout<<"Select 1 to DELETE record"<<endl;
cout<<"Select 2 to UPDATE record"<<endl;
cout<<"Select 3 to SEE record"<<endl;
cout<<"Select 4 to Register new Employee"<<endl;
cin>>ch;
switch(ch)
{
case 1:
   e.DELETE();
   break;
case 2:
   e.UPDATE();
   break;
case 3:
   e.SHOW();
   break;
   case 4:
   INSERT();
   break;
default:
    e.exit();
}
	}
	break;
case 2:
cout<<"Hello Employee"<<endl;
cout<<"Enter your id";
cin>>ID;
cout<<"Enter your Password";
cin>>PASS;
int ch,ch1;

ps = con->prepareStatement("select * from employee where emp_id = (?);");
ps->setInt(1, ID); 
res= ps->executeQuery();
while(res->next()){
	ID1=res->getInt("emp_id");
	PASS1=res->getString("password");
}
if(ID==ID1 && PASS==PASS1)
{
	ps = con->prepareStatement("select * from employee where emp_id = (?);");
	ps->setInt(1,ID);
	res=ps->executeQuery();
	if(res->next()){
cout<<res->getString(1)<<"\t"<<res->getString(2)<<"\t"<<res->getString(3)<<"\t"<<res->getInt(4)<<"\t"<<res->getInt(5)<<"\t"<<res->getInt(6)<<"\t"<<res->getInt(7)<<endl;

}

}
else
{
cout<<"No Record found"<<endl;
cout<<"...Please contact your Admin...";

}
break;
default:e.exit();
delete ps;
  delete con;
  delete show_st;

}}
public:
void DELETE()
{
try{

  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
  con->setSchema("EmployeeManagement");
}
catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  
}

cout<< "Enter id of a record to delete ";
cin>>id;
ps = con->prepareStatement("delete from employee where emp_id= (?)");
 
ps->setInt(1,id);
 ps->executeUpdate();

 cout<<"record deleted"<<endl; 

delete ps;
  delete con;
  delete show_st;
} 
void UPDATE()
{
try{

  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
  con->setSchema("EmployeeManagement");
}
catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  
}

   cout<<"Enter id of record to update";
   cin>>id;

   cout<<"Enter new department name";
   cin>>dname;
   
   cout<<"Enter new email id";
   cin>>email;
   
   cout<<"Enter new contact no.";
   cin>>no;
   
   cout<<"Enter new salary";
   cin>>salary;
    
   cout<<"Enter new designation";
   cin>>designation;
   try{
   cout<<"Enter new password";
   cin>>pass;  
   ps = con->prepareStatement("update employee set dep_name=(?), email_id=(?),cont_no=(?),emp_salary=(?),designation=(?),password=(?) where emp_id = (?);");

   ps->setString(1,dname);
   ps->setString(2,email);
   ps->setInt(3, no);
   ps->setInt(4, salary);
   ps->setString(5, designation);
   ps->setString(6,pass);
   ps->setInt(7, id);
 ps->executeUpdate();}
catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  
}
 cout<<"record updated successfully"<<endl; 

delete ps;
  delete con;
  delete show_st;
}
int exit()
{
return 0;

} 
};
 

                                                
int main()
{
	login log;
	log.Valid();

return 0;
}
