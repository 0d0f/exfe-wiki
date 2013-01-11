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

type <span id="CreateArg">CreateArg</span>

    type CreateArg struct {
        Data               string `json:"data"`
        Resource           string `json:"resource"`
        ExpireAfterSeconds int    `json:"expire_after_seconds"`
    }

type <span id="Iom">Iom</span>

    type Iom struct {
        // contains filtered or unexported fields
    }

func <span id="NewIom">NewIom</span>

    func NewIom(config *model.Config, redis broker.Redis) *Iom

    func (iom *Iom) Create(params map[string]string, data string) (string, error)
        将资源data存入用户user_id名下，并返回对应的hash。如果资源data已经在user_id名下，则直接返回对应的hash。hash不区分大小写。

        例子：

	> curl http://127.0.0.1:23333/iom/user/124 -d '"abc"'
	"AA"

    func (iom *Iom) Get(params map[string]string) (string, error)
        获取用户user_id名下的hash对应的资源。

        例子：

	> curl http://127.0.0.1:23333/iom/124/aa -d '{"user_id":"124","hash":"aa"}'
	"abc"

    func (iom *Iom) SetRoute(route gobus.RouteCreater) error

type <span id="IomPostArg">IomPostArg</span>

    type IomPostArg struct {
        UserID string `json:"user_id"`
        Data   string `json:"data"`
    }

type <span id="Message">Message</span>

    type Message struct {
        // contains filtered or unexported fields
    }

