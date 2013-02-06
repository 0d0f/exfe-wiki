h1. Api document

采用4sq的api矩阵方式组织本api文档。

其中 Objects为基本对象，General为基本操作，Aspects为基本对象钻取之后获得的其他对象，也可以理解为对象关系。Actions为其他动作，目前只有少数对象有。

h2. Overview

[[Api_response|Response]]

h2. API

|Objects	|General	|Aspects	|Actions|
|[[object_user|user]]   |[[signin]]
[[signout]]
[[GetRegistrationFlag]]
[[ForgotPassword]]
[[SetupUserByInvitationToken]]
[[update]]
[[regDevice]]|[[api_user_crosses|crosses]]
[[crosslist]]
                         exfee  
                         identity |[[addIdentity]]
[[deleteIdentity]]
[[setPassword]]
[[mergeIdentities]]
[[sortIdentities]]|
|[[object_identity|identity]] | [[get]]
[[complete]]
[[update / public]] |     | |
|[[api_cross|cross]] | [[api_cross_add|gather]]
              [[api_cross_edit|edit]]
              [[api_cross_update|updated]]
[[GetCrossByInvitationToken]]
[[GetInvitationByToken]]  |exfee|                      |
|[[object_exfee|exfee]] | [[edit]]
[[rsvp]]  | conversation |             |
|[[object_conversation|conversation]] | [[api_add_conversation|add]]         
                                     [[api_del_post|del]]  | |             |
|[[Place]] | [[api_get_place|get]]  |        | |   
|Background | [[getAvailableBackgrounds]]  |        | |   




----------------------------------------------------
Extra APIs:

[[Avatar API]]
----------------------------------------------------
Private APIs:

[[For Gobus]]
----------------------------------------------------
Verify / Set Password APIs:

[[Verify APIs For Front-end]]

[[Verify APIs For Gobus]]
----------------------------------------------------
OAuth APIs:

[[oauth_signin]]

[[follow_exfe]]
----------------------------------------------------

h2. object

[[object_user|user]]
[[object_identity|identity]]
[[object_cross_time|cross_time]]
[[object_place|place]]
[[object_exfee|exfee]]

[[object_cross|cross]] -> [[object_meta_info|meta_info]]
[[object_post|post]] -> [[object_meta_info|meta_info]]
[[object_meta_info|meta_info]]