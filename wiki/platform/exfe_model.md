exfe接口对象模型
=======

PACKAGE
-------

    package model
        import "model"

CONSTANTS
-------

    const (
        HourInSeconds   int = 1 * 60 * 60 /*seconds*/
        MinuteInSeconds int = 1 * 60      /*seconds*/
    )

FUNCTIONS
-------

func <span id="LoadLocation">LoadLocation</span>

    func LoadLocation(zone string) (*time.Location, error)

TYPES
-------

type <span id="Config">Config</span>

    type Config struct {
        SiteUrl      string `json:"site_url"`
        SiteApi      string `json:"site_api"`
        SiteImg      string `json:"site_img"`
        AppUrl       string `json:"app_url"`
        TemplatePath string `json:"template_path"`
        DefaultLang  string `json:"default_lang"`

        DB struct {
            Addr     string `json:"addr"`
            Port     int    `json:"port"`
            Username string `json:"username"`
            Password string `json:"password"`
            DbName   string `json:"db_name"`
        } `json:"db"`
        Redis struct {
            Netaddr  string `json:"netaddr"`
            Db       int    `json:"db"`
            Password string `json:"password"`
        } `json:"redis"`
        Email struct {
            Host     string `json:"host"`
            Port     int    `json:"port"`
            Username string `json:"username"`
            Password string `json:"password"`
            Name     string `json:"name"`
            Domain   string `json:"domain"`
        } `json:"email"`

        ExfeService struct {
            Addr string `json:"addr"`
            Port int    `json:"port"`
        } `json:"exfe_service"`
        ExfeQueue struct {
            Addr string         `json:"addr"`
            Port int            `json:"port"`
            Head map[string]int `json:"head"`
        } `json:"exfe_queue"`

        TokenManager struct {
            TableName string `json:"table_name"`
        } `json:"token_manager"`
        Thirdpart struct {
            Twitter struct {
                ClientToken  string `json:"client_token"`
                ClientSecret string `json:"client_secret"`
                AccessToken  string `json:"access_token"`
                AccessSecret string `json:"access_secret"`
                ScreenName   string `json:"screen_name"`
            } `json:"twitter"`
            Apn struct {
                Cert             string `json:"cert"`
                Key              string `json:"key"`
                Server           string `json:"server"`
                RootCA           string `json:"rootca"`
                TimeoutInMinutes uint   `json:"timeout_in_minutes"`
            } `json:"apn"`
            Gcm struct {
                Key string `json:"key"`
            } `json:"gcm"`
        } `json:"thirdpart"`

        Log *logger.Logger `json:"-"`
    }

type <span id="ConversationUpdate">ConversationUpdate</span>

    type ConversationUpdate struct {
        To    Recipient `json:"to"`
        Cross Cross     `json:"cross"`
        Post  Post      `json:"post"`
    }

type <span id="ConversationUpdates">ConversationUpdates</span>

    type ConversationUpdates []ConversationUpdate

    func (u ConversationUpdates) String() string

type <span id="Cross">Cross</span>

    type Cross struct {
        ID          uint64    `json:"id"`
        By          Identity  `json:"by_identity"`
        Title       string    `json:"title"`
        Description string    `json:"description"`
        Time        CrossTime `json:"time"`
        Place       Place     `json:"place"`
        Exfee       Exfee     `json:"exfee"`
    }

    func (c Cross) Equal(other *Cross) bool

    func (c Cross) String() string

type <span id="CrossInvitation">CrossInvitation</span>

    type CrossInvitation struct {
        To    Recipient `json:"to"`
        Cross Cross     `json:"cross"`

        Config *Config `json:"-"`
    }

    func (a CrossInvitation) IsCreator() bool

    func (a CrossInvitation) Link() string

    func (a CrossInvitation) ListInvitations() string

    func (a CrossInvitation) LongDescription() bool

    func (a *CrossInvitation) Parse(config *Config) (err error)

    func (a CrossInvitation) String() string

    func (a CrossInvitation) Timezone() string

    func (a CrossInvitation) ToIn(invitations []Invitation) bool