func <span id="NewMessage">NewMessage</span>

    func NewMessage(config *model.Config, dispatcher *gobus.Dispatcher) (*Message, error)

    func (m *Message) Send(params map[string]string, arg model.Message) (int, error)
        通过Message发送一条消息arg

        例子：

        > curl 'http://127.0.0.1:23333/message' -d
        '{"service":"bus://exfe_service/conversation",

	"ticket":"email_cross123",
	"recipients":[{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"}],
	"data":{"cross":{"id":123,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"title":"Test Cross","description":"test cross description","time":{"begin_at":{"date_word":"","date":"","time_word":"","time":"","timezone":""},"origin":"","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":0,"name":"","invitations":null}},"post":{"id":1,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"content":"email1 post sth","via":"abc","created_at":"2012-10-24 16:31:00"}}}'

    func (m *Message) SetRoute(r gobus.RouteCreater) error

type <span id="Notifier">Notifier</span>

    type Notifier struct {
        // contains filtered or unexported fields
    }

func <span id="NewNotifier">NewNotifier</span>

    func NewNotifier(local *formatter.LocalTemplate, config *model.Config, sender *broker.Sender) *Notifier

    func (n *Notifier) CrossInvite(params map[string]string, invitation model.CrossInvitation) (int, error)
        发送Cross的邀请消息invitations

        例子：

        > curl 'http://127.0.0.1:23333/cross/invitation' -d
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

    func (n *Notifier) CrossSummary(params map[string]string, updates model.CrossUpdates) (int, error)
        发送Cross的更新汇总消息updates

        例子：

        > curl 'http://127.0.0.1:23333/cross/summary' -d
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

    func (n *Notifier) PostUpdate(params map[string]string, updates model.ConversationUpdates) (int, error)
        发送Conversation的更新消息updates

        例子：

        > curl 'http://127.0.0.1:23333/conversation' -d
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

    func (n *Notifier) SetRoute(r gobus.RouteCreater) error

    func (n *Notifier) UserPassword(params map[string]string, verify model.UserVerify) (int, error)
        发送给用户的重置密码请求

        例子：

        > curl 'http://127.0.0.1:23333/User?method=ResetPassword' -d
        '[{"to":{"identity_id":11,"user_id":1,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"by_name":"by
        user"}]'

    func (n *Notifier) UserVerify(params map[string]string, confirmation model.UserVerify) (int, error)
        发送给用户的验证请求

        例子：

        > curl 'http://127.0.0.1:23333/user/verify' -d
        '[{"to":{"identity_id":11,"user_id":1,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"by_name":"by
        user"}]'

    func (n *Notifier) UserWelcome(params map[string]string, welcome model.UserWelcome) (int, error)
        发送给用户的邀请

        例子：

        > curl 'http://127.0.0.1:23333/user/welcome' -d
        '[{"to":{"identity_id":11,"user_id":1,"name":"email1
        name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"email1@domain.com","external_username":"email1@domain.com"},"need_verify":true}]'

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

    func (s *ShortToken) Create(params map[string]string, arg CreateArg) (model.Token, error)
        根据resource，data和expire after seconds创建一个token

        例子：

	> curl "http://127.0.0.1:23333/shorttoken" -d '{"data":"abc","resource":"123","expire_after_seconds":300}'

        返回：

	{"key":"0303","data":"abc"}

    func (s *ShortToken) Get(params map[string]string) ([]model.Token, error)
        根据key或者resource获得一个token，如果token不存在，返回错误

        例子：

	> curl "http://127.0.0.1:23333/shorttoken?key=0303&resource=123"

        返回：

	[{"key":"0303","data":"abc"}]

    func (s *ShortToken) SetRoute(route gobus.RouteCreater) error

    func (s *ShortToken) Update(params map[string]string, arg UpdateArg) (int, error)
        更新key对应的token的data信息或者expire after seconds

        例子：

	> curl "http://127.0.0.1:23333/shorttoken/0303" -d '{"data":"xyz","expire_after_seconds":13}'

        返回：

	0

    func (s *ShortToken) UpdateResource(params map[string]string, expire int) (int, error)
        更新resource对应的token的data信息或者expire after seconds

        例子：

	> curl "http://127.0.0.1:23333/shorttoken/resource?resouce=123" -d '13'

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

    func (t *Thirdpart) Send(params map[string]string, arg model.ThirdpartSend) (string, error)
        发信息给to，如果是私人信息，就发送private的内容，如果是公开信息，就发送public的内容。info内是相关的应用信息。

        例子：

	> curl http://127.0.0.1:23333/thirdpart/message -d '{"to":{"external_id":"123","external_username":"name","auth_data":"","provider":"twitter","identity_id":789,"user_id":1},"private":"private","public":"public","info":null}'

    func (t *Thirdpart) SetRoute(route gobus.RouteCreater) error

    func (t *Thirdpart) UpdateFriends(params map[string]string, to model.ThirdpartTo) (int, error)
        同步更新to在第三方网站的好友信息

        例子：

	> curl http://127.0.0.1:23333/thirdpart/friends -d '{"external_id":"123","external_username":"name","auth_data":"","provider":"twitter","identity_id":789,"user_id":1}'

    func (t *Thirdpart) UpdateIdentity(params map[string]string, to model.ThirdpartTo) (int, error)
        同步更新to在第三方网站的个人信息（头像，bio之类）

        例子：

	> curl http://127.0.0.1:23333/thirdpart/identity -d '{"external_id":"123","external_username":"name","auth_data":"","provider":"twitter","identity_id":789,"user_id":1}'

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

    func (mng *TokenManager) Expire(params map[string]string) (int, error)
        立刻使token过期。

        例子：

	> curl http://127.0.0.1:23333/tokenmanager/token/ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a/expire
	0

    func (mng *TokenManager) ExpireAll(params map[string]string, resource string) (int, error)
        立刻使resource对应的所有token过期。

        例子：

	> curl http://127.0.0.1:23333/tokenmanager/resource/expire -d '"abc"'
	0

    func (mng *TokenManager) Expire_(params map[string]string, token string) (int, error)

    func (mng *TokenManager) Generate(params map[string]string, arg TokenGenerateArgs) (string, error)
        根据资源resource，数据data和过期时间expire_after_seconds生成一个token。如果expire_after_seconds是-1，则此token无过期时间

        例子：

	> curl http://127.0.0.1:23333/tokenmanager -d '{"resource":"abcde","data":"","expire_after_seconds":12}'
	"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a"

    func (mng *TokenManager) Get(params map[string]string) (*tokenmanager.Token, error)
        根据token返回Token对象

        例子：

	> curl http://127.0.0.1:23333/tokenmanager/token/ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a
	{"token":"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a","data":"","is_expire":true}

    func (mng *TokenManager) Get_(params map[string]string, token string) (*tokenmanager.Token, error)

    func (mng *TokenManager) Refresh(params map[string]string, expireAfterSeconds int) (int, error)
        将token的过期时间设为expire_after_seconds秒之后过期。如果expire_after_seconds为-1，则token永不过期。

        例子：

	> curl http://127.0.0.1:23333/tokenmanager/token/ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a/refresh -d '-1'
	0

    func (mng *TokenManager) Refresh_(params map[string]string, arg TokenRefreshArg) (int, error)

    func (mng *TokenManager) ResourceFind(params map[string]string, resource string) ([]*tokenmanager.Token, error)
        根据resource，查找对应的所有Token对象

        例子：

	> curl http://127.0.0.1:23333/tokenmanager/resource -d '"abcde"'
	[{"token":"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a","data":"","is_expire":true},{"token":"ab56b4d92b40713acc5af89985d4b786aa354d0a4f80c96c85c728e67a73b795","data":"","is_expire":true}]

    func (mng *TokenManager) SetRoute(r gobus.RouteCreater) error

    func (mng *TokenManager) Update(params map[string]string, data string) (int, error)
        更新token对应的数据data

        例子：

        > curl
        http://127.0.0.1:23333/tokenmanager/token/ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a
        -d '"123"' 0

    func (mng *TokenManager) Update_(params map[string]string, arg TokenUpdateArg) (int, error)

    func (mng *TokenManager) Verify(params map[string]string, resource string) (TokenVerifyReply, error)
        根据token和资源resource来验证两者是否一致matched，并返回Token对象

        例子：

	> curl http://127.0.0.1:23333/tokenmanager/token/ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a/verify -d '"abcde"'
	{"matched":true,{"token":"ab56b4d92b40713acc5af89985d4b786c027b1ee301059618fb364abafd43f4a","data":"","is_expire":true}}

    func (mng *TokenManager) Verify_(params map[string]string, arg TokenVerifyArg) (TokenVerifyReply, error)

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

