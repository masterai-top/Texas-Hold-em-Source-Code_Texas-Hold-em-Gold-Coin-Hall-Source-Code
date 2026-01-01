#ifndef __GOODSMANAGER_DEFINED__
#define __GOODSMANAGER_DEFINED__
#include <string>
#include <map>
enum Eum_Goods_Type
{
    E_DIAMOND = 10000,
    E_GOLD = 20000,
    E_CLUB_GOLD = 30000,
    E_VIP = 40000,
    E_LEAGUE_GOLD = 60000,
};

typedef struct _TGoodsManagerDetail
{
    int id;
    Eum_Goods_Type type;
    std::string name;
    std::string icon;
    std::string desc;
    bool canTransaction;
}GoodsManagerDetail;


typedef struct _TGoodsManagerList
{
    std::map<int, GoodsManagerDetail> data;
}GoodsManagerList;
#endif
