exfe服务接口
=======

PACKAGE
-------

    package main
        import "service"

CONSTANTS
-------

    const (
        POST_CREATE = "INSERT INTO `posts` (by_id, created_at, relationship, content, via, exfee_id, ref_uri) VALUES (?, ?, ?, ?, ?, ?, ?)"
        POST_FIND   = "SELECT id, by_id, created_at, relationship, content, via, exfee_id, ref_uri FROM `posts` WHERE del=0 AND exfee_id=? AND ref_uri=?"
        POST_DELETE = "UPDATE `posts` SET posts.del=1 WHERE id=? AND ref_uri=?"
    )
    const (
        SHORTTOKEN_STORE           = "INSERT INTO `shorttokens` (`key`, `resource`, `data`, `expire_at`, `created_at`) VALUES (?, ?, ?, ?, ?)"
        SHORTTOKEN_FIND            = "SELECT `key`, resource, data, expire_at FROM `shorttokens` WHERE expire_at>UTC_TIMESTAMP()"
        SHORTTOKEN_UPDATE_DATA     = "UPDATE `shorttokens` SET data=? WHERE expire_at>UTC_TIMESTAMP()"
        SHORTTOKEN_UPDATE_EXPIREAT = "UPDATE `shorttokens` SET expire_at=? WHERE expire_at>UTC_TIMESTAMP()"
    )
    const (
        CREATE                   = "INSERT INTO `tokens` VALUES (null, ?, ?, ?, ?, ?)"
        STORE                    = "UPDATE `tokens` SET expire_at=?, data=? WHERE tokens.key=? AND tokens.rand=?"
        FIND_BY_KEY              = "SELECT rand, created_at, expire_at, data FROM `tokens` WHERE tokens.key=?"
        FIND_BY_TOKEN            = "SELECT created_at, expire_at, data FROM `tokens` WHERE tokens.key=? AND tokens.rand=?"
        UPDATE_DATA_BY_TOKEN     = "UPDATE `tokens` SET tokens.data=? WHERE tokens.key=? AND tokens.rand=?"
        UPDATE_EXPIREAT_BY_TOKEN = "UPDATE `tokens` SET tokens.expire_at=? WHERE tokens.key=? AND tokens.rand=?"
        UPDATE_EXPIREAT_BY_KEY   = "UPDATE `tokens` SET tokens.expire_at=? WHERE tokens.key=?"
        DELETE_BY_TOKEN          = "DELETE FROM `tokens` WHERE tokens.key=? AND tokens.rand=?"
    )

TYPES
-------

type <span id="Conversation">Conversation</span>

    type Conversation struct {
        // contains filtered or unexported fields
    }

func <span id="NewConversation">NewConversation</span>

    func NewConversation(localTemplate *formatter.LocalTemplate, config *model.Config, sender *broker.Sender) *Conversation

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

type <span id="Conversation">Conversation</span>

    type Conversation_ struct {
        // contains filtered or unexported fields
    }

