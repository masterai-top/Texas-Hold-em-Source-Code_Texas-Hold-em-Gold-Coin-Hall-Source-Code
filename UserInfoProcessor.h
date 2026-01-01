#ifndef _UserInfo_Processor_H_
#define _UserInfo_Processor_H_

//
#include <util/tc_singleton.h>
#include "UserInfoProto.h"
#include "DBAgentProto.h"
#include "DataProxyProto.h"
#include "login.pb.h"
#include "UserInfo.pb.h"
#include "Friends.pb.h"

//
using namespace tars;
using namespace std;
using namespace userinfo;


//#define MAX_NICKNAME_LEN    6   //最大昵称长度（字数）
#define MAX_NICKNAME_BYTES  18   //最大昵称长度（byte数）(1个汉字占3个byte,最多支持6个汉字)
#define MAX_SIGNATURE_LEN   40   //最大签名长度（字数）

/**
 *UserInfo请求处理类
 *
 */
class UserInfoProcessor
{
public:
    /**
     *
    */
    UserInfoProcessor();

    /**
     *
    */
    ~UserInfoProcessor();

public:
    //初始化用户信息
    tars::Int32 initUser(const userinfo::InitUserReq &req, userinfo::InitUserResp &resp);
    //USER_INFO    = 21,     //#tb_user_info
    //查询
    int selectUserInfo(long uid, UserInfo &userinfo);
    //更新
    int updateUserInfo(long uid, const map<string, string> &updateInfo, UserInfo &mUserInfo, bool bInsert = false);
   
    //USER_ACCOUNT = 20,     //#tb_user_account
    //查询
    int selectUserAccount(long uid, UserAccount &useraccount);
    //
    int updateUserAccount(long uid, const map<string, string> &updateInfo, UserAccount &mUserAccount, bool bInsert = false);
    //
    int selectSafePwdCount(long uid, int* errcount, long* lock_time);
    //
    int updateSafePwdCount(long uid);
    //
    int deleteSafePwdCount(long uid);
    //
    int authCode(long uid, const string& code);
    //处理游客绑定账户
    int BindAccount(long uid, const UserInfoProto::BindAccountReq &bindAccountReq);
    //
    int resertSafePwd(long uid, const UserInfoProto::ModifySafePwdReq &modifySafePwdReq);
    //
    int getAuthData(const std::string &username, std::string &ret, time_t &time);
    //
    int delAuthData(const std::string &username);
    //
    bool checkFriendRelation(tars::Int64 uid, tars::Int64 friend_uid, FriendsProto::Eum_Friend_Relationship_Type relationship);
    //
    int addUserRecommend(const long lUid, tars::Int64 recommend_uid, int state, UserInfoProto::RecommendBindResp &resp);
    //
    void getUserRecommend(const long lUid, vector<long>& vecUidList);
    //
    int disabledUser(const long lUid);
    //
    int listWriteOffUser(const long lUid, UserInfoProto::ListWriteOffResp &resp);
    // 检测玩家是否是代理 count就是下属代理人数
    int checkUserRecommend(const long uid, int &count);
    //
    int listUserBags(long uid, vector<UserBag> &vBags);
    //
    int getBagCountById(long lUid, long lPid);

    int updateUserBag(long lUid, long lPid, int iType, int changeCount, int &curCount);
    int setCheckSitDownTime(long lUid, string sSafePwd);

    int selectUserRemmendInfo(const long uid, string& sAndriod, string& sIos);
private:
    vector<long> writeOffList;
    bool bWriteOff;
};

//singleton
typedef TC_Singleton<UserInfoProcessor, CreateStatic, DefaultLifetime> UserInfoProcessorSingleton;

#endif

