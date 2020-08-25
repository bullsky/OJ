
//login消息
struct login_msg
{
    long msg_id;//客户端递增
    int uid;
    long login_timestamp;//登入时间戳
};
//logout消息
struct logout_msg
{
    long msg_id;//客户端递增
    int uid;
    long logout_timestamp;//登出时间戳
};
//登陆日志条目
struct login_entry
{
    long login_timestamp;
    int uid;
};
//登陆日志，尾部追加，日志过长用快照压缩状态
login_entry loginLogs[];

//登出日志条目
struct logout_entry
{
    long logout_timestamp;
    int uid;
};
//登出日志，尾部追加，日志过长用快照压缩状态
logout_entry logoutLogs[];
//用户状态信息，map存储
struct user_status
{
    int uid;
    bool status; //在线/离线
    long status_update_timestamp;//状态更新时间戳
};

//server

long latest_msg_id;//防止过期消息
long dau_counter;//DAU计数器

//工作流程

1. 传入login_msg
2. 构造login_entry,并插入loginLogs尾部
3. 检查user_status, 如果不在线，增加dau_counter，并修改user_status。更新status_update_timestamp

性能
日志插入性能O（1），更新状态和dau_counter性能O（1）

可扩展性，单点失效
log日志和user_status的存储和水平扩展，用分布式kv存储来做，也可避免单点失效