func <span id="NewConversation">NewConversation</span>

    func NewConversation_(config *model.Config, db *broker.DBMultiplexer, redis *broker.RedisMultiplexer, dispatcher *gobus.Dispatcher) (*Conversation_, error)

    func (c *Conversation_) DELETE(meta *gobus.HTTPMeta, arg string, reply *model.Post) error
        删除一条Post

        例子：

	> curl "http://panda.0d0f.com:23333/cross/100354/Conversation/11?method=DELETE" -d '""'

        返回：

	{"id":11,"by_identity":{"id":572,"name":"Googol","connected_user_id":-572,"avatar_filename":"http://api.panda.0d0f.com/v2/avatar/default?name=Googol","provider":"email","external_id":"googollee@163.com","external_username":"googollee@163.com"},"content":"@googollee@twitter blablabla","via":"web","created_at":"2010-12-27 19:52:24 +0000","relationship":[{"uri":"identity://573","relation":"mention"}],"exfee_id":110220,"ref_uri":"cross://100354"}

    func (c *Conversation_) GET(meta *gobus.HTTPMeta, arg string, reply *[]model.Post) error
        查询Posts

        例子：

	> curl "http://panda.0d0f.com:23333/cross/100354/Conversation?method=GET&clear_user=378&since=2010-12-27+19:52:24&until=2010-12-27+19:52:24&min=11&max=11" -d '""'

        返回：

	[{"id":11,"by_identity":{"id":572,"name":"Googol","connected_user_id":-572,"avatar_filename":"http://api.panda.0d0f.com/v2/avatar/default?name=Googol","provider":"email","external_id":"googollee@163.com","external_username":"googollee@163.com"},"content":"@googollee@twitter blablabla","via":"web","created_at":"2010-12-27 19:52:24 +0000","relationship":[{"uri":"identity://573","relation":"mention"}],"exfee_id":110220,"ref_uri":"cross://100354"}]

    func (c *Conversation_) POST(meta *gobus.HTTPMeta, arg model.Post, reply *model.Post) error
        发一条新的Post到cross_id

        例子：

	> curl http://panda.0d0f.com:23333/cross/100354/Conversation?via=web&created_at=1293479544 -d '{"by_identity":{"id":572},"content":"@googollee@twitter blablabla"}'

        返回：

	{"id":11,"by_identity":{"id":572,"name":"Googol","connected_user_id":-572,"avatar_filename":"http://api.panda.0d0f.com/v2/avatar/default?name=Googol","provider":"email","external_id":"googollee@163.com","external_username":"googollee@163.com"},"content":"@googollee@twitter blablabla","via":"web","created_at":"2010-12-27 19:52:24 +0000","relationship":[{"uri":"identity://573","relation":"mention"}],"exfee_id":110220,"ref_uri":"cross://100354"}

        content解析方式：

        默认：

	"@exfe@twitter look at this image http://instagr.am/xxxx\n cool!"
	 =>
	"@exfe@twitter look at this image {{url:http://instagr.am/xxxx}}\n cool!"
	relationship: [{"mention": "identity://123"}, {"url":"http://instagr.am/xxxx"}]

        特殊格式解析：

	"@exfe@twitter look at this image {{image:http://instagr.am/xxxx.jpg}}\n cool!"
	 =>
	"@exfe@twitter look at this image {{image:http://instagr.am/xxxx.jpg}}\n cool!"
	relationship: [{"mention": "identity://123"}, {"image":"http://instagr.am/xxxx.jpg"}]
	"@exfe@twitter look at this image {{webpage:http://instagr.am/xxxx}}\n cool!"
	 =>
	"@exfe@twitter look at this image {{webpage:http://instagr.am/xxxx}}\n cool!"
	relationship: [{"mention": "identity://123"}, {"webpage":"http://instagr.am/xxxx"}]

    func (c *Conversation_) Unread(meta *gobus.HTTPMeta, arg string, reply *int) error
        取得用户user_id未读的post条数

        例子：

	> curl "http://panda.0d0f.com:23333/cross/100354/user/-572/unread_count?method=Unread" -d '""'

        返回：

	1

type <span id="Cross">Cross</span>

    type Cross struct {
        // contains filtered or unexported fields
    }

func <span id="NewCross">NewCross</span>

    func NewCross(localTemplate *formatter.LocalTemplate, config *model.Config, sender *broker.Sender) *Cross

    func (c *Cross) Invite(meta *gobus.HTTPMeta, invitation model.CrossInvitation, i *int) error
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

type <span id="Iom">Iom</span>

    type Iom struct {
        // contains filtered or unexported fields
    }

func <span id="NewIom">NewIom</span>

    func NewIom(config *model.Config, redis broker.Redis) *Iom

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

type <span id="PostArg">PostArg</span>

    type PostArg struct {
        Resource           string `json:"resource"`
        Data               string `json:"data"`
        ExpireAfterSeconds int    `json:"expire_after_seconds"`
    }

type <span id="PostRepository">PostRepository</span>

    type PostRepository struct {
        // contains filtered or unexported fields
    }

func <span id="NewPostRepository">NewPostRepository</span>

    func NewPostRepository(config *model.Config, db *broker.DBMultiplexer, redis *broker.RedisMultiplexer, dispatcher *gobus.Dispatcher) (*PostRepository, error)

    func (r *PostRepository) AddUnreadCount(uri string, userID int64, count int) error

    func (r *PostRepository) DeletePost(refID string, postID uint64) error

    func (r *PostRepository) FindCross(id uint64) (model.Cross, error)

    func (r *PostRepository) FindIdentity(identity model.Identity) (model.Identity, error)

    func (r *PostRepository) FindPosts(exfeeID uint64, refURI, sinceTime, untilTime string, minID, maxID uint64) ([]convmodel.Post, error)

    func (r *PostRepository) GetUnreadCount(uri string, userID int64) (int, error)

    func (r *PostRepository) SavePost(post convmodel.Post) (uint64, error)

    func (r *PostRepository) SendUpdate(tos []model.Recipient, cross model.Cross, post model.Post) error

    func (r *PostRepository) SetUnreadCount(uri string, userID int64, count int) error

type <span id="ShortToken">ShortToken</span>

    type ShortToken struct {
        // contains filtered or unexported fields
    }

