#include <stdio.h>  
#include <stdlib.h>  
#include <mysql.h>

int main (int argc, char *argv[])
 {  

    MYSQL *conn;  

    // 步骤1： 初始化连接句柄  
    conn = mysql_init(NULL);  

    if (conn == NULL) { // 如果返回NULl说明初始化失败  
        printf("mysql_init failed!\n");   
        return EXIT_FAILURE;  
    }  

    // 步骤2：实际进行连接  
    // 参数分别为，conn连接句柄，host是MySQL所在主机或地址，user用户名，password密码，database_name数据库名，后面的都是默认  
    conn = mysql_real_connect(conn, "127.0.0.1", "root", "root", "test", 0, NULL, 0);  

    if (conn) { // 连接成功  
        printf("Connection success!\n");

        // 执行插入语句
        int res = mysql_query(conn,"insert into test_table value(\"Kate\",29)");
        
        if (res){
            // 插入失败，输出错误语句
            fprintf(stderr,"insert error %d : %s",mysql_errno(conn),mysql_error(conn));
            return 1;// 结束
        }
        else {
            fprintf(stdout,"insert successfully\n");
        }

        // 删除语句
        res = mysql_query(conn,"delete from test_table limit 1");
        if (res){
            // 删除失败，输出错误语句
            fprintf(stderr,"delete error %d : %s",mysql_errno(conn),mysql_error(conn));
            return 1;// 结束
        }
        else {
            fprintf(stdout,"delete successfully\n");
        }


        // 查找语句
        res = mysql_query(conn,"SELECT * FROM test_table");
        if (res){
            // 删除失败，输出错误语句
            fprintf(stderr,"select error %d : %s",mysql_errno(conn),mysql_error(conn));
            return 1;// 结束
        }
        else {
            fprintf(stdout,"select successfully\n");
            MYSQL_RES* result=mysql_store_result(conn);
            if(mysql_num_rows(result))
            {
                MYSQL_ROW row;
                int num_fields = mysql_num_fields(result);
                while(row=mysql_fetch_row(result)) // 有多少条数据
                {
                    for (int i = 0; i<num_fields;i++ ) //一条数据有多少列
                        printf("%s\t",row[i]);
                    printf("\n");
                }
            }

        }



    } else {  
        printf("Connection failed!\n");   
    }  

    

    // 步骤3： 退出前关闭连接  
    mysql_close(conn);  

    return 0;  
}  