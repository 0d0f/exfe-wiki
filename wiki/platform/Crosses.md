# Crosses
    author: Leask Huang
    created date: 2013-06-06
    updated date: 2013-06-06


## Check Invitation Token
* endpoint: /v2/crosses/checkinvitationtoken
* POST args:
    - invitation_token: [str:length = 32]
* returns:
    - 200: valid: [bol]
    - 400: no_token
