## ChangeIdentity

<pre>
endpoint: api.local.exfe.com/v2/exfee/[exfee_id]/changeIdentity

GET:
    token [str]

POST:
    identity_id [int]

Demo:
http -f post api.local.exfe.com/v2/exfee/110192/ChangeIdentity?token=aed684b1d8559a36cecf166cb36633012dfb306af050b24bc66c1c5bc6aa5be5 identity_id=356
</pre>

<pre>
return:

{
    meta : 200,
    response :
    {
        exfee: [object]
    }
}
</pre>