type <span id="CrossInvitations">CrossInvitations</span>

    type CrossInvitations []CrossInvitation

    func (c CrossInvitations) String() string

type <span id="CrossTime">CrossTime</span>

    type CrossTime struct {
        BeginAt      EFTime       `json:"begin_at"`
        Origin       string       `json:"origin"`
        OutputFormat OutputFormat `json:"output_format"`
    }

    func (t CrossTime) StringInZone(targetZone string) (string, error)

type <span id="CrossUpdate">CrossUpdate</span>

    type CrossUpdate struct {
        To       Recipient `json:"to"`
        OldCross Cross     `json:"old_cross"`
        Cross    Cross     `json:"cross"`
        By       Identity  `json:"by"`
    }

type <span id="CrossUpdates">CrossUpdates</span>

    type CrossUpdates []CrossUpdate

    func (u CrossUpdates) String() string

type <span id="DataType">DataType</span>

    type DataType string

    const (
        TypeCrossInvitation DataType = "i"
        TypeCrossUpdate              = "u"
        TypeCrossRemove              = "r"
        TypeConversation             = "c"
    )

    func (t DataType) String() string

type <span id="EFTime">EFTime</span>

    type EFTime struct {
        DateWord string `json:"date_word"`
        Date     string `json:"date"`
        TimeWord string `json:"time_word"`
        Time     string `json:"time"`
        Timezone string `json:"timezone"`
    }

    func (t EFTime) StringInZone(targetZone string, targetLoc *time.Location) (string, error)

    func (t EFTime) UTCTime(layout string) (string, error)

type <span id="Exfee">Exfee</span>

    type Exfee struct {
        ID          uint64       `json:"id"`
        Name        string       `json:"name"`
        Invitations []Invitation `json:"invitations"`

        Accepted   []Invitation `json:"-"`
        Declined   []Invitation `json:"-"`
        Interested []Invitation `json:"-"`
        Pending    []Invitation `json:"-"`
    }

    func (e Exfee) CountPeople(invitations []Invitation) int

    func (e Exfee) Equal(other *Exfee) bool

    func (e *Exfee) Parse()

type <span id="Identity">Identity</span>

    type Identity struct {
        ID       uint64 `json:"id,omitempty"`
        Name     string `json:"name,omitempty"`
        Nickname string `json:"nickname,omitempty"`
        Bio      string `json:"bio,omitempty"`
        Timezone string `json:"timezone,omitempty"`
        UserID   int64  `json:"connected_user_id,omitempty"`
        Avatar   string `json:"avatar_filename,omitempty"`

        Provider         string `json:"provider,omitempty"`
        ExternalID       string `json:"external_id,omitempty"`
        ExternalUsername string `json:"external_username,omitempty"`
        OAuthToken       string `json:"oauth_token,omitempty"`
    }

    func (i Identity) Equal(other Identity) bool

    func (i Identity) SameUser(other Identity) bool

    func (i Identity) String() string

type <span id="InfoData">InfoData</span>

    type InfoData struct {
        CrossID uint64   `json:"cross_id"`
        Type    DataType `json:"type"`
    }

    func (i InfoData) String() string

type <span id="Invitation">Invitation</span>

    type Invitation struct {
        ID         uint64   `json:"id"`
        Host       bool     `json:"host"`
        Mates      uint64   `json:"mates"`
        Identity   Identity `json:"identity"`
        RsvpStatus RsvpType `json:"rsvp_status"`
        By         Identity `json:"by_identity"`
        Via        string   `json:"via"`
    }

    func (i *Invitation) IsAccepted() bool

    func (i *Invitation) String() string

type <span id="OutputFormat">OutputFormat</span>

    type OutputFormat uint

    const (
        TimeFormat OutputFormat = 0
        TimeOrigin              = 1
    )

