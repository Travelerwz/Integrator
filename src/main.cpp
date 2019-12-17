#include "Cmysql.h"
#include "Credis.h"
#include "Cjson.h"
#include "CBase64.h"
#include <memory.h>
#include <future>
#include <string>
#include "Cmd5.h"
#include "CMysqlPool.h"
#include "MutexLockGuard.h"
using namespace Intergrator;
int main()
{
    // mutex mt;
    // shared_ptr<MutexLockGuard>ptrmt = make_shared<MutexLockGuard>(mt);
    // string sql = "select * from test";
    // shared_ptr<CMysqlPool>csql = make_shared<CMysqlPool>(10);
    // csql->CreatePool("127.0.0.1","root","666666","test");
    // CMysql* msql = csql->getConnect();
    // msql->Query(sql);
    // csql->FreeConnect(msql);
    // csql->getConnect()->Query(sql);

    // shared_ptr<CMysql>csql = make_shared<CMysql>();
    // csql->Connect("127.0.0.1","root","666666","test");
    // 
    // csql->Query(sql);
    // string str = csql->Query_json(sql);
    //cout<<"str:"<<str<<endl;
    // string result = csql->Query(sql,"1");
    // cout<<"result:"<<result<<endl;
    // shared_ptr<Credis>crds = make_shared<Credis>();
    // crds->Command_jsonset(str,sql);
    // std::string com = "set foo 1234";
    // crds->Command_set(com);
    // std::string res = crds->Command_get("get foo");
    // std::cout<<"res:"<<res<<std::endl;
    // crds->Command_set("www","hello");
    // crds->Command_del("www");
    // shared_ptr<Cjson>cjs = make_shared<Cjson>();
    // //cjs->Output();
    // std::string res = cjs->Combination("www","wwz");
    // cout<<"res:"<<res<<endl;
    // shared_ptr<CMD5>md = make_shared<CMD5>(); 
    // md->Make_Md5(sql);
    // shared_ptr<CBase64>bs = make_shared<CBase64>(); 
    // cout<<bs->Base64_encode(sql)<<endl;
    // string str2 = "cdjn\nndjc\nd";
    // cout<<bs->Replace_All(str2)<<endl;
    return 0;
}