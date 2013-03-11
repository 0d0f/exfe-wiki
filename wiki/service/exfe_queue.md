exfe队列
=======

PACKAGE
-------

    package main
        import "queue"

TYPES
-------

type <span id="Head">Head</span>

    type Head struct {
        // contains filtered or unexported fields
    }

func <span id="NewHead">NewHead</span>

    func NewHead(delayInSecond uint, url string, config *model.Config) (*Head, *tomb.Tomb)

    func (i *Head) Push(params map[string]string, arg model.QueuePush) (int, error)
        首延迟发送队列

        例子：

        > curl 'http://127.0.0.1:23334/head10' -d '{"service":"Conversation",

	"method":"Update",
	"merge_key":"email_cross123",
	"tos":[{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"}],
	"data":{"to":{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},"cross":{"id":123,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"title":"Test Cross","description":"test cross description","time":{"begin_at":{"date_word":"","date":"","time_word":"","time":"","timezone":""},"origin":"","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":0,"name":"","invitations":null}},"post":{"id":1,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"content":"email1 post sth","via":"abc","created_at":"2012-10-24 16:31:00"}}}'

    func (i *Head) SetRoute(route gobus.RouteCreater) error

    func (i Head) String() string

type <span id="Instant">Instant</span>

    type Instant struct {
        // contains filtered or unexported fields
    }

func <span id="NewInstant">NewInstant</span>

    func NewInstant(config *model.Config) *Instant

    func (i *Instant) Push(params map[string]string, arg model.QueuePush) (int, error)
        即时发送队列

        例子：

        > curl 'http://127.0.0.1:23334/instant' -d '{"service":"Conversation",

	"method":"Update",
	"merge_key":"email_cross123",
	"tos":[{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"}],
	"data":{"to":{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},"cross":{"id":123,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"title":"Test Cross","description":"test cross description","time":{"begin_at":{"date_word":"","date":"","time_word":"","time":"","timezone":""},"origin":"","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":0,"name":"","invitations":null}},"post":{"id":1,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"content":"email1 post sth","via":"abc","created_at":"2012-10-24 16:31:00"}}}'

    func (i *Instant) SetRoute(route gobus.RouteCreater) error

type <span id="Push">Push</span>

    type Push struct {
        Service    string            `json:"service"`
        Priority   string            `json:"priority"`
        DelayType  string            `json:"delay_type"`
        GroupKey   string            `json:"group_key"`
        Recipients []model.Recipient `json:"recipients"`
        Data       interface{}       `json:"data"`
    }

    func (a Push) String() string

type <span id="Queue">Queue</span>

    type Queue struct {
        // contains filtered or unexported fields
    }

func <span id="NewQueue">NewQueue</span>

    func NewQueue(config *model.Config, redis broker.Redis) (*Queue, error)

    func (q *Queue) Push(param map[string]string, arg Push) (int, error)
        将data以delay type的合并方式，放入priority队列，之后发送给service服务。合并关键字group
        key，接收者recipients

        priority取值：

        - instant - urgent - normal

        priority也可以使用数字，表示经过多少秒后合并发送。

        例子：

        > curl 'http://127.0.0.1:23334/' -d
        '{"service":"bus://exfe_service/notifier/conversation",

	"priority": "urgent",
	"delay_type": "head",
	"group_key":"email_cross123",
	"recipients":[{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"}],
	"data":{"cross":{"id":123,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"title":"Test Cross","description":"test cross description","time":{"begin_at":{"date_word":"","date":"","time_word":"","time":"","timezone":""},"origin":"","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":0,"name":"","invitations":null}},"post":{"id":1,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"content":"email1 post sth","via":"abc","created_at":"2012-10-24 16:31:00"}}}'

    func (q *Queue) SetRoute(r gobus.RouteCreater) error

type <span id="Tail">Tail</span>

    type Tail struct {
        // contains filtered or unexported fields
    }

func <span id="NewTail">NewTail</span>

    func NewTail(delayInSecond uint, url string, config *model.Config) (*Tail, *tomb.Tomb)

    func (i *Tail) Push(params map[string]string, arg model.QueuePush) (int, error)
        尾延迟发送队列

        例子：

        > curl 'http://127.0.0.1:23334/tail10' -d '{"service":"Conversation",

	"method":"Update",
	"merge_key":"email_cross123",
	"tos":[{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"}],
	"data":{"to":{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},"cross":{"id":123,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"title":"Test Cross","description":"test cross description","time":{"begin_at":{"date_word":"","date":"","time_word":"","time":"","timezone":""},"origin":"","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":0,"name":"","invitations":null}},"post":{"id":1,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"content":"email1 post sth","via":"abc","created_at":"2012-10-24 16:31:00"}}}'

    func (i *Tail) SetRoute(route gobus.RouteCreater) error

    func (i Tail) String() string

