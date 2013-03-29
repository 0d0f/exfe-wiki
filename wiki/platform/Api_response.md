h1. Api overview

这个结构可以用4sq的，我稍微改了一点点复制一份在这里。原来在 https://developer.foursquare.com/overview/responses

   {
          "meta": {
            "code": 200,
             ...errorType and errorDetail...
          },
          "response": {
             ...results...
          }
   }

Additional details are provided in the errorType. It should be one of the following.

|400 (Bad Request)	|Any case where a parameter is invalid, or a required parameter is missing. This includes the case where no OAuth token is provided and the case where a resource ID is specified incorrectly in a path.|
|401 (Unauthorized)	|The OAuth token was provided but was invalid.|
|403 (Forbidden)	|The requested information cannot be viewed by the acting user, for example, because they are not friends with the user whose data they are trying to read.|
|404 (Not Found)	|Endpoint does not exist.|
|405 (Method Not Allowed)	|Attempting to use POST with a GET-only endpoint, or vice-versa.|
|409 (Conflict)	|The request could not be completed as it is. Use the information included in the response to modify the request and retry.|
|500 (Internal Server Error)	|Foursquare’s servers are unhappy. The request is probably valid but needs to be retried later.|

Errors will usually include an errorDetail field with additional information about what went wrong, intended for the developer. In some cases, the server may include an errorMessage, which is a localized string intended for the client to display back to the user directly.


|invalid_auth	|OAuth token was not provided or was invalid.|
|param_error	|A required parameter was missing or a parameter was malformed. This is also used if the resource ID in the path is incorrect.|
|endpoint_error	|The requested path does not exist.|
|not_authorized	|Although authentication succeeded, the acting user is not allowed to see this information due to privacy restrictions.|
|rate_limit_exceeded	Rate |limit for this hour exceeded.|
|deprecated	|Something about this request is using deprecated functionality, or the response format may be about to change.|
|server_error	|Server is currently experiencing issues. Check status.foursquare.com for updates.|
|other	|Some other type of error occurred.|