func <span id="NewShortToken">NewShortToken</span>

    func NewShortToken(config *model.Config, db *broker.DBMultiplexer) (*ShortToken, error)

    func (s *ShortToken) Expire(meta *gobus.HTTPMeta, expire int, reply *int) error
        更新resource对应的token的expire after seconds

        例子：

	> curl "http://127.0.0.1:23333/shorttoken/resource?method=Expire&resource=123" -d '13'

        返回：

	0

    func (s *ShortToken) GET(meta *gobus.HTTPMeta, arg string, reply *[]model.Token) error
        根据key或者resource获得一个token，如果token不存在，返回错误

        例子：

	> curl "http://127.0.0.1:23333/shorttoken?method=GET&key=0303&resource=123" -d '""'

        返回：

	{"key":"0303","data":"abc"}

    func (s *ShortToken) POST(meta *gobus.HTTPMeta, arg PostArg, reply *model.Token) error
        根据resource，data和expire after seconds创建一个token

        例子：

	> curl "http://127.0.0.1:23333/shorttoken" -d '{"data":"abc","resource":"123","expire_after_seconds":300}'

        返回：

	{"key":"0303","data":"abc"}

    func (s *ShortToken) PUT(meta *gobus.HTTPMeta, arg UpdateArg, reply *int) error
        更新key对应的token的data信息或者expire after seconds

        例子：

	> curl "http://127.0.0.1:23333/shorttoken/0303?method=PUT" -d '{"data":"xyz","expire_after_seconds":13}'

        返回：

	0

type <span id="ShortTokenRepository">ShortTokenRepository</span>

    type ShortTokenRepository struct {
        // contains filtered or unexported fields
    }

func <span id="NewShortTokenRepository">NewShortTokenRepository</span>

    func NewShortTokenRepository(config *model.Config, db *broker.DBMultiplexer) (*ShortTokenRepository, error)

    func (r *ShortTokenRepository) Find(key, resource string) ([]shorttoken.Token, error)

    func (r *ShortTokenRepository) Store(token shorttoken.Token) error

    func (r *ShortTokenRepository) UpdateData(key, resource, data string) error

    func (r *ShortTokenRepository) UpdateExpireAt(key, resource string, expireAt time.Time) error

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

    func (t *Thirdpart) UpdateFriends(meta *gobus.HTTPMeta, to model.ThirdpartTo, i *int) error
        同步更新to在第三方网站的好友信息

        例子：

	> curl http://127.0.0.1:23333/Thirdpart?method=UpdateFriends -d '{"external_id":"123","external_username":"name","auth_data":"","provider":"twitter","identity_id":789,"user_id":1}'

    func (t *Thirdpart) UpdateIdentity(meta *gobus.HTTPMeta, to model.ThirdpartTo, i *int) error
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

    func NewTokenManager(config *model.Config, db *broker.DBMultiplexer) (*TokenManager, error)

    func (mng *TokenManager) Expire(meta *gobus.HTTPMeta, token *string, reply *int) error
        立刻使token过期。

        例子：

	> curl http://127.0.0.1:23333/TokenManager?method=Expire -d '"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a"'
	0

    func (mng *TokenManager) ExpireAll(meta *gobus.HTTPMeta, resource *string, reply *int) error
        立刻使resource对应的所有token过期。

        例子：

	> curl http://127.0.0.1:23333/TokenManager?method=ExpireAll -d '"abc"'
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
        // contains filtered or unexported fields
    }

func <span id="NewTokenRepository">NewTokenRepository</span>

    func NewTokenRepository(config *model.Config, db *broker.DBMultiplexer) (*TokenRepository, error)

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

type <span id="UpdateArg">UpdateArg</span>

    type UpdateArg struct {
        Data               *string `json:"data"`
        ExpireAfterSeconds *int    `json:"expire_after_seconds"`
    }

type <span id="User">User</span>

    type User struct {
        // contains filtered or unexported fields
    }

func <span id="NewUser">NewUser</span>

    func NewUser(localTemplate *formatter.LocalTemplate, config *model.Config, sender *broker.Sender) *User

    func (u *User) ResetPassword(meta *gobus.HTTPMeta, verify model.UserVerify, i *int) error
        发送给用户的重置密码请求

        例子：

        > curl 'http://127.0.0.1:23333/User?method=ResetPassword' -d
        '[{"to":{"identity_id":11,"user_id":1,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"by_name":"by
        user"}]'

    func (u *User) Verify(meta *gobus.HTTPMeta, confirmation model.UserVerify, i *int) error
        发送给用户的验证请求

        例子：

        > curl 'http://127.0.0.1:23333/User?method=Verify' -d
        '[{"to":{"identity_id":11,"user_id":1,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"by_name":"by
        user"}]'

    func (u *User) Welcome(meta *gobus.HTTPMeta, welcome model.UserWelcome, i *int) error
        发送给用户的邀请

        例子：

        > curl 'http://127.0.0.1:23333/User?method=Welcome' -d
        '[{"to":{"identity_id":11,"user_id":1,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"need_verify":true}]'

