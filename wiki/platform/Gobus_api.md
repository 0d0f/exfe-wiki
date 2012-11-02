h1. Gobus 接口

h2. User 对象

对象名： user

h3. - Welcome接口

输入参数：

	type UserArg struct {
		To_identity exfe_model.Identity
		User_name   string
		Token       string
	}

h3. - Veryfy接口

输入参数：

	type UserArg struct {
		To_identity exfe_model.Identity
		User_name   string
		Token       string
		Action      string
	}

Action取值："set_password", "confirm_identiy"

h3. - GetFriends 查找好友

输入参数：

	type GetFriendsArg struct {
		ClientToken  string `json:"client_token"`
		ClientSecret string `json:"client_secret"`
		AccessToken  string `json:"access_token"`
		AccessSecret string `json:"access_secret"`
		UserID       string `json:"user_id"`
		ExternalID   string `json:"external_id"`
		Provider     string `json:"provider"`
	}