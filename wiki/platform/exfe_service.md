exfe服务接口
=======

PACKAGE
-------

    package main
        import "service"

CONSTANTS
-------

    const (
        CREATE                   = "INSERT INTO `%%table%%` VALUES (null, ?, ?, ?, ?, ?)"
        STORE                    = "UPDATE `%%table%%` SET expire_at=?, data=? WHERE %%table%%.key=? AND %%table%%.rand=?"
        FIND_BY_KEY              = "SELECT rand, created_at, expire_at, data FROM `%%table%%` WHERE %%table%%.key=?"
        FIND_BY_TOKEN            = "SELECT created_at, expire_at, data FROM `%%table%%` WHERE %%table%%.key=? AND %%table%%.rand=?"
        UPDATE_DATA_BY_TOKEN     = "UPDATE `%%table%%` SET %%table%%.data=? WHERE %%table%%.key=? AND %%table%%.rand=?"
        UPDATE_EXPIREAT_BY_TOKEN = "UPDATE `%%table%%` SET %%table%%.expire_at=? WHERE %%table%%.key=? AND %%table%%.rand=?"
        UPDATE_EXPIREAT_BY_KEY   = "UPDATE `%%table%%` SET %%table%%.expire_at=? WHERE %%table%%.key=?"
        DELETE_BY_TOKEN          = "DELETE FROM `%%table%%` WHERE %%table%%.key=? AND %%table%%.rand=?"
    )

TYPES
-------

type <span id="Conversation">Conversation</span>

    type Conversation struct {
        // contains filtered or unexported fields
    }

func <span id="NewConversation">NewConversation</span>

    func NewConversation(localTemplate *formatter.LocalTemplate, config *model.Config) *Conversation

    func (c *Conversation) Update(meta *gobus.HTTPMeta, updates model.ConversationUpdates, i *int) error
        发送Conversation的更新消息updates

        例子：

        > curl 'http://127.0.0.1:23333/Conversation?method=Update' -d
        '[{"to":{"identity_id":33,"user_id":3,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},"cross":{"id":123,"by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},"title":"Test
        Cross","description":"test cross
        description","time":{"begin_at":{"date_word":"","date":"","time_word":"","time":"","timezone":""},"origin":"","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":0,"name":"","invitations":null}},"post":{"id":1,"by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},"content":"email1
        post sth","via":"abc","created_at":"2012-10-24
        16:31:00"}},{"to":{"identity_id":33,"user_id":3,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},"cross":{"id":123,"by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},"title":"Test
        Cross","description":"test cross
        description","time":{"begin_at":{"date_word":"","date":"","time_word":"","time":"","timezone":""},"origin":"","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":0,"name":"","invitations":null}},"post":{"id":2,"by_identity":{"id":22,"name":"twitter3
        name","nickname":"twitter3 nick","bio":"twitter3
        bio","timezone":"+0800","connected_user_id":3,"avatar_filename":"http://path/to/twitter3.avatar","provider":"twitter","external_id":"twitter3@domain.com","external_username":"twitter3@domain.com"},"content":"twitter3
        post sth","via":"abc","created_at":"2012-10-24 16:40:00"}}]'

type <span id="Cross">Cross</span>

    type Cross struct {
        // contains filtered or unexported fields
    }

