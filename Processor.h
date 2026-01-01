#ifndef _Processor_H_
#define _Processor_H_

//
#include <util/tc_singleton.h>
#include "HallProto.h"
#include "HallServant.h"
#include "GameRecordProto.h"
#include "GoodsManagerProto.h"
#include "DataProxyProto.h"
#include "MailProto.h"
#include "mail.pb.h"
#include "mall.pb.h"
//
using namespace tars;
using namespace hall;
using namespace dbagent;
/**
 *请求处理类
 *
 */
class Processor
{
public:
    /**
     *
    */
    Processor();

    /**
     *
    */
    ~Processor();

public:
    int readDataFromDB(long uid, const string& table_name, const std::vector<string>& col_name, const map<string, string>& whlist, const string& order_col, int limit_num,  dbagent::TDBReadRsp &dataRsp);

    int writeDataFromDB(dbagent::Eum_Query_Type dBOPType, long uid, const string& table_name, const std::map<string, string>& col_info, const map<string, string>& whlist);

    int delDataFromDB(long uid, const string& table_name, const map<string, string>& whlist);

    int getUserScratchNum(long lUin, int propID);
    //增加刮刮卡
    int addUserScratch(long lUin, int propID, int count, bool isFree, int channel);

    //goods
    int addGoods(long lUin, int goodsID, long count);
    int selectGoods(long lUin, GoodsManager::GetGoodsListRsp &resp);
    int selectAllGoods(long lUin, GoodsManager::GetGoodsListRsp &resp);
    int selectAGoods(const GoodsManager::GetAGoodsCountReq &req, GoodsManager::GetAGoodsCountRsp &resp);
    int selectTypeGoods(const GoodsManager::GetTypeGoodsCountReq &req, GoodsManager::GetTypeGoodsCountRsp &resp);
    int updateGoods(long lUin, int goodsID, long count);

    //红点
    int addRedDot(long uid, int type);
    int removeRedDot(long uid, int type);
    int getRedDotList(long uid, std::vector<int> &reddotlist);

    // 系统弹框
    int selectSysFrame(const long uId, hall::SysFrameResp &resp);
    int delSysFrame(const long uId);

    int queryMessages(const long lUid, const MailProto::TQueryMessageReq &req, MailProto::TQueryMessageResp& resp);

    int dealMessages(const long messageId, const int iStatus);

    int updateMessages(const long lUid, const map<string, string>& updateData, const map<string, string>& whlData);

    int insertMessage(const mail::MessageReq &req);
    //
    int getMallExchange(const string& props_id, const double discount, userinfo::ModifyUserWealthReq& modifyUserWealthReq);
    //
    int getMallMenu(const int menu_type, const int goods_id, mallProto::GetMenuResp& resp);
    //
    long selectSysTranferByPropsID(const int iPropsID);
    //
    int updateSysTranferByPropsID(const int iPropsID, const long iCount);

private:
    //产生uuid串
    string generateUUIDStr();
};

//singleton
typedef TC_Singleton<Processor, CreateStatic, DefaultLifetime> ProcessorSingleton;

#endif

