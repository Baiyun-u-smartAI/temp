#include <mysql.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

MYSQL *conn, mysql;
MYSQL_RES *res;
MYSQL_ROW row;

int query_state;

int main(int argc, char ** argv)
{
   const char *server=argv[1];
   const char *user="root";
   const char *password="123456";
   const char *database="test";

   mysql_init(&mysql);
   conn=mysql_real_connect(&mysql, server, user, password, database, 3306, 0, 0);
   if(conn==NULL)
   {
       cout<<mysql_error(&mysql)<<endl<<endl;
      return 1;
   }
   string instrument="delete from testtable limit 1;";
   query_state=mysql_query(conn, instrument.c_str());
   if(query_state!=0)
   {
      cout<<mysql_error(conn)<<endl<<endl;
      return 1;
   }
   cout<<endl<<endl;
   instrument.clear();
   
   instrument="INSERT INTO testtable (name,age) VALUES(\"E\",15);";
   query_state=mysql_query(conn, instrument.c_str());
   if(query_state!=0)
   {
      cout<<mysql_error(conn)<<endl<<endl;
      return 1;
   }
   cout<<endl<<endl;
    
   mysql_free_result(res);
   mysql_close(conn);

   return 0;

}