func <span id="NewCross">NewCross</span>

    func NewCross(localTemplate *formatter.LocalTemplate, config *model.Config) *Cross

    func (c *Cross) Invite(meta *gobus.HTTPMeta, invitations model.CrossInvitations, i *int) error
        发送Cross的邀请消息invitations

        例子：

        > curl 'http://127.0.0.1:23333/Cross?method=Invite' -d
        '[{"to":{"identity_id":11,"user_id":1,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"cross":{"id":123,"by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"title":"Test
        Cross","description":"test cross
        description","time":{"begin_at":{"date_word":"","date":"2012-10-23","time_word":"","time":"08:45:00","timezone":"+0800"},"origin":"2012-10-23
        16:45:00","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":123,"name":"","invitations":[{"id":11,"host":true,"mates":2,"identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"rsvp_status":"NORESPONSE","by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"via":""},{"id":22,"host":false,"mates":0,"identity":{"id":12,"name":"email2
        name","nickname":"email2 nick","bio":"email2
        bio","timezone":"+0800","connected_user_id":2,"avatar_filename":"http://path/to/email2.avatar","provider":"email","external_id":"email2@domain.com","external_username":"email2@domain.com"},"rsvp_status":"NORESPONSE","by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"via":""},{"id":33,"host":false,"mates":0,"identity":{"id":22,"name":"twitter3
        name","nickname":"twitter3 nick","bio":"twitter3
        bio","timezone":"+0800","connected_user_id":3,"avatar_filename":"http://path/to/twitter3.avatar","provider":"twitter","external_id":"twitter3@domain.com","external_username":"twitter3@domain.com"},"rsvp_status":"NORESPONSE","by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"via":""},{"id":44,"host":false,"mates":0,"identity":{"id":32,"name":"facebook4
        name","nickname":"facebook4 nick","bio":"facebook4
        bio","timezone":"+0800","connected_user_id":4,"avatar_filename":"http://path/to/facebook4.avatar","provider":"facebook","external_id":"facebook4@domain.com","external_username":"facebook4@domain.com"},"rsvp_status":"NORESPONSE","by_identity":{"id":22,"name":"twitter3
        name","nickname":"twitter3 nick","bio":"twitter3
        bio","timezone":"+0800","connected_user_id":3,"avatar_filename":"http://path/to/twitter3.avatar","provider":"twitter","external_id":"twitter3@domain.com","external_username":"twitter3@domain.com"},"via":""}]}}}]'

    func (c *Cross) Summary(meta *gobus.HTTPMeta, updates model.CrossUpdates, i *int) error
        发送Cross的更新汇总消息updates

        例子：

        > curl 'http://127.0.0.1:23333/Cross?method=Summary' -d
        '[{"to":{"identity_id":11,"user_id":1,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"old_cross":{"id":123,"by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"title":"Test
        Cross","description":"test cross
        description","time":{"begin_at":{"date_word":"","date":"","time_word":"","time":"","timezone":"+0800"},"origin":"","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":123,"name":"","invitations":[{"id":11,"host":true,"mates":2,"identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"rsvp_status":"NORESPONSE","by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"via":""},{"id":22,"host":false,"mates":0,"identity":{"id":12,"name":"email2
        name","nickname":"email2 nick","bio":"email2
        bio","timezone":"+0800","connected_user_id":2,"avatar_filename":"http://path/to/email2.avatar","provider":"email","external_id":"email2@domain.com","external_username":"email2@domain.com"},"rsvp_status":"NORESPONSE","by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"via":""},{"id":33,"host":false,"mates":0,"identity":{"id":22,"name":"twitter3
        name","nickname":"twitter3 nick","bio":"twitter3
        bio","timezone":"+0800","connected_user_id":3,"avatar_filename":"http://path/to/twitter3.avatar","provider":"twitter","external_id":"twitter3@domain.com","external_username":"twitter3@domain.com"},"rsvp_status":"NORESPONSE","by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"via":""},{"id":44,"host":false,"mates":0,"identity":{"id":32,"name":"facebook4
        name","nickname":"facebook4 nick","bio":"facebook4
        bio","timezone":"+0800","connected_user_id":4,"avatar_filename":"http://path/to/facebook4.avatar","provider":"facebook","external_id":"facebook4@domain.com","external_username":"facebook4@domain.com"},"rsvp_status":"ACCEPTED","by_identity":{"id":22,"name":"twitter3
        name","nickname":"twitter3 nick","bio":"twitter3
        bio","timezone":"+0800","connected_user_id":3,"avatar_filename":"http://path/to/twitter3.avatar","provider":"twitter","external_id":"twitter3@domain.com","external_username":"twitter3@domain.com"},"via":""},{"id":77,"host":false,"mates":0,"identity":{"id":34,"name":"facebook6
        name","nickname":"facebook6 nick","bio":"facebook6
        bio","timezone":"+0800","connected_user_id":6,"avatar_filename":"http://path/to/facebook6.avatar","provider":"facebook","external_id":"facebook6@domain.com","external_username":"facebook6@domain.com"},"rsvp_status":"NORESPONSE","by_identity":{"id":32,"name":"facebook4
        name","nickname":"facebook4 nick","bio":"facebook4
        bio","timezone":"+0800","connected_user_id":4,"avatar_filename":"http://path/to/facebook4.avatar","provider":"facebook","external_id":"facebook4@domain.com","external_username":"facebook4@domain.com"},"via":""}]}},"cross":{"id":123,"by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"title":"Test
        Cross","description":"test cross
        description","time":{"begin_at":{"date_word":"","date":"","time_word":"","time":"","timezone":"+0800"},"origin":"","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":123,"name":"","invitations":[{"id":22,"host":false,"mates":0,"identity":{"id":12,"name":"email2
        name","nickname":"email2 nick","bio":"email2
        bio","timezone":"+0800","connected_user_id":2,"avatar_filename":"http://path/to/email2.avatar","provider":"email","external_id":"email2@domain.com","external_username":"email2@domain.com"},"rsvp_status":"ACCEPTED","by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"via":""},{"id":33,"host":false,"mates":0,"identity":{"id":22,"name":"twitter3
        name","nickname":"twitter3 nick","bio":"twitter3
        bio","timezone":"+0800","connected_user_id":3,"avatar_filename":"http://path/to/twitter3.avatar","provider":"twitter","external_id":"twitter3@domain.com","external_username":"twitter3@domain.com"},"rsvp_status":"DECLINED","by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"via":""},{"id":44,"host":false,"mates":0,"identity":{"id":32,"name":"facebook4
        name","nickname":"facebook4 nick","bio":"facebook4
        bio","timezone":"+0800","connected_user_id":4,"avatar_filename":"http://path/to/facebook4.avatar","provider":"facebook","external_id":"facebook4@domain.com","external_username":"facebook4@domain.com"},"rsvp_status":"ACCEPTED","by_identity":{"id":22,"name":"twitter3
        name","nickname":"twitter3 nick","bio":"twitter3
        bio","timezone":"+0800","connected_user_id":3,"avatar_filename":"http://path/to/twitter3.avatar","provider":"twitter","external_id":"twitter3@domain.com","external_username":"twitter3@domain.com"},"via":""},{"id":55,"host":true,"mates":2,"identity":{"id":21,"name":"twitter1
        name","nickname":"twitter1 nick","bio":"twitter1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/twitter1.avatar","provider":"twitter","external_id":"twitter1@domain.com","external_username":"twitter1@domain.com"},"rsvp_status":"NORESPONSE","by_identity":{"id":11,"name":"email1
        name","nickname":"email1 nick","bio":"email1
        bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"via":""},{"id":66,"host":false,"mates":2,"identity":{"id":33,"name":"facebook5
        name","nickname":"facebook5 nick","bio":"facebook5
        bio","timezone":"+0800","connected_user_id":5,"avatar_filename":"http://path/to/facebook5.avatar","provider":"facebook","external_id":"facebook5@domain.com","external_username":"facebook5@domain.com"},"rsvp_status":"ACCEPTED","by_identity":{"id":32,"name":"facebook4
        name","nickname":"facebook4 nick","bio":"facebook4
        bio","timezone":"+0800","connected_user_id":4,"avatar_filename":"http://path/to/facebook4.avatar","provider":"facebook","external_id":"facebook4@domain.com","external_username":"facebook4@domain.com"},"via":""}]}},"by":{"id":32,"name":"facebook4
        name","nickname":"facebook4 nick","bio":"facebook4
        bio","timezone":"+0800","connected_user_id":4,"avatar_filename":"http://path/to/facebook4.avatar","provider":"facebook","external_id":"facebook4@domain.com","external_username":"facebook4@domain.com"}}]'

type <span id="DBRepository">DBRepository</span>

    type DBRepository struct {
        Config *model.Config
        // contains filtered or unexported fields
    }

    func (r *DBRepository) Connect() error

    func (r *DBRepository) Exec(sql string, v ...interface{}) (sql.Result, error)

    func (r *DBRepository) Query(sql string, v ...interface{}) (*sql.Rows, error)

type <span id="Iom">Iom</span>

    type Iom struct {
        // contains filtered or unexported fields
    }

func <span id="NewIom">NewIom</span>

    func NewIom(config *model.Config, redis *godis.Client) *Iom

    func (iom *Iom) GET(meta *gobus.HTTPMeta, arg *IomGetArg, reply *string) (err error)
        获取用户user_id名下的hash对应的资源。

        例子：

	> curl http://127.0.0.1:23333/Iom?method=GET -d '{"user_id":"124","hash":"aa"}'
	"abc"

    func (iom *Iom) POST(meta *gobus.HTTPMeta, arg *IomPostArg, reply *string) (err error)
        将资源data存入用户user_id名下，并返回对应的hash。如果资源data已经在user_id名下，则直接返回对应的hash。hash不区分大小写。

        例子：

	> curl http://127.0.0.1:23333/Iom?method=POST -d '{"user_id":"124","data":"abc"}'
	"AA"

type <span id="IomGetArg">IomGetArg</span>

    type IomGetArg struct {
        UserID string `json:"user_id"`
        Hash   string `json:"hash"`
    }

type <span id="IomPostArg">IomPostArg</span>

    type IomPostArg struct {
        UserID string `json:"user_id"`
        Data   string `json:"data"`
    }

type <span id="Thirdpart">Thirdpart</span>

    type Thirdpart struct {
        // contains filtered or unexported fields
    }

func <span id="NewThirdpart">NewThirdpart</span>

    func NewThirdpart(config *model.Config) (*Thirdpart, error)

    func (t *Thirdpart) Send(meta *gobus.HTTPMeta, arg model.ThirdpartSend, id *string) error
        发信息给to，如果是私人信息，就发送private的内容，如果是公开信息，就发送public的内容。info内是相关的应用信息。

        例子：

	> curl http://127.0.0.1:23333/Thirdpart?method=Send -d '{"to":{"external_id":"123","external_username":"name","auth_data":"","provider":"twitter","identity_id":789,"user_id":1},"private":"private","public":"public","info":null}'

    func (t *Thirdpart) UpdateFriends(meta *gobus.HTTPMeta, to *model.Recipient, i *int) error
        同步更新to在第三方网站的好友信息

        例子：

	> curl http://127.0.0.1:23333/Thirdpart?method=UpdateFriends -d '{"external_id":"123","external_username":"name","auth_data":"","provider":"twitter","identity_id":789,"user_id":1}'

    func (t *Thirdpart) UpdateIdentity(meta *gobus.HTTPMeta, to *model.Recipient, i *int) error
        同步更新to在第三方网站的个人信息（头像，bio之类）

        例子：

	> curl http://127.0.0.1:23333/Thirdpart?method=UpdateIdentity -d '{"external_id":"123","external_username":"name","auth_data":"","provider":"twitter","identity_id":789,"user_id":1}'

type <span id="TokenGenerateArgs">TokenGenerateArgs</span>

    type TokenGenerateArgs struct {
        Resource           string `json:"resource"`
        Data               string `json:"data"`
        ExpireAfterSeconds int    `json:"expire_after_seconds"`
    }

type <span id="TokenManager">TokenManager</span>

    type TokenManager struct {
        // contains filtered or unexported fields
    }

func <span id="NewTokenManager">NewTokenManager</span>

    func NewTokenManager(config *model.Config) (*TokenManager, error)

    func (mng *TokenManager) Delete(meta *gobus.HTTPMeta, token *string, reply *int) error
        删除token，如果成功返回0

        例子：

	> curl http://127.0.0.1:23333/TokenManager?method=Delete -d '"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a"'
	0

    func (mng *TokenManager) Expire(meta *gobus.HTTPMeta, token *string, reply *int) error
        立刻使token过期。

        例子：

	> curl http://127.0.0.1:23333/TokenManager?method=Expire -d '"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a"'
	0

    func (mng *TokenManager) ExpireAll(meta *gobus.HTTPMeta, key *string, reply *int) error
        立刻使key对应的所有token过期。

        例子：

	> curl http://127.0.0.1:23333/TokenManager?method=ExpireAll -d '"ab56b4d92b40713acc5af89985d4b786"'
	0

    func (mng *TokenManager) Find(meta *gobus.HTTPMeta, resource *string, reply *[]*tokenmanager.Token) error
        根据resource，查找对应的所有Token对象

        例子：

	> curl http://127.0.0.1:23333/TokenManager?method=Find -d '"abcde"'
	[{"token":"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a","data":"","is_expire":true},{"token":"ab56b4d92b40713acc5af89985d4b786aa354d0a4f80c96c85c728e67a73b795","data":"","is_expire":true}]

    func (mng *TokenManager) Generate(meta *gobus.HTTPMeta, arg *TokenGenerateArgs, reply *string) error
        根据资源resource，数据data和过期时间expire_after_seconds生成一个token。如果expire_after_seconds是-1，则此token无过期时间

        例子：

	> curl http://127.0.0.1:23333/TokenManager?method=Generate -d '{"resource":"abcde","data":"","expire_after_seconds":12}'
	"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a"

    func (mng *TokenManager) Get(meta *gobus.HTTPMeta, token *string, reply *tokenmanager.Token) error
        根据token返回Token对象

        例子：

	> curl http://127.0.0.1:23333/TokenManager?method=Get -d '"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a"'
	{"token":"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a","data":"","is_expire":true}

    func (mng *TokenManager) Refresh(meta *gobus.HTTPMeta, args *TokenRefreshArg, reply *int) error
        将token的过期时间设为expire_after_seconds秒之后过期。如果expire_after_seconds为-1，则token永不过期。

        例子：

	> curl http://127.0.0.1:23333/TokenManager?method=Refresh -d '{"token":"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a","expire_after_seconds":-1}'
	0

    func (mng *TokenManager) Update(meta *gobus.HTTPMeta, arg *TokenUpdateArg, reply *int) error
        更新token对应的数据data

        例子：

        > curl http://127.0.0.1:23333/TokenManager?method=Update -d
        '{"token":"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a","data":"123"}'
        0

    func (mng *TokenManager) Verify(meta *gobus.HTTPMeta, args *TokenVerifyArg, reply *TokenVerifyReply) error
        根据token和资源resource来验证两者是否一致matched，并返回Token对象

        例子：

	> curl http://127.0.0.1:23333/TokenManager?method=Verify -d '{"token":"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a","resource":"abcde"}'
	{"matched":true,{"token":"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a","data":"","is_expire":true}}

type <span id="TokenRefreshArg">TokenRefreshArg</span>

    type TokenRefreshArg struct {
        Token              string `json:"token"`
        ExpireAfterSeconds int    `json:"expire_after_seconds"`
    }

type <span id="TokenRepository">TokenRepository</span>

    type TokenRepository struct {
        DBRepository
        // contains filtered or unexported fields
    }

func <span id="NewTokenRepository">NewTokenRepository</span>

    func NewTokenRepository(config *model.Config) (*TokenRepository, error)

    func (r *TokenRepository) Create(token *tokenmanager.Token) error

    func (r *TokenRepository) DeleteByToken(key, rand string) error

    func (r *TokenRepository) FindByKey(key string) ([]*tokenmanager.Token, error)

    func (r *TokenRepository) FindByToken(key, rand string) (*tokenmanager.Token, error)

    func (r *TokenRepository) Store(token *tokenmanager.Token) error

    func (r *TokenRepository) UpdateDataByToken(key, rand, data string) error

    func (r *TokenRepository) UpdateExpireAtByKey(key string, expireAt *time.Time) error

    func (r *TokenRepository) UpdateExpireAtByToken(key, rand string, expireAt *time.Time) error

type <span id="TokenUpdateArg">TokenUpdateArg</span>

    type TokenUpdateArg struct {
        Token string `json:"token"`
        Data  string `json:"data"`
    }

type <span id="TokenVerifyArg">TokenVerifyArg</span>

    type TokenVerifyArg struct {
        Token    string `json:"token"`
        Resource string `json:"resource"`
    }

type <span id="TokenVerifyReply">TokenVerifyReply</span>

    type TokenVerifyReply struct {
        Matched bool                `json:"matched"`
        Token   *tokenmanager.Token `json:"token,omitempty"`
    }

type <span id="User">User</span>

    type User struct {
        // contains filtered or unexported fields
    }

func <span id="NewUser">NewUser</span>

    func NewUser(localTemplate *formatter.LocalTemplate, config *model.Config) *User

    func (u *User) Confirm(meta *gobus.HTTPMeta, confirmations model.UserConfirms, i *int) error
        发送给用户的确认请求

        例子：

        > curl 'http://127.0.0.1:23333/User?method=Confirm' -d
        '[{"to":{"identity_id":11,"user_id":1,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"by":{"id":12,"name":"email2
        name","nickname":"email2 nick","bio":"email2
        bio","timezone":"+0800","connected_user_id":2,"avatar_filename":"http://path/to/email2.avatar","provider":"email","external_id":"email2@domain.com","external_username":"email2@domain.com"}}]'

    func (u *User) ResetPassword(meta *gobus.HTTPMeta, tos model.ThirdpartTos, i *int) error
        发送给用户的重置密码请求

        例子：

        > curl 'http://127.0.0.1:23333/User?method=ResetPassword' -d
        '[{"to":{"identity_id":11,"user_id":1,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"}}]'

    func (u *User) Welcome(meta *gobus.HTTPMeta, welcomes model.UserWelcomes, i *int) error
        发送给用户的邀请

        例子：

        > curl 'http://127.0.0.1:23333/User?method=Welcome' -d
        '[{"to":{"identity_id":11,"user_id":1,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"need_verify":true}]'

