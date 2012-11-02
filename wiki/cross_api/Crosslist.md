h1. Crosslist

<pre>
method: get

endpoint: api.local.exfe.com/v2/users/[user_id]/crosslist
args: token
upcoming_folded = true / false
sometime_folded = true / false
sevendays_folded = true / false
later_folded = true / false
past_folded = true / false
more_category = sometime / sevendays / later / past
more_position = int


returns: crosses



example: 
http get api.local.exfe.com/v2/users/143/crosslist?token=sadfsadfsdafsdf

</pre>