type <span id="Place">Place</span>

    type Place struct {
        ID          uint64 `json:"id"`
        Title       string `json:"title"`
        Description string `json:"description"`
        Lng         string `json:"lng"`
        Lat         string `json:"lat"`
        Provider    string `json:"provider"`
        ExternalID  string `json:"external_id"`
    }

    func (p *Place) Same(other *Place) bool

    func (p *Place) String() string

type <span id="Post">Post</span>

    type Post struct {
        ID        uint64   `json:"id"`
        By        Identity `json:"by_identity"`
        Content   string   `json:"content"`
        Via       string   `json:"via"`
        CreatedAt string   `json:"created_at"`
    }

    func (p *Post) CreatedAtInZone(timezone string) (string, error)

type <span id="QueuePush">QueuePush</span>

    type QueuePush struct {
        Service  string      `json:"service"`
        Method   string      `json:"method"`
        MergeKey string      `json:"merge_key"`
        Tos      []Recipient `json:"tos"` // it will expand and overwrite "to" field in data
        Data     interface{} `json:"data"`
    }

    func (a QueuePush) String() string

type <span id="Recipient">Recipient</span>

    type Recipient struct {
        IdentityID       uint64 `json:"identity_id"`
        UserID           int64  `json:"user_id"`
        Name             string `json:"name"`
        AuthData         string `json:"auth_data"`
        Timezone         string `json:"timezone"`
        Token            string `json:"token"`
        Language         string `json:"language"`
        Provider         string `json:"provider"`
        ExternalID       string `json:"external_id"`
        ExternalUsername string `json:"external_username"`
    }

    func (r Recipient) Equal(other *Recipient) bool

    func (r Recipient) ID() string

    func (r Recipient) SameUser(other *Identity) bool

    func (r Recipient) String() string

type <span id="RsvpType">RsvpType</span>

    type RsvpType string

    const (
        RsvpNoresponse   RsvpType = "NORESPONSE"
        RsvpAccepted              = "ACCEPTED"
        RsvpInterested            = "INTERESTED"
        RsvpDeclined              = "DECLINED"
        RsvpRemoved               = "REMOVED"
        RsvpNotification          = "NOTIFICATION"
    )

type <span id="ThirdpartSend">ThirdpartSend</span>

    type ThirdpartSend struct {
        To             Recipient `json:"to"`
        PrivateMessage string    `json:"private"`
        PublicMessage  string    `json:"public"`
        Info           *InfoData `json:"info"`

        Config *Config `json:"-"`
    }

    func (a ThirdpartSend) String() string

type <span id="ThirdpartTo">ThirdpartTo</span>

    type ThirdpartTo struct {
        To Recipient `json:"to"`

        Config *Config `json:"-"`
    }

    func (a ThirdpartTo) Link() string

    func (a *ThirdpartTo) Parse(config *Config) (err error)

    func (a ThirdpartTo) String() string

    func (a ThirdpartTo) ToIn(invitations []Invitation) bool

    func (a ThirdpartTo) ToRecipient() Recipient

type <span id="ThirdpartTos">ThirdpartTos</span>

    type ThirdpartTos []ThirdpartTo

    func (t ThirdpartTos) String() string

type <span id="UserConfirm">UserConfirm</span>

    type UserConfirm struct {
        To Recipient `json:"to"`
        By Identity  `json:"by"`

        Config *Config `json:"-"`
    }

    func (c UserConfirm) Link() string

    func (a UserConfirm) NeedShowBy() bool

    func (c *UserConfirm) Parse(config *Config) (err error)

    func (c UserConfirm) String() string

type <span id="UserConfirms">UserConfirms</span>

    type UserConfirms []UserConfirm

    func (u UserConfirms) String() string

type <span id="UserWelcome">UserWelcome</span>

    type UserWelcome struct {
        To         Recipient `json:"to"`
        NeedVerify bool      `json:"need_verify"`

        Config *Config `json:"-"`
    }

    func (w UserWelcome) Link() string

    func (w *UserWelcome) Parse(config *Config) (err error)

    func (w UserWelcome) String() string

type <span id="UserWelcomes">UserWelcomes</span>

    type UserWelcomes []UserWelcome

    func (w UserWelcomes) String() string

