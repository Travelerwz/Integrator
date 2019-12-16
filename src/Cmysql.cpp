#include "Cmysql.h"

CMysql::CMysql()
{
    if(NULL == mysql_init(&mysql))
    {
        cout<<"mysql_init is error"<<endl;
        exit(-1);
    }
}
CMysql::~CMysql()
{
    mysql_close(&mysql);
}

bool CMysql::Connect(string host,string user,string passwd,string database)
{
    if(!mysql_real_connect(&mysql,host.c_str(),user.c_str(),passwd.c_str(),database.c_str(),0,NULL,0))
    {
        perror("mysql_real_connect");
        return false;
    }
    cout<<"connect is ok"<<endl;
    return true;
} 

bool CMysql::Del(string sql)
{
    if(!mysql_query(&mysql,sql.c_str()))
    {
        return false;
    }
    return true;
}

bool CMysql::Query(string sql)
{
    if(mysql_query(&mysql,sql.c_str()))
    {
        perror("mysql_query");
        return false;
    }
    MYSQL_RES *result= mysql_store_result(&mysql);
    int row = mysql_num_rows(result);
    int colum = mysql_num_fields(result);
    MYSQL_ROW rrow;
    MYSQL_FIELD *COL;
    for(int j=0;j<colum;j++)
    {
        COL = mysql_fetch_field(result);
        string res = COL->name;
        cout<<"res:"<<res<<endl;
        root[res.c_str()] = "hello";
        cout<<"col:"<<COL->name<<endl;
    }
    

    for(int i=0;i < row;i++)
    {
        rrow = mysql_fetch_row(result);

        for(int j=0;j<colum;j++)
        {
            printf("%10s ",rrow[j]);
        }
        printf("\n");
    }
    cout<<""<<endl;
    mysql_free_result(result);
    return true;
}


string CMysql::Query_json(string sql)
{
    string str;
    if(mysql_query(&mysql,sql.c_str()))
    {
        perror("mysql_query");
        return NULL;
    }
    MYSQL_RES *result= mysql_store_result(&mysql);
    int row = mysql_num_rows(result);
    int colum = mysql_num_fields(result);
    MYSQL_ROW rrow;
    string col2,row2;
    MYSQL_FIELD *COL;
    //rrow = mysql_fetch_row(result);
    COL = mysql_fetch_field(result);
    for(int i=1;i<row+1;i++)
    {
        rrow = mysql_fetch_row(result);
        for(int j=0;j<colum;j++)
        {
            emlue[COL[j].name] = rrow[j];
        }
        array.append(emlue);
    }
    root["result"] = Json::Value(array);
    str = fast_wariter.write(root);
    mysql_free_result(result);
    return str;
}
