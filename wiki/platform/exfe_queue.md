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

    func NewHead(services map[string]*gobus.Client, delayInSecond int, config *model.Config) (*Head, *tomb.Tomb)

    func (i *Head) Push(meta *gobus.HTTPMeta, arg PushArg, count *int) error
        首延迟发送队列

        例子：

        > curl 'http://127.0.0.1:23334/Head10?method=Push' -d
        '{"service":"Conversation",

	"method":"Update",
	"merge_key":"email_cross123",
	"tos":[{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"}],
	"data":{"recipient":{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},"cross":{"id":123,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"title":"Test Cross","description":"test cross description","time":{"begin_at":{"date_word":"","date":"","time_word":"","time":"","timezone":""},"origin":"","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":0,"name":"","invitations":null}},"post":{"id":1,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"content":"email1 post sth","via":"abc","created_at":"2012-10-24 16:31:00"}}}'

    func (i Head) String() string

type <span id="Instant">Instant</span>

    type Instant struct {
        // contains filtered or unexported fields
    }

func <span id="NewInstant">NewInstant</span>

    func NewInstant(services map[string]*gobus.Client) *Instant

    func (i *Instant) Push(meta *gobus.HTTPMeta, arg PushArg, count *int) error
        即时发送队列

        例子：

        > curl 'http://127.0.0.1:23334/Instant?method=Push' -d
        '{"service":"Conversation",

	"method":"Update",
	"merge_key":"email_cross123",
	"tos":[{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"}],
	"data":{"recipient":{"identity_id":12,"user_id":3,"name":"email1 name","auth_data":"","timezone":"+0800","token":"recipient_email1_token","language":"en_US","provider":"email","external_id":"sender1@gmail.com","external_username":"sender1@gmail.com"},"cross":{"id":123,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"title":"Test Cross","description":"test cross description","time":{"begin_at":{"date_word":"","date":"","time_word":"","time":"","timezone":""},"origin":"","output_format":0},"place":{"id":0,"title":"","description":"","lng":"","lat":"","provider":"","external_id":""},"exfee":{"id":0,"name":"","invitations":null}},"post":{"id":1,"by_identity":{"id":11,"name":"email1 name","nickname":"email1 nick","bio":"email1 bio","timezone":"+0800","connected_user_id":1,"avatar_filename":"http://path/to/email1.avatar","provider":"email","external_id":"sender2@hotmail.com","external_username":"sender2@hotmail.com"},"content":"email1 post sth","via":"abc","created_at":"2012-10-24 16:31:00"}}}'

type <span id="PushArg">PushArg</span>

    type PushArg struct {
        Service  string            `json:"service"`
        Method   string            `json:"method"`
        MergeKey string            `json:"merge_key"`
        Tos      []model.Recipient `json:"tos"` // it will expand and overwrite "to" field in data
        Data     interface{}       `json:"data"`
    }

    func (a PushArg) FindService(services map[string]*gobus.Client) (*gobus.Client, error)

    func (a PushArg) String() string

